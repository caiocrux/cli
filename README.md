

# CLI Tool

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![CMake](https://github.com/caiocruz/cli-tool/actions/workflows/cmake.yml/badge.svg)](https://github.com/caiocruz/cli-tool/actions/workflows/cmake.yml)

A modern C++ command-line interface framework built with CMake, featuring modular design and structured logging.

## Features

- **Command System**: Support for subcommands with `--command` flag
- **Help/Version**: Built-in `-h/--help` and `-v/--version` flags
- **Structured Logging**: Timestamped debug/error output
- **Modular Architecture**: Separated into CLI, Commands, and Logger components
- **CMake Build**: Cross-platform support with debug/release configurations

## Installation

### Prerequisites
- C++17 compatible compiler (GCC, Clang, MSVC)
- CMake 3.12+

### Build Instructions
```bash
git clone https://github.com/caiocruz/cli-tool.git
cd cli-tool
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

# Usage
## Show version
``` bash 
./app/cli-tool -v 
[10:21:38] [debug] Welcome to CliTool v0.0.1
```


## Show help
``` bash
./app/cli-tool -h
cli-tool — Available Commands:
--------------------------------
  --command hello <args>    Print a hello message
  --help                   Show this help message
  --version                Show version
```
## Execute command
``` bash 
./app/cli-tool -c hello
[10:21:48] [debug] running hello world function!
```
# Project Strucuture

´´´ shell
├── app/                  # Main application
│   ├── CMakeLists.txt
│   └── main.cc           # Entry point
├── cmake/                # Build configurations
│   ├── Debug.cmake
│   └── Warnings.cmake
├── lib/                  # Core libraries
│   ├── cli/              # Command-line interface
│   ├── commands/         # Command implementations
│   └── logger/           # Logging system
└── configured/           # Generated configuration
´´´ 

# Development

## Adding New Commands
1. Create command implementation in lib/commands/commands.cc:

``` c++
void new_command(const std::string& args) {
    LOG_DEBUG("Executing new command with args: {}", args);
}
```
2. Register command in lib/cli/cli.cc:

``` c++
options.add_options()
    ("n,new-command", "Description", cxxopts::value<std::string>());
```
Handle execution in app/main.cc:

``` c++
if (result.count("new-command")) {
    new_command(result["new-command"].as<std::string>());
}
``` 

# Building and Packaging as a Debian .deb

This project supports building and packaging into a Debian package using the standard Debian packaging tools.

## Prerequisites

Make sure you have the necessary packages installed for building Debian packages:

```bash
sudo apt-get update
sudo apt-get install build-essential devscripts debhelper dh-make cmake
``` 

## Building the .deb Package

1. Run the Debian package build command from the project root directory:

``` bash
dpkg-buildpackage -us -uc
```
