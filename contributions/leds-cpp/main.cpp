/*!
    \file  main.c
    \brief C++ template for starting new projects

    \version 20201209
*/
#include "led.hpp"
#include "systick.hpp"
#include <vector>

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void main(void)
{
    SystemInit();

    SystemTick tick(250);
    
    Led led1(LED1);
    Led led2(LED2);
    Led led3(LED3);
    
    std::vector<Led *> vL;
    vL.push_back(&led1);
    vL.push_back(&led2);
    vL.push_back(&led3);
    
    while(1)
    {
      for (auto i : vL)
      { 
          i->Blink();
          i->Log();
      }
        tick.Delay();
    }
}
