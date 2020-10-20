# Getting started with the IAR RISC-V GD32V Eval board

This guide briefly describes how to get started using __[IAR Embedded Workbench for RISC-V](https://www.iar.com/riscv)__ with the __I-jet Lite__ debug probe, to run an example application on the [IAR RISC-V GD32V Eval board](https://iar.com/evalkit). 

## Table of contents
* [IAR RISC-V GD32V Eval board at a glance](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#iar-risc-v-gd32v-eval-board-at-a-glance)
* [I-jet Lite debug probe](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#i-jet-lite-debug-probe)
* [Install IAR Embedded Workbench for RISC-V](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#1install-iar-embedded-workbench-for-risc-v)
* [Set up the evaluation board](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#2set-up-the-evaluation-board)
* [Running example applications](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#3running-example-applications)
* [Viewing and editing project options](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#4-viewing-and-editing-project-options)
* [Target power supply from I-jet Lite](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#5-target-power-supply-from-i-jet-lite)
* [Board overview](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#board-overview)
* [Troubleshooting](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#troubleshooting)

## Getting Started

### IAR RISC-V GD32V Eval board at a glance
* GD32VF103RBT6 RISC-V GigaDevice MCU
* User [LEDs](../Examples/leds)
* [RGB LED](../Examples/rgb-led)
* User [switches](../Examples/switches)
* [Potentiometer](../Examples/potentiometer)
* I²C 3-axis [accelerometer](../Examples/potentiometer)
* I²C [temperature-humidity](../Examples/temperature-humidity) sensors
* Light sensor
* On-board microphone
* iPhone compatible earbud jack
* [SPI flash](../Examples/spi-flash) memory
* Reset button 
* JTAG connector 20-pin 0.05” 
* USB micro-B connector for USB/Serial converter 
* Power can be supplied directly through USB micro-B connector or through I-jet Lite (pin 11/13 JTAG connector)

![](images/00-board.png)

### I-jet Lite debug probe 
* MCU support: RISC-V, Arm Cortex-M/A/R devices 
* JTAG/SWD(/SWO) debugging support 
* Flash download into supported evaluation boards 
* Up to 5V target interface voltage 
* MIPI-20 cable and USB-micro cable included 
* Fully integrated with IAR Embedded Workbench 
* RoHS/CE compliant (used with starter kit only)

![](images/00-ijet-lite.PNG)
 
## 1.	Install IAR Embedded Workbench for RISC-V

Please refer to the installation instructions from the welcome e-mail for the RISC-V evaluation kit.

## 2.	Set up the evaluation board

1. Using the MIPI-20 flat cable, connect the I-jet Lite to the __J11__ JTAG header of the evaluation board.

2. Using the USB micro B cable, connect the I-jet Lite to an USB port of the host PC. 

> __Notes__
> * The __USB__ indicator on the I-jet Lite should turn on green as soon as Windows recognizes the device.
>
> * The I-jet Lite requires an USB port 2.0 (or later) on the host PC.
>
> * The I-jet Lite can power the evaluation board. Refer to the section [Target power supply from I-jet Lite](5-target-power-supply-from-i-jet-lite) for more details. 
>
> * Please refer to the [Debug Probes User Guide](https://netstorage.iar.com/SuppDB/Public/UPDINFO/014860/riscv/doc/EWRISCV_DebugProbes.pdf) for further reference.

## 3.	Running example applications

When you have installed and set up all the software and hardware, you can try one of the example applications provided for IAR Embedded Workbench For trial projects you can access the [board's repository](https://github.com/IARSystems/iar-risc-v-gd32v-eval) at the [IAR Systems GitHub page](https://github.com/IARSystems).

1. Clone (or download) the repository for the [IAR RISC-V GD32V Eval board](https://github.com/IARSystems/iar-risc-v-gd32v-eval).

![](images/01-repo.png)

2. From the Windows Start menu, launch the __IAR Embedded Workbench IDE__ by choosing __IAR Systems__ → __IAR Embedded Workbench for RISC-V__.

3. Open the Examples Workspace by selecting `File → Open Workspace`, navigate to the [Examples](Examples) folder and choose the __Examples.eww__ file.

![](images/02-examples.png)

4. Right-click on the desired project and select `Set as Active`.

5. Unfold the project in the __Workspace__ window and open its __README.md__ file. The README.md file provides any specific board setup or details specific to the active project.

6. Choose `Project` → `Make` (or <kbd>F7</kbd>) or click the `Make` button on the main toolbar to compile and link the project.

7. Choose `Project` → `Download and Debug` (or <kbd>CTRL</kbd> + <kbd>D</kbd>) or click the `Download and Debug` button on the _Debug Toolbar_.

8. Use the default settings in the hardware setup dialog box that is displayed. Click `OK`. This will cause your application to be downloaded to the evaluation board.

9. The source file including the _main()_ function is now displayed in the editor window and the application is stopped at the entry point.

10. Click `Debug` → `Go` (or <kbd>F5</kbd>) or click the `Go` button on the _Debug Toolbar_ to start the application. 

11. To halt the execution, choose `Debug` → `Break` or click the `Break` button on the _Debug toolbar_.

12.	To exit C-SPY, choose `Debug` → `Stop Debugging` (or <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>D</kbd>) or click the `Stop Debugging` button on the _Debug Toolbar_.

> __Note__
> * You can `Set as Active` another project of the workspace and repeat this process.

##  4. Viewing and editing project options

1. On the `Project` menu, select `Options`. Make sure the project name is highlighted in the workspace window and a dialog box will be displayed.

![](images/03-options.png)
 
2. The Options dialog box provides options for the building tools and the debugger. For example, by selecting processor family and device under General Options in the category list to, the correct linker configuration file and device description file are automatically chosen for this device.

![](images/04-target.png)
 
3. Select `Debugger` in the category list to verify what options are used.

4. The option `Run to` is used to specify the location to which C-SPY executes when the debugger is started and after a reset. By default, IAR Embedded Workbench will insert a breakpoint in the main() function automatically.

![](images/05-debugger.png)
 
5. Click `OK` if you want to save your settings.

## 5. Target power supply from I-jet Lite
To power the Evaluation Board directly from the I-jet Lite, proceed as follows.

1. Choose `Project` → `Options` → `I-jet` → `Setup` to enable __Target power__ supply from the I-jet Lite. 

![](images/06-ijet.png)

2. Then close the `1-2` pins (USB/Debug)  on the board's jumper __J4__.

## Board overview

![](images/07-board-layout.png)
 
## Troubleshooting
If you are unable to find the cause of a problem, try resetting the evaluation board by using the reset button on the board. Then restart the C-SPY Debugger in the IAR Embedded Workbench IDE. You can also try disconnecting and reconnecting the power to the evaluation board, pressing the reset button and then restarting C-SPY.

---
### Disclaimer
Information given in this document is intended as a help for the user. IAR Systems shall not be held liable for any losses or problems arising from using the information given in this document. 
