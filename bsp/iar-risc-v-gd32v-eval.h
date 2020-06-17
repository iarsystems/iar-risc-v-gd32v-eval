/*!
    \file    iar-risc-v-gd32v-eval.h
    \brief   definitions for IAR RISC-V GD32V Eval board hardware resources

    \version 2020-06-16, V1.0.0
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
	LED5 = 4
} led_typedef_enum;

typedef enum 
{
    KEY_A = 0,
    KEY_B = 1,
    KEY_C = 2,
    KEY_D = 3,
    KEY_E = 4,
    KEY_CET = 5
} key_typedef_enum;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} keymode_typedef_enum;

/* IAR eval board LEDs */
#define LEDn                             5U

#define LED1_PIN                         GPIO_PIN_9
#define LED1_GPIO_PORT                   GPIOA
#define LED1_GPIO_CLK                    RCU_GPIOA

#define LED2_PIN                         GPIO_PIN_7
#define LED2_GPIO_PORT                   GPIOC
#define LED2_GPIO_CLK                    RCU_GPIOC
  
#define LED3_PIN                         GPIO_PIN_6
#define LED3_GPIO_PORT                   GPIOB
#define LED3_GPIO_CLK                    RCU_GPIOB
  
#define LED4_PIN                         GPIO_PIN_11
#define LED4_GPIO_PORT                   GPIOB
#define LED4_GPIO_CLK                    RCU_GPIOB

#define LED5_PIN                         GPIO_PIN_10
#define LED5_GPIO_PORT                   GPIOB
#define LED5_GPIO_CLK                    RCU_GPIOB

/* IAR eval board RGB LED */
#define LEDR_PIN                         GPIO_PIN_11
#define LEDR_GPIO_PORT                   GPIOA
#define LEDR_GPIO_CLK                    RCU_GPIOA

#define LEDG_PIN                         GPIO_PIN_10
#define LEDG_GPIO_PORT                   GPIOB
#define LEDG_GPIO_CLK                    RCU_GPIOB

#define LEDB_PIN                         GPIO_PIN_11
#define LEDB_GPIO_PORT                   GPIOB
#define LEDB_GPIO_CLK                    RCU_GPIOB

/* IAR eval board USART */
#define COMn                             2U

#define EVAL_COM0                        USART0
#define EVAL_COM0_CLK                    RCU_USART0
#define EVAL_COM0_TX_PIN                 GPIO_PIN_9
#define EVAL_COM0_RX_PIN                 GPIO_PIN_10
#define EVAL_COM0_GPIO_PORT              GPIOA
#define EVAL_COM0_GPIO_CLK               RCU_GPIOA

#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCU_USART1
#define EVAL_COM1_TX_PIN                 GPIO_PIN_2
#define EVAL_COM1_RX_PIN                 GPIO_PIN_3
#define EVAL_COM1_GPIO_PORT              GPIOA
#define EVAL_COM1_GPIO_CLK               RCU_GPIOA

/* IAR eval board KEYs */
#define KEYn                             5U

/* S1 */
#define KEY_A_PIN                        GPIO_PIN_10
#define KEY_A_GPIO_PORT                  GPIOA
#define KEY_A_GPIO_CLK                   RCU_GPIOA
#define KEY_A_EXTI_LINE                  EXTI_11
#define KEY_A_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOA
#define KEY_A_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_10
#define KEY_A_EXTI_IRQn                  EXTI10_15_IRQn

/* S2 */
#define KEY_B_PIN                        GPIO_PIN_5
#define KEY_B_GPIO_PORT                  GPIOB
#define KEY_B_GPIO_CLK                   RCU_GPIOB
#define KEY_B_EXTI_LINE                  EXTI_12
#define KEY_B_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOB
#define KEY_B_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_5
#define KEY_B_EXTI_IRQn                  EXTI10_15_IRQn

/* S3 */
#define KEY_C_PIN                        GPIO_PIN_8
#define KEY_C_GPIO_PORT                  GPIOA
#define KEY_C_GPIO_CLK                   RCU_GPIOA
#define KEY_C_EXTI_LINE                  EXTI_13
#define KEY_C_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOA
#define KEY_C_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_8
#define KEY_C_EXTI_IRQn                  EXTI10_15_IRQn

/* S4 */
#define KEY_D_PIN                        GPIO_PIN_11
#define KEY_D_GPIO_PORT                  GPIOA
#define KEY_D_GPIO_CLK                   RCU_GPIOA
#define KEY_D_EXTI_LINE                  EXTI_14
#define KEY_D_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOA
#define KEY_D_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_11
#define KEY_D_EXTI_IRQn                  EXTI10_15_IRQn

/* S5 */
#define KEY_E_PIN                        GPIO_PIN_11
#define KEY_E_GPIO_PORT                  GPIOB
#define KEY_E_GPIO_CLK                   RCU_GPIOB
#define KEY_E_EXTI_LINE                  EXTI_15
#define KEY_E_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOB
#define KEY_E_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_11
#define KEY_E_EXTI_IRQn                  EXTI10_15_IRQn

#define KEY_CET_PIN                      GPIO_PIN_4
#define KEY_CET_GPIO_PORT                GPIOC
#define KEY_CET_GPIO_CLK                 RCU_GPIOC
#define KEY_CET_EXTI_LINE                EXTI_15
#define KEY_CET_EXTI_PORT_SOURCE         GPIO_PORT_SOURCE_GPIOC
#define KEY_CET_EXTI_PIN_SOURCE          GPIO_PIN_SOURCE_4
#define KEY_CET_EXTI_IRQn                EXTI10_15_IRQn

/* function declarations */
/* configure led GPIO */
void gd_eval_led_init(led_typedef_enum lednum);
/* turn on selected led */
void gd_eval_led_on(led_typedef_enum lednum);
/* turn off selected led */
void gd_eval_led_off(led_typedef_enum lednum);
/* toggle the selected led */
void gd_eval_led_toggle(led_typedef_enum lednum);
/* configure key */
void gd_eval_key_init(key_typedef_enum key_num, keymode_typedef_enum key_mode);
/* return the selected key state */
uint8_t gd_eval_key_state_get(key_typedef_enum key);
/* configure COM port */
void gd_eval_com_init(uint32_t com);

#ifdef cplusplus
}
#endif

#endif /* __IAR_RISCV_GD32V_EVAL_H */
