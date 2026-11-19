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
