# Lab 3:

This repository contains C programs demonstrating how primitive data types are sized by the compiler/OS and how variables are organized across different segments of a process's virtual address space (Text, Data, BSS, Heap, and Stack).

## 1. Source Code (data_types.c)

Uses sizeof() to inspect memory allocation (in bytes) for primary C data types (char, int, float, double, long, unsigned int, long long, and pointers).#include <stdio.h>

``` c
int main(void) {
    printf("=== Data Type Sizes on This System ===\n\n");

    printf("char:    %zu bytes\n", sizeof(char));
    printf("short:   %zu bytes\n", sizeof(short));
    printf("int:     %zu bytes\n", sizeof(int));
    printf("long:    %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("float:   %zu bytes\n", sizeof(float));
    printf("double:  %zu bytes\n", sizeof(double));
    printf("pointer: %zu bytes\n", sizeof(int*));

    return 0;
}
```

### Compilation and Execution
Compiling sleep_timer.c using GCC to get execuitable binary and then execute it.

``` bash

gcc data_types.c -o data_types

./data_types
```

### Output:

## 2. Source Code (addresses.c)

Demonstrates variable memory addresses across the Data, BSS, Stack, and Heap segments using %p.

``` c
#include <stdio.h>
#include <stdlib.h>

int global_var = 150;
int bss_var;

int main(void) {
    int local_var = 30;
    int *heap_var = malloc(sizeof(int));

    if (heap_var == NULL) {
        perror("malloc failed");
        return 1;
    }
    *heap_var = 75;

    printf("Data segment (global_var) : %p\n", (void *)&global_var);
    printf("BSS segment  (bss_var)    : %p\n", (void *)&bss_var);
    printf("Heap segment (heap_var)   : %p\n", (void *)heap_var);
    printf("Stack segment (local_var) : %p\n", (void *)&local_var);

    free(heap_var);
    return 0;
}
```
### Compilation and Execution
Compiling sleep_timer.c using GCC to get execuitable binary and then execut>

``` bash

gcc addresses.c -o addresses

./addresses
```

### output:


## 3. Source Code (data_types.c)

Maps variables across all segments, compares high vs. low memory addresses, and computes the address gap between the Stack and Heap.

``` c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int global_init = 42;

int global_uninit;

int main() {
    int local_var = 10;
    int *heap_var = (int *)malloc(sizeof(int));
    if (heap_var == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    *heap_var = 99;

    printf("=== Memory Segment Address Mapping ===\n\n");
    printf("Data Segment (Global Initialized)   : %p\n", (void *)&global_init);
    printf("BSS Segment  (Global Uninitialized) : %p\n", (void *)&global_uninit);
    printf("Heap Segment (Dynamically Allocated): %p\n", (void *)heap_var);
    printf("Stack Segment (Local Variable)      : %p\n", (void *)&local_var);

    uintptr_t stack_addr = (uintptr_t)&local_var;
    uintptr_t heap_addr  = (uintptr_t)heap_var;
    uintptr_t diff = (stack_addr > heap_addr) ? (stack_addr - heap_addr) : (heap_addr - stack_addr);

    printf("\n=== Analysis ===\n");
    printf("Address difference (Stack - Heap)   : 0x%lx (%lu bytes)\n", diff, diff);

    free(heap_var);
    return 0;
}
```

### Compilation and Execution
Compiling sleep_timer.c using GCC to get execuitable binary and then execut>

``` bash

gcc memory_mapping.c -o memory_mapping

./memory_mapping
```

### output:
