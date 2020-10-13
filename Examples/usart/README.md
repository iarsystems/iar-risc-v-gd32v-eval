# IAR RISC-V GD32V EVAL - USART interrupt-driven Transmitter/Receiver mini game 

## Building
	
To build the project, select 

`Project → Make` (or <kbd>F7</kbd>)


## Board Setup

1. Connect __J11__ to the I-jet Lite probe.
2. Connect the I-jet Lite probe to one PC USB port.
3. Connect __J7__ to another PC USB port.

* For more information regarding the I-jet probe, refer to the [IAR Debug Probes User Guide][ijet-guide-url].

[ijet-guide-url]: https://netstorage.iar.com/SuppDB/Public/UPDINFO/014617/riscv/doc/EWRISCV_DebugProbes.pdf 

Open a __Serial Terminal Emulator__ and configure the COM port with the following settings:

| __Baud rate__ | __Data__ | __Bit Parity__ | __Stop Bit__ | __Flow Control__ |
|--------------:|---------:|---------------:|-------------:|-----------------:|
|      `115200` |      `8` |         `None` |          `1` |           `None` |

> __Note__
> * This project example was tested with [Tera Term][tera-term-url] and [PuTTY][putty-url] as __Serial Terminal Emulator__.

[tera-term-url]: https://ttssh2.osdn.jp/index.html.en
[putty-url]: https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html 

## Running

To start the debug session on the IAR Embedded Workbench IDE select

`Project → Download and Debug` (or <kbd>CTRL</kbd> + <kbd>D</kbd>)

The IDE will slightly change its initial appearance and new menu options will become available as it enters in debug mode.

Next, execute the program by selecting
`Debug → Go` (or <kbd>F5</kbd>)

The __Serial Terminal Emulator__ should display a welcome message with an output similar to the following:
```
---
USART example

Type: <fruit>
█
```

> __Note__
> * The `<fruit>` is randomly selected from a word list.

When a character is sent to the serial port, a __dot__ will show on the __Serial Terminal Emulator__. For example:
```
---
USART example

Type: kiwi
...█
```

Once the word has been correctly typed, a result message will be displayed and a new word will be randomly selected for the next round:
```
---
USART example

Type: kiwi
....
Well done!

Type: papaya
█
```

If the typed word do not match the selected word, an error message will be displayed and the program will await for the user to try again the previously select word: 

```
---
USART example

Type: kiwi
....
Try again!
█
```

---
Navigate: [Initial Page][home-url]

[home-url]: ../../README.md
