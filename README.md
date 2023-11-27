# A311-Project
Tobias Bromirski and Ashton Wagner

This project aims to utilize and test shadow stacks using linked lists instead of the more common method of using an array. 
Source.cpp holds main() and must include stack.h, shadow_stack.h, shadow_stack_LL.h, functional, and chrono to properly work.
To use this code, download the files to your computer and then import them to your IDE of choice that supports compiling c++ code. 


### Hardware and Environment Specifications for Execution Time Measurements
- **Processor (CPU):** Intel Core i7-10700KF, 3.80 GHz
- **Memory (RAM):** 32 GB DDR4
- **Storage:** 1024 GB NVMe SSD.
- **Operating System:** Windows 11
- **Compiler:** cl.exe

## Runtimes of stack implemented using stack.h/.cpp (in microseconds):
- [733, 729, 519, 698, 813]
- Average runtime: 698
## Runtimes of stack implemented using shadow_stack.h/.cpp (in microseconds):
- [301, 406, 349, 454, 594]
- Average runtime: 421
## Runtimes of stack implemented using shadow_stack_LL.h/.cpp (in microseconds):
- [306, 469, 376, 414, 604]
- Average Runtime: 434

