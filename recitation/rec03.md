2-6-20
# Recitation 3

## For project 1

### Part 1:
We have variables on the stack. how can we modify stack so that the instruction pointer moves to next statement of main funciton.

Goal: Access instruciton pointer for main function from within seg_handler function.

Need to inspect stack with GDB to find where this IP is.


### Part 2:
Goal is for two threads to work together to increment counter to 100.

Need to incorporate mutex to ensure mutual exclusion.

### Part 3:
Goal to measure time it takes to context switch.

## Register and Stack Review

[CPU]

load values from mem or CPU into registers in CPU

[Memory]

---

on 32-bit registers are

eax, ebx, ecx

---
on 64

rax, rbx, rcx

ax is lower 16 bit<br>
eax is lower 32<br>
rax is whole 32 bit register

---
Main important registers<br>
rax - return value<br>
rbp - base of stack<br>
rsp - top of stack<br>
rip - instruciton pointer<br>

---
[Stack]

[Heap]

[data]

[text]

---
stack for 32
```
int main() {
    int x = 1;
        y = 2;
        z = 3;
    foo(4, 5, 6);
}

int foo(a, b, c){

}
```
[x=1]<br>
[y=2]<br>
[z=3]<br>

---
32-bit
* push arguments right to left.
* push eip
* push ebp
* push 6, 5, 4, 
---
64-bit
* isntead of pushing args into stack, we will push them into registers (first six, rest into stack)
* push rip
* push rbp
* now increment rbp and rsp to stack frame of foo
* Then unloads arguments from foo and loads them onto stack


## GDB Review
rip is current instruciton, saved rip is saved instruction of the caller frame.

saved registers is address of base and instruciton pointer of prevous frame.

We can print out what is in these registers to confirm. Frame base pointer shoul typically contain argument lists.

