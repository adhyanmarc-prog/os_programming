# Lab 2 - Task 1: Process Creation and Monitoring

This task displays creating a simple C program (`black.c`) that runs for a certain time using `sleep()`, compiling it with GCC, executing the binary, and inspecting running processes using `ps aux`.


## 1. Source Code (`black.c`)

The program prints a starting message and sleeps for 1 second in a loop that runs 30 times (total runtime of 30 seconds), and then prints a completion message.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("I am starting...\n");
    for(int i = 1; i <= 30; i++) {
        sleep(1);
    }
    printf("I am finished.\n");
    return 0;
}

## 2. Compilation and Execution
Compiling black.c using GCC to get execuitable binary and then execute it.

``` bash
nano black.c

gcc black.c -o black

./black
```
above we created a .c file using nano, then compiled it using gcc into executable binary and ran that executable using ./ .

## Output:
``` plaintext
I am starting...
I am finished.
```

## 3. Process Monitoring
During the run time of the process or after execution the active process can be viewed in the process table using ps aux piped into grep:

``` bash
ps aux | grep black
```

## Process Output Details:
ps aux displays all the running processes in the system.
grep black filter outs the process output for process name black.

