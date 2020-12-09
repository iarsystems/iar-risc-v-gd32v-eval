#pragma once

#include "iar-risc-v-gd32v-eval.h"

class Led
{
public:
    Led(led_t led = LED1);
    void Blink();
    int getLed();
    void setState(bool x);
    bool getState();
    void On();
    void Off();
    void Log();
    
private:
    led_t m_led;
    bool m_state;
};
