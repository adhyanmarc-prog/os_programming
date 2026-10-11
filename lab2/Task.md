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

---

# Lab 2 - Task 2: Process Identifiers (PID and PPID)

This task shows how we can retrieve and inspect process identifiers in C using `getpid()` and `getppid()`, compile the program (`sugar.c`), run it in the background, and inspect its PID/PPID status from the terminal.

---

## 1. Source Code (`sugar.c`)

The program retrieves its own Process ID (PID) and Parent Process ID (PPID) using Linux system calls defined in `<unistd.h>`, prints them, and sleeps for 20 seconds.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("My PID is: %d\n", getpid());
    printf("My Parent PID is: %d\n", getppid());
    printf("Sleeping for 20 seconds...\n");
    sleep(20);
    return 0;
}
```

## 2. Compilation and Execution

compile the .c file using GCC and running the execuitable file.

``` bash
nano sugar.c

gcc sugar.c -o sugar

./sugar
```

## Sample Terminal Output:

``` plaintext

My PID is: 1100
My Parent PID is: 337
Sleeping for 20 seconds...
```

## 3. Process Inspection
We can use the PID that we got from the program output to verify the process attributes with the help of ps command.

``` bash
ps -p 1100 -o pid,ppid,cmd
```

## Context:
`getpid()`: It returns the process ID which is assigned by th OS kernel to the running program.

`getppid()`: It returns the Parent Process ID. 

`ps -p <PID> -o pid,ppid,cmd`: It displays the specific process attributes like PID, PPID and Command Name for the process verification.
