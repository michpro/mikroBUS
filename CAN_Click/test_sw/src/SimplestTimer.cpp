#include "SimplestTimer.h"

/**
 *  \brief SimplestTimer class constructor.
 * 
 *  \param interval Timer interval [ms] [default 0].
**/
SimplestTimer::SimplestTimer(const uint32_t interval) :
  _interval(interval)
{
    _previousMillis = millis();
}

/**
 *  \brief SimplestTimer class destructor.
**/
SimplestTimer::~SimplestTimer()
{}

/**
 *  \brief Method to set a new timer interval.
 *  \param interval New timer interval [ms].
 *  \param autoRestart Variable that restarts the timer [default 'true'].
**/
void SimplestTimer::SetInterval(const uint32_t interval, const bool autoRestart)
{
    _interval = interval;
    if (autoRestart)
    {
       Reset();
    }
}

/**
 *  \brief Resets the timer and starts counting again.
**/
void SimplestTimer::Reset()
{
    _previousMillis = millis();
}

/**
 *  \brief Checks if the timer has expired.
 *  \return "true" if the timer has already expired, otherwise "false".
**/
bool SimplestTimer::Expired() const
{
    uint32_t    currentMillis  {millis()};

    return (currentMillis - _previousMillis >= _interval);
}
