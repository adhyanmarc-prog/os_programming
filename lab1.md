# Task 1: GCC Compilation Pipeline

This document details the step-by-step GCC compilation pipeline for `test.c`.

## Source Code (`test.c`)
```c
# include <stdio.h>

int main(){
    printf("testing this task!!");
    return 0;
}

```

the above given program is the c program that we are going to compile and run.

# Environment Setup
```bash
sudo apt install build-essential

gcc --version
```
through the above given commands we can install build-essential and check its version.

# Compilation Pipeline
```bash
gcc -E test.c -o test.i

gcc -S test.i -o test.s

gcc -c test.s -o test.o

gcc test.o -o test
```
above given are the c program compilation commands.

# Program Execution
```bash
./test
```
through the above given command we can run the test c program file.

