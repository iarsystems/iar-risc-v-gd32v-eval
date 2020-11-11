# IAR RISC-V GD32V EVAL - Potentiometer example

## Introduction
The potentiometer __R1__ pin is read from the analog-to-digital conversion and its value is printed in the Terminal I/O on regular intervals.

## Building and Running
	
To build and run the benchmark, select 

- `Project` → `Make` (or <kbd>F7</kbd>)

Once the build is complete, connect your evaluation board debugger 20-pin header to the I-jet debugging probe and then select

- `Project` → `Download and Debug` (or <kbd>CTRL</kbd> + <kbd>D</kbd>)

The IDE will slightly change its initial appearance and new menu options will become available as it enters in debug mode.

This project uses the IAR Embedded Workbench integrated __Terminal__ I/O to show results.

In order to see the results, select
- `View` → `Terminal I/O`

A new window named __Terminal I/O__ will show up without any output so far.

Next, execute the program by selecting
- `Debug` → `Go` (or <kbd>F5</kbd>)

### Terminal I/O output
The expected Terminal I/O output visualization should be similar to the one below, with the values changing when the __R1__ potentiometer position changes:
```
> ---
> Potentiometer example
> 
> Value: 1168
> Value: 1255
> Value: 1347
> Value: 1431
> Value: 1789
> Value: 2247
> Value: 3047
> ...
> ```
