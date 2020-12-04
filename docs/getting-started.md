# Getting started with the IAR RISC-V GD32V Eval board

This guide briefly describes how to get started using __[IAR Embedded Workbench for RISC-V](https://www.iar.com/riscv)__ with the __I-jet Lite__ debug probe, to run an example application on the [IAR RISC-V GD32V Eval board](https://iar.com/evalkit). 

## Table of contents
* [IAR RISC-V GD32V Eval board at a glance](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#iar-risc-v-gd32v-eval-board-at-a-glance)
* [I-jet Lite debug probe](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#i-jet-lite-debug-probe)
* [Install IAR Embedded Workbench for RISC-V](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#install-iar-embedded-workbench-for-risc-v)
* [Set up the evaluation board](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#set-up-the-evaluation-board)
* [Build and Debug the example projects](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#build-and-debug-the-example-applications)
* [View and edit project options](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#view-and-edit-project-options)
* [Target power supply from I-jet Lite](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#target-power-supply-from-i-jet-lite)
* [Board overview](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#board-overview)
* [Troubleshooting](https://github.com/IARSystems/iar-risc-v-gd32v-eval/blob/master/docs/getting-started.md#troubleshooting)

## Getting Started

### IAR RISC-V GD32V Eval board at a glance

<img align="right" src="images/00-board.png" width=400px />

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



### I-jet Lite debug probe 

<img align="right" src="images/00-ijet-lite.PNG" width=200px />

* MCU support: RISC-V, Arm Cortex-M/A/R devices 
* JTAG/SWD(/SWO) debugging support 
* Flash download into supported evaluation boards 
* Up to 5V target interface voltage 
* MIPI-20 cable and USB-micro cable included 
* Fully integrated with IAR Embedded Workbench 
* RoHS/CE compliant (used with starter kit only)
 
## Install IAR Embedded Workbench for RISC-V

Please refer to the installation instructions from the welcome e-mail for the RISC-V evaluation kit.


## Set up the evaluation board

1. Connect one end of the MIPI-20 flat cable to the I-jet Lite and the other end of the cable to the __J11__ JTAG header on the evaluation board.

2. Connect the I-jet Lite to an USB port of the host PC using the USB micro B cable.

> __Notes__
> * The __USB__ indicator on the I-jet Lite should turn on green as soon as Windows recognizes the device.
>
> * The I-jet Lite requires an USB port 2.0 (or later) on the host PC.
>
> * The I-jet Lite can power the evaluation board. Refer to the section [Target power supply from I-jet Lite](5-target-power-supply-from-i-jet-lite) for more details. 
>
> * The [Debug Probes User Guide](https://netstorage.iar.com/SuppDB/Public/UPDINFO/014860/riscv/doc/EWRISCV_DebugProbes.pdf) provides further information.


## Build and Debug the example projects

Once you have finished to install and setup the required software and hardware for the development environment, you can try one of the evaluation board's [example projects](https://github.com/IARSystems/iar-risc-v-gd32v-eval/tree/master/Examples) on the [IAR Embedded Workbench for RISC-V](https://iar.com/riscv).

1. Using a Git client (such as [Git for Windows](https://git-scm.com/download/win)), launch __Git CMD__ and then perform the following to clone this repository.
```
md %PROGRAMDATA%\IARSystems\EmbeddedWorkbench\DownloadedExamples\riscv

cd %PROGRAMDATA%\IARSystems\EmbeddedWorkbench\DownloadedExamples\riscv

git clone https://github.com/IARSystems/iar-risc-v-gd32v-eval.git --recurse-submodules
```

> __Note__
> * It is important to clone with `--recurse-submodules` because the __GD32VF103 Firmware Library__ is fetched directly from its official GitHub repository.
> * After the repository is cloned for the first time, it can be updated in a similar manner, by changing to its directory and pulling the updates as below:
>
> ```
> cd %PROGRAMDATA%\IARSystems\EmbeddedWorkbench\DownloadedExamples\riscv\iar-risc-v-gd32-eval
>
> git pull --recurse-submodules
> ```
>
> * The __IAR GD32V RISC-V Board Examples__ were tested with the __GD32VF103 Firmware Library V1.1.0__.

![](images/01-repo.png)

2. From the Windows Start menu, launch the __IAR Embedded Workbench IDE__ by choosing __IAR Systems__ → __IAR Embedded Workbench for RISC-V__.

3. Go to `Help` → `Information Center` → `Example projects` → `IAR GD32V EVAL` → `IAR GD32V EVAL board examples` and finally click on `Select Folder` to save this Workspace to its default location, inside the `%USERPROFILE%\Documents\IAR Embedded Workbench` folder.

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
> * You can `Set as Active` any project from this workspace and repeat the process.

##  View and edit project options

1. On the `Project` menu, select `Options`. Make sure the project name is highlighted in the workspace window and a dialog box will be displayed.

![](images/03-options.png)
 
2. The Options dialog box provides options for the building tools and the debugger. For example, by selecting processor family and device under General Options in the category list to, the correct linker configuration file and device description file are automatically chosen for this device.

![](images/04-target.png)
 
3. Select `Debugger` in the category list to verify what options are used.

4. The option `Run to` is used to specify the location to which C-SPY executes when the debugger is started and after a reset. By default, IAR Embedded Workbench will insert a breakpoint in the main() function automatically.

![](images/05-debugger.png)
 
5. Click `OK` if you want to save your settings.

## Target power supply from I-jet Lite
To power the Evaluation Board directly from the I-jet Lite, proceed as follows.

1. Choose `Project` → `Options` → `I-jet` → `Setup` to enable __Target power__ supply from the I-jet Lite. 

![](images/06-ijet.png)

2. Then close the `1-2` pins (USB/Debug)  on the board's jumper __J6__.

## Board overview

![](images/07-board-layout.png)
 
## Troubleshooting
If you are unable to find the cause of a problem, try the following:
- Try to press the board's `RESET` button.
- Try to restart the C-SPY Debugger in the IAR Embedded Workbench IDE. 
- Try disconnecting and reconnecting the power to the evaluation board and then repeat the previous sequence with the `RESET` followed by restarting of the C-SPY.

---
### Disclaimer
Information provided in this document is intended for helping new IAR Embedded Workbench users on how to get started. IAR Systems shall not be held liable for any losses or problems arising from using the information given in this document. 
