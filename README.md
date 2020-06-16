# Getting started with IAR RISC-V GD32V Evaluation board

This guide briefly describes how to get started using the IAR Embedded Workbench for RISC-V with the I-jet Lite debug interface. The project examples in this repository are designed to be run on the IAR RISC-V GD32 Eval board.


For documentation and schematics, follow this [link](docs).


Make sure that the following jumpers are correctly configured on the evaluation board:

| __Jumper__     | __Description__ |   __Position__  |
| :------------- | :-------------- |  -------------- |
| J6             | Power USB/Debug |  1-2            |
| J5             | Green LED       |  2-3            |
| J8             | Red LED         |  2-3            |
| J9             | Blue LED        |  2-3            |

For the __USART__ example, configure the Serial Port in the Virtual Terminal with the following settings:

| __Setting__    |  __Selection__  |
| :------------- | :-------------- |
| Baud rate      | 115200          |
| Data           | 8               |
| Bit Parity     | None            |
| Stop bit       | 1               | 
| Flow Control   | None            | 


**You also need to activate the Terminal I/O built into the IAR Embedded Workbench IDE (View → Terminal I/O)**

For questions please reach out to [fae@iar.com](mailto:fae@iar.com?subject=Question%20from%20GitHub). 
We are happy to assist you with any additional questions or guidance. 

*More examples will be uploaded shortly.*
