2-17-20
# Lecture 8 - Virtual Memory: Paging
(ch 18)<br>
## Review: Match Description
review this slide<br>
Segmentation Review
* How to choose number of high roder bits? based on nnumber of segments you have.
    * If you have one or two segments, you can use 1 bit. If you have 4 segmetns you only need 2  bits.
* Where does segment table live? Who does this implementation?
    * The hardware does this translation (in the processor)
    * it is responsibility of OS to load these registers so that the processor can look at the registers and do the translation

A problem is **fragmentation** - How did myMalloc handle this?

It is responisiblity of OS to load context into MMU of CPU.

## Problems with fragmentation?
definition: free memory that cant be usefully allocated

Two types:
1. External: Visible to allocator
    * My initial impression of fragmentation
2. Internal: Visible to requester
    * Inside a segment of memory (Created by malloc()), only using a small percentage of what was originally allcoated - and so there is unused memory.

## Paging
Goal: Eliminate requirement that address space is continuous
* eliminate externam gragmentaiton
* grow saegments as needed

Idead: Dividie address aoce and phsycial memory into fized sized pages
* size 2^n, example 4KB (in most systtems, page is really small)
* Physical page: page frame

It basically divides the notion of segments as previpously discussed into smaller parts called pages.

## Translation of PAge addresses
How to translate lofical address to phsysical address
* High order bits of address designate page number
* Low order bits of address desginate offset within page

## Quiz: Address Format

## Virtual to Physical Page Mapping
Higher order bits are known at the VPN (virtual page number).

Number of bits in virtual address does not need to equal number of bits in physical address format.

### How should OS translate vpn into some phsical address? 
For paging, OS need a more genereal mapping mechanism than what was used for segmentations (phys_addres = virt_offset + bas_reg)

### The Mapping
Programs can have the same virtual address, however theya re never mapped to the same physical address.
 
### Where are PAgetables stored (take notes on this slide)
How big is the typical page table?
* It is the number of maximum virutal pages that a process can get.
    * So in a 32-bit system, if its a 4KB page, and 12 bits are dedicated to offset and 20 bits are dedicated to page number, then there are 1,000,000 possible pages
* Final answer:<br> 2 ^ (32 - log(4KB)) * 4 = 4MB<br> 
                2 ^ ( 20) * 4 = 4MB
