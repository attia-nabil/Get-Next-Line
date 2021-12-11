# get_next_line
Get_next_line (42cursus) 2021-2022

- Actual Status : finished.
- Result        : 125%
- Observations  : (NULL).

![Capture](https://user-images.githubusercontent.com/78090806/145683425-21a041c2-29e2-4fdf-abf6-4d46fd448746.PNG)

In this project i created a function called `get_next_line` wich allow you to read content line by line from a file descriptor (whether a file, standard input, or even later a network connection). Calling it in a loop will read one line at a time until the end of the text.

## Pseudo code flowchart:
![](resources/images/gnl_flowchart_pseudo.png)

## Source code flowchart:
![](resources/images/gnl_flowchart_source.png)

## Key points:

* Functions `open`, `read`, `close` and buff size adaptation.
* Utilization of temporal variables.
* Static variables.
* Proper allocation and destruction of heap memory.
* Managing multiple file descriptors.

## Objectives:

* Filedescriptors. 
* Buffering.
* Basic parsing. 

## Skills:

* Imperative programming.
* Rigor.
* Algorithms & AI.

## Compilation ('get_next_line' directory):

`make all` | First time compilation.

`make fclean` | Delete files generated from compilation.

`make re` | Delete files generated from compilation and recompile.

## Returning values:

`1` | Line read.

`0` | No read, end of file.

`-1` | Error.

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

This is my get_next_line project from the 42 cursus (1337),
need help:
nattia@student.1337.ma
