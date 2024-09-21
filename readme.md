# gpm - GNU Package Manager

**Copyright (C) 2024 Voltaged**  
**License: GNU General Public License v3**

This manual documents `gpm`, a simple package manager for GNU/Linux systems.

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Usage](#usage)
   1. [Commands](#commands)
   2. [Command Options](#command-options)
4. [Examples](#examples)
5. [Author](#author)
6. [License](#license)

## Introduction

`gpm` is a simple package manager designed to install, list, remove, and update packages on GNU/Linux systems. It uses `tar.gz` archives for packaging and requires a manifest file to manage dependencies and versions.

## Installation

To build `gpm`, you need to have a C compiler (such as `gcc`) installed on your system. Follow these steps:

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd gpm
   ```

2. Compile the program:
   ```bash
   make
   ```

3. Install (optional):
   ```bash
   sudo make install
   ```

## Usage

To use `gpm`, invoke it from the command line with a command and its options.

### Commands

`gpm` supports the following commands:

- `install <package>`: Install a package from the packages directory.
- `list`: List all installed packages.
- `remove <package>`: Remove an installed package.
- `update <package>`: Update an installed package to the latest version.
- `help`: Display this help message.

### Command Options

Each command can be executed with its required parameters. If a parameter is missing, `gpm` will display an error message indicating the missing argument.

## Examples

To install a package:
```bash
./gpm install hello-1.0.tar.gz
```

To list installed packages:
```bash
./gpm list
```

To remove a package:
```bash
./gpm remove hello
```

To update a package:
```bash
./gpm update hello-2.0.tar.gz
```

## Author

This package manager was created by Voltaged <rusindanilo@example.com>.

## License

`gpm` is distributed under the terms of the GNU General Public License v3. See the LICENSE file for more details.