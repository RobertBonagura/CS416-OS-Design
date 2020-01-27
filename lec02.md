1-27-20
# Virtualization: The CPU
Questions answered in this lecture:
* What is a process?
* Why is limited direct execition a good apporach for virtualizing the CPU
* 
* What 3 modes can a process work in?

## What is a process?
An execution stream in the context of a process state. <br>
<br>
What is an **exection stream**?
* Stream of executing instructions
* Running piece of code
* "thread control"

What is **process state**?
* Everything that the running code can afect or be affected by
* Registers
    * General purpose, floating point, status, program counter, stack pointer
    * program counter is like a global variable for everything in that CPU, keeping track of where that process is
    * stack pointer tells exactly in which part of the stack you are *clarify between this and program counter*
* Address space
    * Heap, stack and code
* Open files

## Processes vs Programs
A process is different than a program
* Program: static code and static data.
* Process: Dynamic instance of code data.

Can have multiple process instances of the same program.<br>

## Processes vs Threads
Thread: A "lightweight" abstraction of a process 
* An execiution stream that shares an address space
* Multiple threads within a single process
* Each will have their own stacks and heap, though share address space so could potentially access each others stacks.

## Process Memory Segment
Write each part
"Stack gets released once the program returns" what does this mean exactly.

## Virtualizing the CPU
**Goal**: Give each process impression it alone is actively using CPU.<br>
Resouces can be shrared in time and space.<br>
Assume single uniprocessor - you use timseharing.<br>
Memory and Disk? - you use space sharing.<br>

## How to Provide Good CPU Performance?
**Direct execution**
* Allow user process to run directly on hardware.
* OS creates process and transfers control to starting point. (i.e., main())

Problems with direct execution?
* Process could do somethin restricted - for example could read/write other process data. (disk or memory - Think about writing while true malloc an create files)
* PRocess could run forever
* something else

Solution - **Limited Direct execution**.

## Problem 1: Restricted OPS
How can we ensure user process cant harm others?<br>
Solution: privelage levels supported by hardware (bit of status)
* User processes run in user mode (restriucted mode)
* OS runs in kernel mode (not restricted)
    * Instructions for interactuing with devices
    * could have many privelage levels (Advanced levels)

How can process access device?
* System calls (Gateway to interact with OS, and get the OS to implement a function call)
    * Interface between Application to Kernel to switch program from untrusted to trusted
    * System calls are implemented within the OS, in the kernel. Can not be implemented within an application.
* Change privelage level through system call (trap)

*Look through System Call slides*<br>
[int $64 is an interrupt to indicating RAM is receving a system call. Note this example only looked at read, not any of its paramaters]

### What to limit?
USer processes are not allowed to perform
* General memory access
*D Disk I/O
* Sepcial x86 instructions like 'lidt'

What if process tries to do something restricted?

## Problem 2: How to take CPU away?
How does it do multitasking?<br>
OS requirements for **multiprogramming** or multitasking.
* Mechanism - to switch between processes
* Policy - To decide which process to schedule when

Seperation of policy and mechanism
* Reoccuring theme in OS
* **Policy**: Decision-maker to optimize some workload performance metric
    * Which process when?
    * Process scheduler: Future lecture
* **Mechanism**: Low-level code that implements the decision.
    * How?
    * Process Dispatcher: Todays lecture

### Dispatch Mechanism
OS runs dispatch loop, uses a **Context-swtich**.
* Question 1: How does dispatcher gain control?
* Question 2: What exection context must be saged and restored?

## How does Dispatcher gain control?
Option 1: **Cooperative Multi-tasking** (older)
* Trust process to relinquish CPU to OS through traps
    * Examples: system call, page fault (Access page not in memory) or error (illegal instruction or divide by zero).
    * Provide special yield() system call
    
Doesnt really work because programs do not want to yield - partially the point of virtualization - programs want everything.

Look up disadvantages

Option 2: **True Multi-Tasking**
* Guarantee OS can obtain control periodically
* Enter OS by enabling peridoic alarm clock
    * Hardware generates timer interrupt (CPU or seperate chip)
    * Example: every 10ms
* User must not be able to mask timer interrupt
* Dispatcher counts interrupts between context switches
    * Example: waiting 20 timer ticks gives 200ms time slice
    * Comon time slices range between 10ms and 200ms

## What context must be saved?
Dispatcher must track context of process when not running
* Save context in **process control block (PCB)**
* PCS is a structure maintained for each process in the OS

What information is in stored in PCB?
* PID
* Process state (I.e., running, ready or blocked)
* Execution state (all registers, PC, stack, ptr) -- context
* Scheduling priority (will dive into more deeply later)
* Accounting information (parent and child processes)
* Credentials (which resources can be accessed, owner)
* Pointers to other allocated resources (e.g., open files)

Requires special hardware support

### What's inside a PCB?
see attached code
kernel stack cotains functions that only the kernel can access
### How Context is saved
