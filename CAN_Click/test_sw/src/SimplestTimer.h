#pragma once

#include <Arduino.h>

class SimplestTimer
{
public:
    SimplestTimer(const uint32_t interval = 0);
    virtual ~SimplestTimer();

    void SetInterval(const uint32_t interval, const bool autoRestart = true);
    void Reset();
    bool Expired() const;

private:
    uint32_t    _interval           {0};
    uint32_t    _previousMillis     {0};
};
