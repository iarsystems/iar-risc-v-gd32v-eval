/*!
    \file    iar-risc-v-gd32v-eval.h
    \brief   definitions for IAR RISC-V GD32V Eval board hardware resources

    \version 20200803
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#ifndef __IAR_RISCV_GD32V_EVAL_H
#define __IAR_RISCV_GD32V_EVAL_H

#ifdef cplusplus
 extern "C" {
#endif

#include "gd32vf103.h"
     
/* exported types */
typedef enum 
{
    LED1 = 0,
    LED2 = 1,
    LED3 = 2,
    LED4 = 3,
    LED5 = 4,
    LEDR = 5,
    LEDG = 6,
    LEDB = 7,
} led_t;

typedef enum 
{
    S1 = 0,
    S2 = 1,
    S3 = 2,
    S4 = 3,
    S5 = 4,
} sw_t;

typedef enum 
{
    SW_MODE_GPIO = 0,
    SW_MODE_EXTI = 1,
} sw_mode_t;

typedef enum 
{
    SW_PRESSED = 0,
    SW_RELEASE = 1,
} sw_status_t;

typedef enum
{
    EVAL_COM0 = USART0,
    EVAL_COM1 = USART1,
} com_t;

/* IAR eval board LEDs */
#define LEDn                                  (8U)
                                            
#define LED1_PIN                              GPIO_PIN_9
#define LED1_GPIO_PORT                        GPIOA
#define LED1_GPIO_CLK                         RCU_GPIOA
                                            
#define LED2_PIN                              GPIO_PIN_7
#define LED2_GPIO_PORT                        GPIOC
#define LED2_GPIO_CLK                         RCU_GPIOC
                                            
#define LED3_PIN                              GPIO_PIN_6
#define LED3_GPIO_PORT                        GPIOB
#define LED3_GPIO_CLK                         RCU_GPIOB
                                            
#define LED4_PIN                              GPIO_PIN_11
#define LED4_GPIO_PORT                        GPIOB
#define LED4_GPIO_CLK                         RCU_GPIOB
                                            
#define LED5_PIN                              GPIO_PIN_10
#define LED5_GPIO_PORT                        GPIOB
#define LED5_GPIO_CLK                         RCU_GPIOB
                                      
/* IAR eval board RGB LED */         
#define LEDR_PIN                              GPIO_PIN_11
#define LEDR_GPIO_PORT                        GPIOA
#define LEDR_GPIO_CLK                         RCU_GPIOA
                                          
#define LEDG_PIN                              GPIO_PIN_10
#define LEDG_GPIO_PORT                        GPIOB
#define LEDG_GPIO_CLK                         RCU_GPIOB
                                          
#define LEDB_PIN                              GPIO_PIN_11
#define LEDB_GPIO_PORT                        GPIOB
#define LEDB_GPIO_CLK                         RCU_GPIOB
                                          
/* IAR eval board USARTs */               
#define COMn                                  (2U)
                                          
#define EVAL_COM0_CLK                         RCU_USART0
#define EVAL_COM0_TX_PIN                      GPIO_PIN_9
#define EVAL_COM0_RX_PIN                      GPIO_PIN_10
#define EVAL_COM0_GPIO_PORT                   GPIOA
#define EVAL_COM0_GPIO_CLK                    RCU_GPIOA
                                      
#define EVAL_COM1_CLK                         RCU_USART1
#define EVAL_COM1_TX_PIN                      GPIO_PIN_2
#define EVAL_COM1_RX_PIN                      GPIO_PIN_3
#define EVAL_COM1_GPIO_PORT                   GPIOA
#define EVAL_COM1_GPIO_CLK                    RCU_GPIOA
                                            
/* IAR eval board KEYs */                   
#define Sn                                    (5U)
                                            
/* S1 */                                    
#define S1_PIN                                GPIO_PIN_10
#define S1_GPIO_PORT                          GPIOA
#define S1_GPIO_CLK                           RCU_GPIOA
#define S1_EXTI_LINE                          EXTI_10
#define S1_EXTI_PORT_SOURCE                   GPIO_PORT_SOURCE_GPIOA
#define S1_EXTI_PIN_SOURCE                    GPIO_PIN_SOURCE_10
#define S1_EXTI_IRQn                          EXTI10_15_IRQn
                                      
/* S2 */                              
#define S2_PIN                                GPIO_PIN_5
#define S2_GPIO_PORT                          GPIOB
#define S2_GPIO_CLK                           RCU_GPIOB
#define S2_EXTI_LINE                          EXTI_5
#define S2_EXTI_PORT_SOURCE                   GPIO_PORT_SOURCE_GPIOB
#define S2_EXTI_PIN_SOURCE                    GPIO_PIN_SOURCE_5
#define S2_EXTI_IRQn                          EXTI5_9_IRQn
                                           
/* S3 */                                   
#define S3_PIN                                GPIO_PIN_8
#define S3_GPIO_PORT                          GPIOA
#define S3_GPIO_CLK                           RCU_GPIOA
#define S3_EXTI_LINE                          EXTI_8
#define S3_EXTI_PORT_SOURCE                   GPIO_PORT_SOURCE_GPIOA
#define S3_EXTI_PIN_SOURCE                    GPIO_PIN_SOURCE_8
#define S3_EXTI_IRQn                          EXTI5_9_IRQn
                                      
/* S4 */                              
#define S4_PIN                                GPIO_PIN_11
#define S4_GPIO_PORT                          GPIOA
#define S4_GPIO_CLK                           RCU_GPIOA
#define S4_EXTI_LINE                          EXTI_11
#define S4_EXTI_PORT_SOURCE                   GPIO_PORT_SOURCE_GPIOA
#define S4_EXTI_PIN_SOURCE                    GPIO_PIN_SOURCE_11
#define S4_EXTI_IRQn                          EXTI10_15_IRQn
                                             
/* S5 */                                     
#define S5_PIN                                GPIO_PIN_11
#define S5_GPIO_PORT                          GPIOB
#define S5_GPIO_CLK                           RCU_GPIOB
#define S5_EXTI_LINE                          EXTI_11
#define S5_EXTI_PORT_SOURCE                   GPIO_PORT_SOURCE_GPIOB
#define S5_EXTI_PIN_SOURCE                    GPIO_PIN_SOURCE_11
#define S5_EXTI_IRQn                          EXTI10_15_IRQn

/* function declarations */

/* configure LED GPIO */
void gd_eval_led_init(led_t);
/* turn on selected LED */
void gd_eval_led_on(led_t);
/* turn off selected LED */
void gd_eval_led_off(led_t);
/* toggle the selected LED */
void gd_eval_led_toggle(led_t);
/* configure switch */
void gd_eval_sw_init(sw_t, sw_mode_t);
/* return the selected switch state */
sw_status_t gd_eval_sw_state_get(sw_t);
/* configure COM port */
void gd_eval_com_init(com_t);
/* transmit data to the COM port */
void gd_eval_usart_data_transmit(com_t, uint8_t *);

#ifdef cplusplus
}
#endif

#endif /* __IAR_RISCV_GD32V_EVAL_H */
