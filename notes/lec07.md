2-13-20
# Lecture 7 - 

## Multiprogramming Goals:
Transparency
* Processes are neot aware that memory is shared.
* Works regardless of number and/or location of processes.

Protection
* Cannot corrupt OS or othre process
* Privacy: Cannot read datea of other Process 

Efficiency
* Fo not waste resources (minimize fragmentation)

Sharing
* 

## Abstraction: Address Space
Includes static and dynamic content

### Motivation for dynamic memory

### Heap Organization
Quiz: What gets stored in static data, code, stack heap<br>
Quiz: Memory Access<br>

## How to Virtualize Memory?
How to run multiple processes simultaneously?<br>
Addresses are *hardcoded* into process binaries.

How to avoid collisions<br>
Solutions:
1. Time Sharing
2. Static Relocation
3. Base
4. Base + Bounds
5. Segmentation

### 1) Time Sharing Memory
GPU's use concept of timesharing<br>

Problem is that....

### 2) Static Relocation
OS rewrites each program before loading it as a process in memory.

Each rewrite for different process uses different addresses and pointers.

Change jumps, loads of static data

Basically rewriting program in two differnt locations in memory - allowing mulitiple processes.
* Issue here is that if stack A grows, it can interere with stack B.

In gerenral, static relocation is difficult because the program itself allocates memory dynamically.
* It wpuld be no problem if programs only allocated memory statically, but that is not the case.

### 3) Dynamic Relocation
Present in all processes today by Memory Management Unit.

MMU dynamically changes process address at every memory address.
* Process generates *logical* or *virtual* addresses
* Memory hardware uses *physical* or *real* addresses

#### Hardware support for Dynamic Relocation
Two operatingmdoes:
* Prielaged (protected, kernel) mode: OS runs
    * When enter OS Itrap, system calls, uinterrutps, exceptions
    * allows certain instructions to be executed.
        * Can manipulate contents of MMU
    * **Allows OS to access all of physical memory** - (Think about using Amazons virtual machines)
 * USer mode: User processes run
    * Perform translation of logical address to physical address

Minimal MMU contains base register...

#### Implementaiton of Dynamic Relocations: BASE REG
Translation on every memory access of user process
* Memory adds base register to logical address to form phsyical address

We want the base register incrementor however to increment based on the size of the space that the program needs... Something to define the bounds.

Hardware translates the address<br>
OS <something> the base register (increments)

### 4) Dynamic with Base + Bounds
#### Implementation fo BASE+BOUNDS
Translation of every memory access of user process
* MMU computes logical address to bounds register
    * If logical address is greater, then generate error
* MMU adds base register to logical address to form physical address

How do we set program bounds?<br>
When we use malloc() or allocate memory, OS is responsible for incerasing bounds as process grows.

#### Managing Processes with Base and Bounds
Context-Switch
* Add base and bounds registers to PCB
* Steps
    * Change to privelaged mode
    * Save base and bounds registers to old process
    * Load base and bounds registers of new process
    * Change to user mode and jump to new process

#### BAse and Bounds Advantages and Disadvantages
Disadantages:<br>
Must be allocated continuously in memory.

No partial sharing. Cannot share limited parts of address space.

We need to find a way so that process does not need to be continuous

### 5) Segmentation
Divide address sapace into logical segments
* Each segment corresponds to logical entity in address space
    * code, stack, heap

Each segment can independently:
* be placed seperately in physical memory
* grow and shrink
* be protecteed (Seperate read/write/execute protection bits)

#### Segment Addressing
Process now specified segment and offset witin segment

How does process designate a particular segment?
* Use part of logical address
    * Topn bits of logical address eledxe....
    * lower bits of .....

#### Segmentation Implementation
MMU contains Segment Table (per process)
    * Each segment has own base and bounds, protectin bits

So Code, Heap, and STack will each have their own base and bounds and registers. The assumption is that each of these segments must be physically continuous (later or we will drop this assumption as well)

