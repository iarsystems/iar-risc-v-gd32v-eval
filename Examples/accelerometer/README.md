# IAR RISC-V GD32V EVAL - Accelerometer example

This project exercises the MMA8652 I2C 3-axis accelerometer mounted in this board.

## Jumper settings

To run this example, make sure that the jumper positions on the evaluation board are set for the LEDs to blink. 
The settings are __highlighted__ on the following jumper tables: 

| __J5__         | __Position__    |  __Options__   |
| :------------- | :-------------- | :------------- |
|                | __1-2__         | __LED3__       |
|                | 2-3             | Green LED      |

| __J6__         | __Position__    |  __Options__   |
| :------------- | :-------------- | :------------- |
|                | __1-2__         | __USB/Debug__  |
|                | 2-3             | J4             |

| __J9__         | __Position__    |  __Options__   |
| :------------- | :-------------- | :------------- |
|                | 1-2             | SW5            |
|                | 3-4             | Blue LED       |
|                | __5-6__         | __LED4__       |

## Building and Running
	
To build and run the project, select 

`Project → Make (F7)`

Once the build is complete, connect your evaluation board debugger 20-pin header to the I-jet debugging probe and then select

`Project → Download and Debug (CTRL + D)`

The IDE will slightly change its initial appearance and new menu options will become available as it enters in debug mode.
This project uses the integrated IAR Embedded Workbench virtual terminal to output the accelerometer (x,y,z)-axis data.

In order to see the results, select `View → Terminal I/O`. A new window named __Terminal I/O__ will show up without any output so far.

Next, execute the program by selecting `Debug → Go (F5)`

Lastly, tilt the board and see the LEDs 1 to 5 scrolling in accordance to the gravitational data.
