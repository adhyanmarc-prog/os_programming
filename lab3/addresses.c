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
