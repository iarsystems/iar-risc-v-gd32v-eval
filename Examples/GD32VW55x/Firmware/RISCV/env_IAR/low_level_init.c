/*
    Copyright (c) 2024, GigaDevice Semiconductor Inc.
*/

/* This file refers the RISC-V standard, some adjustments are made according to GigaDevice chips */

#include "Nuclei/ionuclei.h"
#include "intrinsics.h"
#include "csr.h"
#include "stdlib.h"
#include "stdint.h"
#include "gd32vw55x.h"

#pragma language=extended

extern __weak void   eclic_msip_handler(void);
extern __weak void   eclic_mtip_handler(void);
extern __weak void   WWDGT_IRQHandler(void);
extern __weak void   LVD_IRQHandler(void);
extern __weak void   TAMPER_STAMP_IRQHandler(void);
extern __weak void   RTC_WKUP_IRQHandler(void);
extern __weak void   FMC_IRQHandler(void);
extern __weak void   RCU_IRQHandler(void);
extern __weak void   EXTI0_IRQHandler(void);
extern __weak void   EXTI1_IRQHandler(void);
extern __weak void   EXTI2_IRQHandler(void);
extern __weak void   EXTI3_IRQHandler(void);
extern __weak void   EXTI4_IRQHandler(void);
extern __weak void   DMA_Channel0_IRQHandler(void);
extern __weak void   DMA_Channel1_IRQHandler(void);
extern __weak void   DMA_Channel2_IRQHandler(void);
extern __weak void   DMA_Channel3_IRQHandler(void);
extern __weak void   DMA_Channel4_IRQHandler(void);
extern __weak void   DMA_Channel5_IRQHandler(void);
extern __weak void   DMA_Channel6_IRQHandler(void);
extern __weak void   DMA_Channel7_IRQHandler(void);
extern __weak void   ADC_IRQHandler(void);
extern __weak void   EXTI5_9_IRQHandler(void);
extern __weak void   TIMER0_BRK_IRQHandler(void);
extern __weak void   TIMER0_UP_IRQHandler(void);
extern __weak void   TIMER0_CMT_IRQHandler(void);
extern __weak void   TIMER0_Channel_IRQHandler(void);
extern __weak void   TIMER1_IRQHandler(void);
extern __weak void   TIMER2_IRQHandler(void);
extern __weak void   I2C0_EV_IRQHandler(void);
extern __weak void   I2C0_ER_IRQHandler(void);
extern __weak void   I2C1_EV_IRQHandler(void);
extern __weak void   I2C1_ER_IRQHandler(void);
extern __weak void   SPI_IRQHandler(void);
extern __weak void   USART0_IRQHandler(void);
extern __weak void   UART1_IRQHandler(void);
extern __weak void   UART2_IRQHandler(void);
extern __weak void   EXTI10_15_IRQHandler(void);
extern __weak void   RTC_Alarm_IRQHandler(void);
extern __weak void   TIMER15_IRQHandler(void);
extern __weak void   TIMER16_IRQHandler(void);
extern __weak void   I2C0_WKUP_IRQHandler(void);
extern __weak void   USART0_WKUP_IRQHandler(void);
extern __weak void   TIMER5_IRQHandler(void);
extern __weak void   WIFI_TRIGGER_IRQHandler(void);
extern __weak void   WIFI_MAC_IRQHandler(void);
extern __weak void   WIFI_TX_IRQHandler(void);
extern __weak void   WIFI_RX_IRQHandler(void);
extern __weak void   LA_IRQHandler(void);
extern __weak void   WIFI_WKUP_IRQHandler(void);
extern __weak void   BLE_WKUP_IRQHandler(void);
extern __weak void   PLATFORM_WAKE_IRQHandler(void);
extern __weak void   ISO_BT_STAMP0_IRQHandler(void);
extern __weak void   ISO_BT_STAMP1_IRQHandler(void);
extern __weak void   ISO_BT_STAMP2_IRQHandler(void);
extern __weak void   ISO_BT_STAMP3_IRQHandler(void);
extern __weak void   ISO_BT_STAMP4_IRQHandler(void);
extern __weak void   ISO_BT_STAMP5_IRQHandler(void);
extern __weak void   ISO_BT_STAMP6_IRQHandler(void);
extern __weak void   ISO_BT_STAMP7_IRQHandler(void);
extern __weak void   PMU_IRQHandler(void);
extern __weak void   CAU_IRQHandler(void);
extern __weak void   HAU_TRNG_IRQHandler(void);
extern __weak void   WIFI_INT_IRQHandler(void);
extern __weak void   WIFI_SW_TRIG_IRQHandler(void);
extern __weak void   WIFI_FINE_TIMER_TARGET_IRQHandler(void);
extern __weak void   WIFI_STAMP_TARGET1_IRQHandler(void);
extern __weak void   WIFI_STAMP_TARGET2_IRQHandler(void);
extern __weak void   WIFI_STAMP_TARGET3_IRQHandler(void);
extern __weak void   WIFI_ENCRYPTION_ENGINE_IRQHandler(void);
extern __weak void   WIFI_SLEEP_MODE_IRQHandler(void);
extern __weak void   WIFI_HALF_SLOT_IRQHandler(void);
extern __weak void   WIFI_FIFO_ACTIVITY_IRQHandler(void);
extern __weak void   WIFI_ERROR_IRQHandler(void);
extern __weak void   WIFI_FREQ_SELECT_IRQHandler(void);
extern __weak void   EFUSE_IRQHandler(void);
extern __weak void   QSPI_IRQHandler(void);
extern __weak void   PKCAU_IRQHandler(void);

typedef void(*__fp)(void);
const __fp gd_vector_base[116] =
{
    0,
    0,
    0,
    eclic_msip_handler,
    0,
    0,
    0,
    eclic_mtip_handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    WWDGT_IRQHandler,
    LVD_IRQHandler,
    TAMPER_STAMP_IRQHandler,
    RTC_WKUP_IRQHandler,
    FMC_IRQHandler,
    RCU_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA_Channel0_IRQHandler,
    DMA_Channel1_IRQHandler,
    DMA_Channel2_IRQHandler,
    DMA_Channel3_IRQHandler,
    DMA_Channel4_IRQHandler,
    DMA_Channel5_IRQHandler,
    DMA_Channel6_IRQHandler,
    DMA_Channel7_IRQHandler,
    ADC_IRQHandler,
    0,
    0,
    0,
    EXTI5_9_IRQHandler,
    TIMER0_BRK_IRQHandler,
    TIMER0_UP_IRQHandler,
    TIMER0_CMT_IRQHandler,
    TIMER0_Channel_IRQHandler,
    TIMER1_IRQHandler,
    TIMER2_IRQHandler,
    0,
    I2C0_EV_IRQHandler,
    I2C0_ER_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    SPI_IRQHandler,
    0,
    USART0_IRQHandler,
    UART1_IRQHandler,
    UART2_IRQHandler,
    EXTI10_15_IRQHandler,
    RTC_Alarm_IRQHandler,
    0,
    0,
    TIMER15_IRQHandler,
    TIMER16_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    I2C0_WKUP_IRQHandler,
    USART0_WKUP_IRQHandler,
    0,
    TIMER5_IRQHandler,
    WIFI_TRIGGER_IRQHandler,
    WIFI_MAC_IRQHandler,
    WIFI_TX_IRQHandler,
    WIFI_RX_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    LA_IRQHandler,
    WIFI_WKUP_IRQHandler,
    BLE_WKUP_IRQHandler,
    PLATFORM_WAKE_IRQHandler,
    ISO_BT_STAMP0_IRQHandler,
    ISO_BT_STAMP1_IRQHandler,
    ISO_BT_STAMP2_IRQHandler,
    ISO_BT_STAMP3_IRQHandler,
    ISO_BT_STAMP4_IRQHandler,
    ISO_BT_STAMP5_IRQHandler,
    ISO_BT_STAMP6_IRQHandler,
    ISO_BT_STAMP7_IRQHandler,
    PMU_IRQHandler,
    0,
    0,
    CAU_IRQHandler,
    HAU_TRNG_IRQHandler,
    0,
    WIFI_INT_IRQHandler,
    WIFI_SW_TRIG_IRQHandler,
    WIFI_FINE_TIMER_TARGET_IRQHandler,
    WIFI_STAMP_TARGET1_IRQHandler,
    WIFI_STAMP_TARGET2_IRQHandler,
    WIFI_STAMP_TARGET3_IRQHandler,
    WIFI_ENCRYPTION_ENGINE_IRQHandler,
    WIFI_SLEEP_MODE_IRQHandler,
    WIFI_HALF_SLOT_IRQHandler,
    WIFI_FIFO_ACTIVITY_IRQHandler,
    WIFI_ERROR_IRQHandler,
    WIFI_FREQ_SELECT_IRQHandler,
    EFUSE_IRQHandler,
    QSPI_IRQHandler,
    PKCAU_IRQHandler
};

extern unsigned int __minterrupt_clic_base;
extern __interrupt __machine void __minterrupt_single(void);

__interrupt __machine void __default_minterrupt_handler(void);

__interrupt __machine void __default_minterrupt_handler(void)
{
  abort();
}

extern uintptr_t handle_trap(uintptr_t mcause, uintptr_t sp);

uintptr_t handle_trap(uintptr_t mcause, uintptr_t sp)
{
  __fp fp;
  mcause &= 0xFFF;
  fp = gd_vector_base[mcause];
  if (fp)
    fp();
  return 0;
}

__interrupt void trap_entry()
{
  uintptr_t mcause = __read_csr(_CSR_MCAUSE);
  handle_trap(mcause, 0);
}

__interrupt void irq_entry()
{
  uintptr_t mcause = __read_csr(_CSR_MCAUSE);
  uintptr_t mepc = __read_csr(_CSR_MEPC);
  uintptr_t msubm = __read_csr(0x7C4);
  __enable_interrupt();
  handle_trap(mcause, 0);

  __disable_interrupt();
  __write_csr(_CSR_MCAUSE, mcause);
  __write_csr(_CSR_MEPC, mepc);
  __write_csr(0x7C4, msubm);
}

int __low_level_init()
{
  __disable_interrupt();
  /* Set the the NMI base to share with mtvec by setting CSR_MMISC_CTL */
  /* li t0, 0x200           */
  /* csrs CSR_MMISC_CTL, t0 */
  __set_bits_csr(0x7D0, 0x200);

  /* Initialize the mtvt */
  /* la t0, vector_base      */
  /* csrw CSR_MTVT, t0       */
  __write_csr(_CSR_MTVT, ((unsigned int)&gd_vector_base));
  /* Initialize the mtvt2 and enable it */
  /* la t0, irq_entry
     csrw CSR_MTVT2, t0
     csrs CSR_MTVT2, 0x1
  */
  __write_csr(0x7EC, 0x1 | ((unsigned int)&irq_entry));

  /* Initialize the CSR MTVEC for the Trap ane NMI base addr*/
  /* la t0, trap_entry
     csrw CSR_MTVEC, t0
  */
  __write_csr(_CSR_MTVEC, 0x03 | ((unsigned int)&trap_entry));

#ifdef __riscv_flen
    /* Enable FPU */
    /* li t0, MSTATUS_FS
    csrs mstatus, t0
    csrw fcsr, x0
   */
    __set_bits_csr(_CSR_MSTATUS, 0x00006000);
#endif

  /* Enable mycycle_minstret CSR_MCOUNTINHIBIT */
  __clear_bits_csr(0x320, 0x5);
  return 1;
}

void _premain_init(void)
{
    /* TODO: Add your own initialization code here, called before main */
    /* __ICACHE_PRESENT and __DCACHE_PRESENT are defined in demosoc.h */
    EnableICache();

    /* ECLIC initialization, mainly MTH and NLBIT */
    eclic_level_threshold_set(0);
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL2_PRIO2);
    eclic_global_interrupt_enable();

    /* Before enter into main, disable mcycle and minstret counter by default to save power */
    __disable_all_counter();
}