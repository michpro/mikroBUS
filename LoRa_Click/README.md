# **LoRa Click**

- [**LoRa Click**](#lora-click)
  - [**Overview**](#overview)
    - [**Features**](#features)
    - [**Transceivers:**](#transceivers)
  - [**Software**](#software)
  - [**Schematic diagram**](#schematic-diagram)
  - [**Module visualisation**](#module-visualisation)
  - [**Assembly**](#assembly)
  - [**Production files**](#production-files)
  - [**Reporting bugs**](#reporting-bugs)
  - [**License**](#license)
  - [**Support**](#support)

---

## **Overview**
The LoRa Click board is a compact add-on board designed to provide LoRa wireless communication capabilities. Built around the SX1262/SX1268 LoRa transceiver module from Semtech, it supports long-range, low-power wireless communication. The board interfaces with a host microcontroller via the MikroBUS™ standard, ensuring compatibility with a wide range of development platforms.

### **Features**
* **LoRa Transceiver**: Utilizes the SX1262 or SX1268 for reliable long-range communication.
* **Digital Isolation**: Incorporates the CA-IS3763HB digital isolator for safe and noise-immune SPI communication.
* **Antenna Connection**: Features an SMA connector for attaching an external antenna.
* **GPIO Access**: Provides access to additional pins like DIO1 and DIO3 for extended functionality.
* **Power Indicators**: Includes LEDs for visual power status indication.

### **Transceivers:**
* **SX1262**: [RA-01SH](./docs/ra-01sh_specification.pdf) from Ai-Thinker - frequency range: 803-930MHz
* **SX1268**: [RA-01S](./docs/ra-01s_specification.pdf) from Ai-Thinker - frequency range: 410-525MHz

---

## **Software**
Suggested library for Arduino: [https://github.com/nopnop2002/Arduino-LoRa-Ra01S](https://github.com/nopnop2002/Arduino-LoRa-Ra01S)

---

## **Schematic diagram**
<p align="center"><img src="./docs/schematic.png" alt="wiring diagram" width="80%"/></p>


## **Module visualisation**
(click on the image to see the 3D model)
<p align="center"><a href="https://3dviewer.net/#model=https://github.com/michpro/mikroBUS/blob/master/LoRa_Click/docs/LoRa_Click.wrl"><img src="./docs/LoRa_Click.png" alt="LoRa Click" width="50%"/></a></p>

## **Assembly**
[Interactive BOM and placement](https://michpro.github.io/mikroBUS/LoRa_Click/docs/ibom.html)

## **Production files**
Production files can be found [**here**](./production/).

---

## **Reporting bugs**

[Create an issue on GitHub](https://github.com/michpro/mikroBUS/issues)

---

## **License**
Copyright © 2025 Michal Protasowicki

This project is released under CERN Open Hardware Licence Version 2 - Permissive.

[![License: CERN-OHL-P-2.0](https://img.shields.io/badge/License-CERN--OHL--P--2.0-blue.svg)](../LICENSE)

---

## **Support**
If You find my projects interesting and You wanted to support my work, You can give me a cup of coffee or a keg of beer :)

[![PayPal Direct](https://badgen.net/badge/icon/Support%20me%20by%20PayPal?icon=kofi&label&scale=1.5&color=blue)](https://www.paypal.me/michpro)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[![ko-fi](https://badgen.net/badge/icon/Support%20me%20on%20Ko-fi?icon=kofi&label&scale=1.5&color=red)](https://ko-fi.com/F1F24CEW1)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[![Coinbase](https://badgen.net/badge/icon/Support%20me%20with%20cryptocurrencies?icon=kofi&label&scale=1.5&color=blue)](https://commerce.coinbase.com/checkout/ec299320-cbed-475d-976e-fdf37c1ac3d0)
