# IAR RISC-V GD32V Evaluation kit - Project examples

The [Examples projects](Examples) in this repository are designed to be run on the [__IAR RISC-V GD32V Evaluation board__][gd32v-evalkit-url] with the [IAR Embedded Workbench for RISC-V][ewriscv-url].

Start with the [__Getting Started__ guide](docs/getting-started.md).

For related documentation and schematics, follow this [link](docs).

Follow this [link](docs/safertos.md), if you want learn more about [SAFE**RTOS**®](docs/safertos.md) on the IAR RISC-V GD32V board.

If you have questions regarding this repository contents, you can start by checking its [issue tracker][repo-old-issue-url] for the previously asked questions.
If it is a new question, feel free to post it [here][repo-new-issue-url].

[repo-new-issue-url]: https://github.com/IARSystems/iar-risc-v-gd32v-eval/issues/new
[repo-old-issue-url]: https://github.com/IARSystems/iar-risc-v-gd32v-eval/issues?q=is%3Aissue+is%3Aopen%7Cclosed

For learning how you can contribute with new projects to this repository, follow this [link](contributions).

---

The board brings jumpers with user-selectable functionality for its buttons, LEDs and powering options, according to the table below. 

| __Jumper__     | __Position__       |  __Selection__          |
| :------------- | :----------------- | :---------------------- |
| J5             |  1-2<br>2-3        | LED3<br>Green LED       |
| J6             |  1-2<br>2-3        | USB/Debug<br>J4         |
| J8             |  1-2<br>2-3        | SW4<br>Red LED          |
| J9             |  1-2<br>3-4<br>5-6 | SW5<br>Blue LED<br>LED4 |

If an [example](Examples) requires any specific jumper settings, refer to its respective README.md file.

[gd32v-evalkit-url]: https://www.iar.com/evalkit
[ewriscv-url]: https://iar.com/riscv
