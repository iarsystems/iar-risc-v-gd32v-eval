# Template project

## Introduction

This project provides a clean slate as a shortcut for starting new projects with the IAR GD32V Eval Board and the IAR Embedded Workbench for RISC-V.

This template should be used for easily creating new projects and also for contributing with new projects on the contributions folder in this repository.
When the project.template.eww is open on the IDE, a dialog window will offer to save the project in a new location.

When contributing with new projects, a new unique name folder for saving the project must be created on the same level of the template folder as follows:

```
├── contributions
│   ├── template
│   ├── <new project based on the template>
│   │   └──<folder belonging to the new project>
│   ├── <another contributed project>
```

**This README.md is in a format named "Markdown" and it should be updated accordingly to the newly created project.**

The new README.md should typically contain:

- Introduction/Description of the project
- Any needed jumper settings
- How to build an run the project
- Any other relevant remarks

When contributing, you might want to take a look at the existing examples for reference.
If you need guidance on how to rewrite this README.md using the Markdown syntax, refer to [Mastering Markdown](https://guides.github.com/features/mastering-markdown/).

## Details of the Template

* It provides GD32VF103 MCU system clock tree setup to 108 MHz.

* All the GD32VF103 drivers from the Firmware Library are included by default.

* All the BSP drivers for the IAR GD32V Eval Board are included by default.
