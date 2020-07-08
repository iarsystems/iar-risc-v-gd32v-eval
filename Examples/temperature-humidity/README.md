# IAR RISC-V GD32V EVAL - Temperature/Humidity sensor example

This project exercises the SHT31 I2C Temperature/Humidity sensor mounted in this board.

## Jumper settings

To run this example, make sure that the jumper positions on the evaluation board are set for the LEDs to blink. 
The settings are __highlighted__ on the following jumper tables: 

| __J5__         | __Position__    |  __Options__   |
| :------------- | :-------------- | :------------- |
|                | 1-2             | LED3           |
|                | __2-3__         | __Green LED__  |

| __J6__         | __Position__    |  __Options__   |
| :------------- | :-------------- | :------------- |
|                | __1-2__         | __USB/Debug__  |
|                | 2-3             | J4             |

| __J8__         | __Position__    |  __Options__   |
| :------------- | :-------------- | :------------- |
|                | 1-2             | SW4            |
|                | __2-3__         | __Red LED__    |

| __J9__         | __Position__    |  __Options__   |
| :------------- | :-------------- | :------------- |
|                | 1-2             | SW5            |
|                | __3-4__         | __Blue LED__   |
|                | 5-6             | LED4           |

## Building and Running

By default, the IAR Embedded Workbench is set to use the `System` character encoding. For this example we will need take advantage of the `UTF-8` character set for displaying the grade (__`°`__) character correctly.

* To update the __code editor__ character set to use the __UTF-8__ encoding, go to `Tools → Options → File Encoding → Default character encoding` and choose `UTF-8`. Press `OK` to close this window.

To build and run the project, select `Project → Make (F7)`.

Once the build is complete, connect your evaluation board debugger 20-pin header (__J11__) to the I-jet debugging probe and then select `Project → Download and Debug (CTRL + D)`.

The IDE will slightly change its initial appearance and new menu options will become available as it enters in debug mode.
This project uses the integrated IAR Embedded Workbench virtual terminal to output the accelerometer (x,y,z)-axis data.

In order to see the sensor data in real time, select `View → Terminal I/O`. A new window named __Terminal I/O__ will show up without any output so far.

* To update the __Terminal I/O__ character set to use the __UTF-8__ encoding, go to `Tools → Options → Terminal I/O → Encoding` and choose `UTF-8`. Press `OK` to close this window.

Next, execute the program by selecting `Debug → Go (F5)`.

Finally, grab the nearest fan or an air blower to change the temperature and watch the RGB LED and the LED bar update in accordance with the temperature/humidity sensor data. It might take a while for the changes take effect as measuring temperature and humidity is not an instantaneous operation.

Depending on your weather conditions, you might have to adjust the fixed point _threshold_ values be able to see these variations. The _threshold_ values are expressed by a 1000x factor. For example, 25°C should be expressed as `25000`.

| __Temperature threshold__ |  __Set when data is__                                          | 
| :--------------           | :-------------                                                 |
| Low                       | below __TEMP_LOW_THRESHOLD__                                   |
| Medium                    | between __TEMP_LOW_THRESHOLD__ and __TEMP_MEDIUM_THRESHOLD__   |
| High                      | above __TEMP_MEDIUM_THRESHOLD__                                |

| __Humidity threshold__    |  __Set when data is__                                          | 
| :--------------           | :-------------                                                 |
| Low                       | below __HUM_LOW_THRESHOLD__                                    |
| Medium                    | between __HUM_LOW_THRESHOLD__ and __HUM_MEDIUM_THRESHOLD__     |
| High                      | above __HUM_MEDIUM_THRESHOLD__                                 |

To terminate the debugging session, stop the C-SPY debugger, choose `Debug → Stop Debugging (CTRL + SHIFT + D)`.
