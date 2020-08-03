/*!
    \file  compiler.h
    \brief ICCRISCV wrapper 

    \version 20200803 
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#ifndef __COMPILER_H__
#define __COMPILER_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __ICCRISCV__

#include <intrinsics.h>
#include <stdlib.h>

/* from intrinsics.h */
#define read_csr    __read_csr
#define set_csr     __write_csr
#define write_csr   __write_csr
#define clear_csr   __clear_bits_csr

/* from csr.h */
#define mstatus     _CSR_MSTATUS
#define mcycle      _CSR_MCYCLE
#define mcycleh     _CSR_MCYCLEH
#define mtvec       _CSR_MTVEC
#define minstret    _CSR_MINSTRET
#define minstreth   _CSR_MINSTRETH


#endif /* __ICCRISCV__ */ 

#ifdef __cplusplus
}
#endif

#endif /* __COMPILER_H__ */
