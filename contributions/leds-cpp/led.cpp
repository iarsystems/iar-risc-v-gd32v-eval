#ifndef NDEBUG
#include <iostream>
#endif
#include "led.hpp"

Led::Led(led_t led)
{
    m_led = led;
    
    gd_eval_led_init(m_led);
    
    m_state = false;
}

void Led::Blink()
{
    gd_eval_led_toggle(m_led);
    Led::setState(!this->m_state);
}

int Led::getLed()
{
    return m_led + 1; 
}
    
void Led::setState(bool x)
{
    m_state = x;
}

bool Led::getState()
{
    return m_state;
}

void Led::On()
{
    gd_eval_led_on(m_led);
    Led::setState(true);
}

void Led::Off()
{
    gd_eval_led_off(m_led);
    Led::setState(false);
}

void Led::Log()
{
#ifndef NDEBUG
    std::cout << "LED" << getLed() << ":" << getState() << std::endl;
#endif
}

