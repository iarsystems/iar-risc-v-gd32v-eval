# IAR RISC-V GD32V EVAL - Temperature/Humidity sensor example

This project exercises the SHT31 I2C Temperature/Humidity sensor mounted on this board.

## Jumper settings

To run this example, make sure that the jumpers on the evaluation board are set to use the RGB LED. 
The settings are __highlighted__ in the following tables: 

| __J5__         | __Position__    |  __Option__    |
| :------------- | :-------------- | :------------- |
|                | 1-2             | LED3           |
|                | __2-3__         | __Green LED__  |

| __J6__         | __Position__    |  __Option__    |
| :------------- | :-------------- | :------------- |
|                | __1-2__         | __USB/Debug__  |
|                | 2-3             | J4             |

| __J8__         | __Position__    |  __Option__    |
| :------------- | :-------------- | :------------- |
|                | 1-2             | SW4            |
|                | __2-3__         | __Red LED__    |

| __J9__         | __Position__    |  __Option__    |
| :------------- | :-------------- | :------------- |
|                | 1-2             | SW5            |
|                | __3-4__         | __Blue LED__   |
|                | 5-6             | LED4           |

## Building and Running

By default, the IAR Embedded Workbench is set to use the `System` character encoding. For this example, we will take advantage of the `UTF-8` character set for displaying the grade (__`°`__) character correctly.

* To update the __Code Editor__ character set to use the __UTF-8__ encoding, go to `Tools → Options → File Encoding → Default character encoding` and choose `UTF-8`. Press `OK` to close the __IDE Options__ window.

To build and run the project, select `Project → Make` (or <kbd>F7</kbd>).

Once the build is complete, connect your evaluation board debugger 20-pin header (__J11__) to the I-jet debugging probe and then select `Project → Download and Debug` (or <kbd>CTRL</kbd> + <kbd>D</kbd>).

The IDE will slightly change its initial appearance and new menu options will become available as it enters in debug mode.
This project uses the integrated IAR Embedded Workbench virtual terminal to output the sensor data.

In order to see the sensor data in real time, select `View → Terminal I/O`. A new window named __Terminal I/O__ will show up without any output so far.

* To update the __Terminal I/O__ character set to use the __UTF-8__ encoding, go to `Tools → Options → Terminal I/O → Encoding` and choose `UTF-8`. Press `OK` to close the  __IDE Options__ window.

Next, execute the program by selecting `Debug → Go` (or <kbd>F5</kbd>).

Finally, grab the nearest fan, air blower or hair dryer and use them to cause changes in the temperature surrounding the evaluation board. When the temperature/humidity thresholds are crossed, the RGB LED and the LED bar will update their states, always in accordance with the temperature/humidity sensor data. Keep in mind that it might take a while for the changes to take effect, as measuring temperature and humidity is not an instantaneous operation.

To terminate the debugging session, stop the C-SPY debugger, choose `Debug → Stop Debugging` (or <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>D</kbd>).

> ### Note
> Depending on the room temperature/humidity conditions, you might have to adjust the fixed point _threshold values_ be able to cross over the different _threshold levels_. You will find that _threshold values_ in the _main.c_ file are expressed by a __1000x__ factor. For example, 25°C should be expressed as `25000`. If that is the case you are facing, update these _threshold values_, rebuild the project and restart the debugging session. The tables below summarize how the _threshold levels_ changes which LED will be lit.

| __Temperature threshold__ |  __Set when data is__                                          | __Board LED__  |
| :--------------           | :-------------                                                 | :-------       |
| Low                       | below __TEMP_LOW_THRESHOLD__                                   | Blue LED       |
| Medium                    | between __TEMP_LOW_THRESHOLD__ and __TEMP_MEDIUM_THRESHOLD__   | Green LED      |
| High                      | above __TEMP_MEDIUM_THRESHOLD__                                | Red LED        |

| __Humidity threshold__    |  __Set when data is__                                          | __Board LED__  |
| :--------------           | :-------------                                                 | :--------      |
| Low                       | below __HUM_LOW_THRESHOLD__                                    | 3              |
| Medium                    | between __HUM_LOW_THRESHOLD__ and __HUM_MEDIUM_THRESHOLD__     | 3 and 2        |           
| High                      | above __HUM_MEDIUM_THRESHOLD__                                 | 3, 2 and 1     |
