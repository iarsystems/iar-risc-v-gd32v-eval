#pragma once

#include <cstdint>
#include <intrinsics.h>

#include "gd32vf103.h"
#include "n200_func.h"

class SystemTick
{
public:
    SystemTick(uint32_t ms = 100);
    void Handler();
    void Delay();
private:    
    uint32_t m_delay;
    volatile uint32_t m_ticks;
    uint64_t m_start_mtime;
    uint64_t m_delta_mtime;
    uint64_t m_tmp;
    
    uint64_t get_timer_val();
};
