1-23-20
# Introduction

Questions answered in this lecture:
* What will you do in this course?
* What is an OS and why do you want one?
* Why study operating systems?

---

## What is an Operating System?
**Operating System (OS)** - Software that converts hardware into a useful form for applications.

## Why study Operating Systems?
To build, modify, or adminsiter an operating system.
To Understand system performance.
* Behavior of OS impacts entire machine.
* To tune workload performance.
* To apply knowledge across many layers. (Comp Arch, programming languages, data structures and algorithms, and performance modleing)

## What does the OS provide?

**Role 1: Abstraction** - Provide standard library for resources.<br>
* Abstraction is provided for each resource.
* **resource** - Anything valuable (e.g., CPU, memory, disk)
### What abstraction does a modern OS typically provide for each resource?
* CPU: process and/or thread
* Memory: address space
* Disk: file

Allows for applications to reuse common facilities, to make different devices look the same and to provide a higher-level/ more useful functionality.

Some challenges include how to make correct abstractions and how much of hardware should be exposed to OS.

### System Calls
Allows user to tell OS what to do. Typically through the use of some interface (API, standard library).

A typical OS exports a few hundred system calls. This is how the OS is able to run programs, access memory, and access devices.

**Role 2: Resource Management** - How the OS is able to share resources well.

Advantages of OS providing resource management
* Protect applications from one another.
* Provide efficient access to resources. (cost, time, energy)
* Provide fair access to resources.

Some challenges include asking what are the correct mechanisms and polices?

---

The OS can be divided into Three Easy Pieces.
1. Virtualization
2. Concurrency
3. Persistance

## Virtualization
Make each application believe it has each resource to itself, and that it is interacting with the actual physical representation of said resource.

## Virtualizing the CPU
* There are a very large number of virtual CPUs, such that a single CPU can turn into a seemingly infinite number of CPUs
* This allows many programs to seemingly run at once.

## Virtualizing Memory
* Physical memory is simply an array of bytes.
* A program keeps all of its data structures in memory, and is able to Read (load) and Write (store) memory by specifying the appropriate address.
* Each process within the CPU has its own private virtual address space.
    * Running two identical processes simultaneously and printing the address space used exposes this fact - that the address space used by the process is not the actual address space in memory.
* The OS maps this virtual address space onto the actual physical memory.

## Concurrency
The OS must be able to handle events occuring simultaneously that may interact with one another.

The threads demo shows an example of how without providing abstractions for handling concurrency (such as locks, semaphores), a concurrency issue might provide inaccuracy.

## Persistance

In order for the OS to write to disk, it must:
* Figure out where on the disk the new data will reside.
* Issue I/O requests to the underlying storage device.
* Have file system handle system crashes during write.
