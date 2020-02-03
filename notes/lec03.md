1-30-20
# Virtualization: The CPU (continued)

Important registers:
* esp - stack pointer register
* ebx - base pointer register

----
## Stack Detour
### Current Stack Frame ("Top" to Bottom)
* "Argument build" area (paramaters for function about to be called)
* Local variables (if cant be kept in registers)
* Saves register context (when reusing registers)
* Old frame pointer (for caller) 

### Caller's Stack Frame
* Return address (pushed by `call` incstuction)
* Arguments for this call

`swap` function.<br>
See the disasembled code of this operation on slide.<br>
It is broken into 3 phases:
1. Setup phase - take the arg given by caller, move to stack, set return address,
2.  execute the actual swap logic.
3. Finish 

### Setup phase
Base pointer ponts to top of stack, stack pointer points to the lower address.
Swap Setup #1
```
swap:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
```
Swap Setup #2
```
swap:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
```
Swap Setup #3
```
swap:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
```

Swap Body<br>
Finish #1<br>
Finish #2<br>
Finish #3<br>

---

latency for accessing memory: 100 - 150 clock cycles <br>
load or store : 60 - 100 ns<br>
Accessing 1 byte from hard disk: 2 - 5 ms<br>
Accessing 1 byte from SSD: 50 - 100 micros<br>