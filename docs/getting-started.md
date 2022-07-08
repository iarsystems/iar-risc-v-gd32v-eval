# Getting started with the IAR RISC-V GD32V Eval board

This guide briefly describes how to get started using the __IAR RISC-V GD32V Eval board__  with the __I-jet Lite__ debug probe and how to run its example projects on the __[IAR Embedded Workbench for RISC-V](https://www.iar.com/riscv)__.

## Getting Started

### Evaluation board at-a-glance

![](images/07-board-layout.png)

> Click on the [board layout](images/07-board-layout.png) to enlarge.


### Board specifications

<img align="right" src="images/00-board.png" width=400px />

* GD32VF103RBT6 RISC-V GigaDevice MCU
* User [LEDs](../Examples/leds)
* [RGB LED](../Examples/rgb-led)
* User [switches](../Examples/switches)
* [Potentiometer](../Examples/potentiometer)
* I²C 3-axis [accelerometer](../Examples/accelerometer)
* I²C [temperature-humidity](../Examples/temperature-humidity) sensors
* Light sensor
* On-board microphone
* iPhone compatible earbud jack
* [SPI flash](../Examples/spi-flash) memory
* Reset button 
* JTAG connector 20-pin 0.05” 
* USB micro-B connector for USB/Serial converter 
* Power can be supplied directly from the USB connector (__J7__) or from the I-jet Lite (__J11__ pins 11 and 13)



### I-jet Lite debug probe 

<img align="right" src="images/00-ijet-lite.PNG" width=200px />

* CPU support: RISC-V cores, Arm Cortex-M/A/R cores 
* Hi-speed USB 2.0 interface
* Debugging interfaces: JTAG, SWD
* Single-Wire Output (SWO) support  
* Flash the firmware image into the MCU
* Target can be powered from the debugging interface (up to 5V) 
* MIPI-20 flat cable and USB micro B cable are included 
* Fully integrated with the IAR Embedded Workbench for RISC-V (and for Arm) 
* RoHS/CE compliant (used with evaluation kit only)
 
## Install IAR Embedded Workbench for RISC-V

Please refer to the installation instructions from the welcome e-mail for the RISC-V evaluation kit.


## Set up the evaluation board

1. Connect one end of the MIPI-20 flat cable to the I-jet Lite and the other end of the cable to the __J11__ JTAG header on the evaluation board.

2. Connect the I-jet Lite to an USB port of the host PC using the USB micro B cable.

> __Note__
> * The __USB__ indicator on the I-jet Lite should turn on green as soon as Windows recognizes the device.
>
> * The I-jet Lite requires an USB 2.0 port on the host PC.
>
> * The I-jet Lite can power the evaluation board. Refer to the section [Target power supply from I-jet Lite](#target-power-supply-from-i-jet-lite) for more details. 
>
> * The [Debug Probes User Guide](https://netstorage.iar.com/SuppDB/Public/UPDINFO/014860/riscv/doc/EWRISCV_DebugProbes.pdf) provides further information.


## Clone the repository

Once you have finished to install and setup the required software and hardware for the development environment, it is time to clone the repository containing the [example projects](https://github.com/IARSystems/iar-risc-v-gd32v-eval/tree/master/Examples). 

Cloning the repository must be performed only once until decided to upgrade to the latest version available on the repository and there are many methods of cloning it. Below the steps for the two most common methods.

### Using Git (preferred way)

1. Using a Git client (such as [Git for Windows](https://git-scm.com/download/win)), launch __Git CMD__.

2. Perform the following command to clone this repository with the __GD32VF103 Firmware Library__ submodule.
```
git clone --recurse-submodules https://github.com/IARSystems/iar-risc-v-gd32v-eval.git %PROGRAMDATA%\IARSystems\EmbeddedWorkbench\DownloadedExamples\riscv\iar-risc-v-gd32v-eval
```

>__Note__ The projects in the master branch of this repository work with EWRISCV 3.10.1 (or later).
><details><summary>For using with earlier versions, perform the following (click to unfold)</summary>
>
>```
>cd %PROGRAMDATA%\IARSystems\EmbeddedWorkbench\DownloadedExamples\riscv\iar-risc-v-gd32v-eval
>
>git checkout tags/1.30.1
>```
>
></details>

### Using ZIP (alternate way)

1. Create the folder `%PROGRAMDATA%\IARSystems\EmbeddedWorkbench\DownloadedExamples\riscv` if needed.

2. Go to the [tags](https://github.com/IARSystems/iar-risc-v-gd32v-eval/tags) page.

3. Download the `.zip` archive suitable for the version of the Embedded Workbench for RISC-V.

4. Extract the `.zip` archive to the `riscv` folder created on _step 1_.

5. Download the [__GD32VF103 Firmware Library v1.1.1__](https://github.com/GigaDevice-Semiconductor/GD32VF103_Firmware_Library/archive/refs/tags/V1.1.1.zip) available from the [GigaDevice](https://github.com/GigaDevice-Semiconductor) GitHub page.

6. Extract the __Firmware__ folder from the `GD32VF103_Firmware_Library-1.1.1.zip` archive to the `%PROGRAMDATA%\...\riscv\iar-risc-v-gd32v-eval-<tag>\GD32VF103_Firmware_Library` folder.

> __Note__ Replace `<tag>` by the chosen version on _step 3_.

## Build and Debug the example projects

1. From the Windows Start menu, launch the __IAR Embedded Workbench IDE__ by choosing __IAR Systems__ → __IAR Embedded Workbench for RISC-V__.

2. Go to `Help` → `Information Center` → `Example projects` → `IAR RISC-V GD32V Eval` → `IAR RISC-V GD32V Eval board examples` and finally click on `Select Folder` to save this Workspace to its default location, inside the `%USERPROFILE%\Documents\IAR Embedded Workbench` folder.

![](images/02-examples.png)

3. Select the desired project: right-click on the project name in the __Workspace__ window and `Set as Active`. The active project name is __highlighted__.

4. Unfold the project in the __Workspace__ window and open its __README.md__ file. The README.md file provides any specific board setup or details specific to the active project.

5. Choose `Project` → `Make` (or <kbd>F7</kbd>) or click the `Make` button on the main toolbar to compile and link the project.

6. Choose `Project` → `Download and Debug` (or <kbd>CTRL</kbd> + <kbd>D</kbd>) or click the `Download and Debug` button on the _Toolbar_. This action will launch the __IAR C-SPY Debugger__.

> __Note__
> * When in an __IAR C-SPY Debugger__ session, the IDE menu will slightly change, providing new menu options for debugging. Also, a new _Debug Toolbar_ will appear, providing functionality to control the downloaded application's execution flow. 
> * The downloaded application will execute automatically on target until it reaches the entry point of the application's `main()` function, where its execution will remain paused until an user action changes the execution flow. The Code Editor window will display the source file containing the `main()` function, highlighting the line where the application currently is.

7. Click `Debug` → `Go` (or <kbd>F5</kbd>) or click the `Go` button on the _Debug Toolbar_ to resume the downloaded application execution. 

8. To halt the execution, choose `Debug` → `Break` or click the `Break` button on the _Debug Toolbar_.

9. To exit the __IAR C-SPY Debugger__, choose `Debug` → `Stop Debugging` (or <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>D</kbd>) or click the `Stop Debugging` button on the _Debug Toolbar_.

> __Note__
> * You can `Set as Active` any project from this workspace and repeat the process.
> * The board brings jumpers with user-selectable functionality for its buttons, LEDs and powering options. Refer to the respective example's README.md to know if the [example](../Examples) requires any specific jumper settings. The table below brings the board's general jumper configuration.
>
> | __Jumper__     | __Position__       |  __Selection__          |
> | :------------- | :----------------- | :---------------------- |
> | J5             |  1-2<br>2-3        | LED3<br>Green LED       |
> | J6             |  1-2<br>2-3        | USB/Debug<br>J4         |
> | J8             |  1-2<br>2-3        | SW4<br>Red LED          |
> | J9             |  1-2<br>3-4<br>5-6 | SW5<br>Blue LED<br>LED4 |

##  View and edit project options

1. Make sure the desired project name is __highlighted__ in the workspace window. On the `Project` menu, select `Options`. An __Options for node `<active-project>`__ window will be displayed.

![](images/03-options.png)
 
2. The Project Options window offers a graphical user interface for conveniently setting all the options for the build configuration. For example, by selecting processor family and device under the __Target__ _tab_ of the __General Options__ _Category_, the appropriate linker configuration and device description for the debugger are automatically selected for the chosen device.

![](images/04-target.png)
 
3. Select the __Debugger__ in the category. The option `Run to` is used to specify a function for an automatic initial breakpoint when the application is executed during a C-SPY Debugger. By default, IAR Embedded Workbench will insert a breakpoint in the `main()` function entry point. This is particularly useful for skipping the application's low-level initialization functions. 

![](images/05-debugger.png)
 
4. Click `OK` if you want to save your settings.

## Target power supply from I-jet Lite
To power the evaluation board directly from the I-jet Lite, proceed as follows.

1. Choose `Project` → `Options` → `I-jet` → `Setup` to enable __Target power__ supply from the I-jet Lite. 

![](images/06-ijet.png)

2. Then, on the board, use a jumper on __J6__ to connect the pins `1-2` (for USB/Debug).
 
## Troubleshooting
If you are unable to find the cause of a problem, try the following:
- Try to press the board's `RESET` button.
- Try to restart the C-SPY Debugger in the IAR Embedded Workbench IDE. 
- Try disconnecting and reconnecting the power to the evaluation board and then repeat the previous sequence with the `RESET` followed by restarting of the C-SPY.

---
### Disclaimer
Information provided in this document is intended for helping new IAR Embedded Workbench users on how to get started. IAR Systems shall not be held liable for any losses or problems arising from using the information given in this document. 
