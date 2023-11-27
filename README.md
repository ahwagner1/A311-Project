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

#### Regular Stack Runtimes (in microseconds):
- [552, 1117, 779, 675, 941]
- Average runtime: 813
  
#### Shadow Stack Runtimes (in microseconds):
- [593, 628, 645, 665, 557]
- Average runtime: 618

#### Shadow Stack (Linked List) Runtimes (in microseconds):
- [631, 309, 340, 352, 343]
- Average Runtime: 395
