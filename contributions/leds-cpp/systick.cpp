#include "systick.hpp"

using namespace std;

SystemTick::SystemTick(uint32_t delay)
{
    m_delay = delay;
    m_ticks = 0;
    m_start_mtime = 0;
    m_delta_mtime = 0;
    m_tmp = 0;
}

void SystemTick::Handler()
{
    m_ticks++;
}

void SystemTick::Delay()
{
    m_tmp = get_timer_val(); 

    // wait a mtime tick
    do
    {
        m_start_mtime = get_timer_val();
    }
    while (m_start_mtime == m_tmp);

    // start measuring
    do
    {
        m_delta_mtime = get_timer_val() - m_start_mtime;
    }
    while (m_delta_mtime < (SystemCoreClock/4000.0 * m_delay));   
}

uint64_t SystemTick::get_timer_val()
{
    while (1) 
    {
        uint32_t hi = __read_csr(_CSR_CYCLEH);
        uint32_t lo = __read_csr(_CSR_CYCLE);
        if (hi == __read_csr(_CSR_CYCLEH))
        {
            return ((uint64_t)hi << 32) | lo;
        }
    }
}