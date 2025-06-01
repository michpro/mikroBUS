/**
 * \file    test_sw.ino
 * \brief   This Arduino UNO code implements bidirectional CAN bus communication using an MCP2515 module.
 *          It periodically transmits a 3-byte counter message (incremented each send) with an extended ID (0x0BB0DEEF) at 1000kbps,
 *          while simultaneously monitoring for incoming CAN messages.
 *          Received messages are displayed on the serial monitor along with their IDs and data.
 *          The code supports MikroBUS hardware configuration with pin mappings for slot 1 or 2,
 *          handles CAN initialization, and includes standby control for the CAN transceiver.
 *          Both transmission (every 2500ms) and reception are logged to the serial port with formatted hexadecimal output.
 *
 * \copyright SPDX-FileCopyrightText: Copyright 2025 Michal Protasowicki
 *
 * \license SPDX-License-Identifier: MIT
 *
 */

#if !defined(ARDUINO_ARCH_AVR)
    #error "Use only with Arduino AVR family!!!"
#endif

#include <SPI.h>
#include "src/mcp2515_can.h"
#include "src/SimplestTimer.h"

#define MIKROBUS_SLOT                                   1

#if defined (MIKROBUS_SLOT) && (MIKROBUS_SLOT == 1)
const int SPI_CS_PIN                                    {10};
const int CAN_INT_PIN                                   {3};
const int CAN_STANDBY_PIN                               {6};
#else
const int SPI_CS_PIN                                    {7};
const int CAN_INT_PIN                                   {2};
const int CAN_STANDBY_PIN                               {5};
#endif

const uint32_t          CAN_MSG_SEND_PERIOD             {2500};
const uint8_t           CAN_MAX_MSG_LENGTH              {8};
const uint8_t           CAN_EXTENDED_ID                 {1};
const uint8_t           CAN_STANDARD_FRAME              {0};
const MCP_BITTIME_SETUP CAN_SPEED                       {CAN_1000KBPS};

const uint32_t          msgId                           {0x0BB0DEEF};
const uint8_t           msgLength                       {3};
uint32_t                txCounter                       {0};
uint8_t                 msgBuffer[CAN_MAX_MSG_LENGTH]   {0};
char                    printBuffer[20];

mcp2515_can             CAN(SPI_CS_PIN);
SimplestTimer           timerCan(CAN_MSG_SEND_PERIOD);


void printData(const uint8_t *buffer, const uint8_t length)
{
    SERIAL_PORT_MONITOR.print(F("data: "));
    for (uint8_t idx = 0; idx < length; idx++)
    {
        SERIAL_PORT_MONITOR.print((buffer[idx] < 0x10) ? F("0x0") : F("0x"));
        SERIAL_PORT_MONITOR.print(buffer[idx], HEX);
        SERIAL_PORT_MONITOR.print(F(" "));
    }
    SERIAL_PORT_MONITOR.println();
}

void setup()
{
    SERIAL_PORT_MONITOR.begin(115200);
    while (!SERIAL_PORT_MONITOR) {}

    while (CAN_OK != CAN.begin(CAN_SPEED, MCP_12MHz))
    {
        SERIAL_PORT_MONITOR.println(F("CAN init fail, retry..."));
        delay(1000);
    }
    SERIAL_PORT_MONITOR.println(F("CAN init OK!"));

    pinMode(CAN_STANDBY_PIN, OUTPUT);
    digitalWrite(CAN_STANDBY_PIN, LOW);
}

void loop()
{
    if (CAN_MSGAVAIL == CAN.checkReceive())
    {
        uint8_t rxMsgLength {0};
        uint8_t rxMsgBuffer[CAN_MAX_MSG_LENGTH];

        CAN.readMsgBuf(&rxMsgLength, rxMsgBuffer);

        uint32_t canId      {CAN.getCanId()};

        sprintf(printBuffer, "RX ID: 0x%08lX  ", canId);
        SERIAL_PORT_MONITOR.print(printBuffer);

        if (rxMsgLength > 0)
        {
            printData(rxMsgBuffer, rxMsgLength);
        } else
        {
            SERIAL_PORT_MONITOR.println();
        }
    }

    if (true == timerCan.Expired())
    {
        msgBuffer[2] = (uint8_t)((txCounter >>  0) & 0xFF);
        msgBuffer[1] = (uint8_t)((txCounter >>  8) & 0xFF);
        msgBuffer[0] = (uint8_t)((txCounter >> 16) & 0xFF);

        if (CAN_OK == CAN.trySendMsgBuf(msgId, CAN_EXTENDED_ID, CAN_STANDARD_FRAME, msgLength, msgBuffer))
        {
            sprintf(printBuffer, "TX ID: 0x%08lX  ", msgId);
            SERIAL_PORT_MONITOR.print(printBuffer);
            printData(msgBuffer, msgLength);

            timerCan.Reset();
            txCounter++;
        }
    }
}
