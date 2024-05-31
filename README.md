# Get_Next_Line Project

## Overview
The get_next_line project is an essential exercise for programming students to learn about static variables, file descriptors, and dynamic memory allocation. The goal is to write a function that reads a line from a file descriptor.

## Objective
The objective is to create a function called `get_next_line` that returns a line read from a file descriptor. This function should be able to read from a file, the standard input, or even later from a network connection.

## Features
- The function will manage multiple file descriptors.
- It will handle reading from various sources seamlessly.
- The project focuses on memory management and efficiency.

## Usage
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 *.c -o get_next_line
./get_next_line [file_to_read]
```
## mplementation Details
The function prototype is char *get_next_line(int fd);.
The BUFFER_SIZE will be defined during compilation and used as the buffer size for read calls.
The function will return the line that has just been read or NULL if there is nothing else to read or an error occurred.

## Bonus Part
The bonus part includes handling multiple file descriptors with a single static variable.
It also includes managing the memory more efficiently by using only one static variable.

## Author
[hamza chadili]
