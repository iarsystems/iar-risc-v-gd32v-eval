# IAR RISC-V GD32V EVAL - Accelerometer example

This project exercises the MMA8652 I2C 3-axis accelerometer mounted on this board.

## Jumper settings

To run this example, make sure that the jumpers on the evaluation board are set for the LEDs. 
The settings are __highlighted__ in the following tables: 

| __J5__         | __Position__    |  __Option__   |
| :------------- | :-------------- | :------------- |
|                | __1-2__         | __LED3__       |
|                | 2-3             | Green LED      |

| __J6__         | __Position__    |  __Option__   |
| :------------- | :-------------- | :------------- |
|                | __1-2__         | __USB/Debug__  |
|                | 2-3             | J4             |

| __J9__         | __Position__    |  __Option__   |
| :------------- | :-------------- | :------------- |
|                | 1-2             | SW5            |
|                | 3-4             | Blue LED       |
|                | __5-6__         | __LED4__       |

## Building and Running
	
To build and run the project, select `Project → Make` (or <kbd>F7</kbd>).

Once the build is complete, connect your evaluation board debugger 20-pin header (__J11__) to the I-jet debugging probe and then select `Project → Download and Debug` (or <kbd>CTRL</kbd> + <kbd>D</kbd>).

The IDE will slightly change its initial appearance and new menu options will become available as it enters in debug mode.
This project uses the integrated IAR Embedded Workbench virtual terminal to output the accelerometer (x,y,z)-axis data.

In order to see the sensor data in real time, select `View → Terminal I/O`. A new window named __Terminal I/O__ will show up without any output so far.

Next, execute the program by selecting `Debug → Go` (or <kbd>F5</kbd>).

Finally, tilt the board and watch the LED bar to toggle in accordance with the current gravitational data.

To terminate the debugging session, stop the C-SPY debugger, choose `Debug → Stop Debugging` ( or <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>D</kbd>).
