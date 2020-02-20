2-20-20
Reading through chapters 20
# Lecture 9 - Virtualizing Memory: Smaller Page Tables

Pages allows to no longer need to heave different address spae segmetns physically connected.

Logical address maps to a physical address.
## Translation of Page Addresses
* Given 12 bit page offset, we should know the page size is 2^12 bytes.
* High order buts give page number

### Quiz: Address Format
Page Size -- Low Bits:Offset -- Virt Addr bits --- High bits (vpn)
1. 16 bytes = 4  -- 10  = 6
2. 1KB = 10  --  20 = 10
3. 1MB = 20 --
4. 512 bytes = 9
5. 4KB = 12

look at slide to finish 

### Where are Pagetables stored?
Pagetables reside in RAM

How big?
* Assume 32-bit address space
* Assume 4 KB pages
* Assume 4 byte entries

Answer is number of entries * size of entry

2 ^ (32 - log(4KB)) * 4 = 4 MB
* Num entries = num virtual pages = 2^(bits for vpn)
* Bits for vpn = 32 - number of bits for page offset = 32 - log(4KB) = 32 -12 = 20
* Num entries = 2^20 = 1 MB
* PAge table size = Num entries * 4 bytes = 4 MB

Clearly this design is not sufficient, not scalable.

On a 64 bit machine, a single page table would consists of 2^52 entries.

CPU does translation, OS tells CPU where translation table is.

### What other info is in pagetable entries besides translation?
* valid bit
* protection bits
* present bit (needed later)
* reference bit (need later)
* dirty bit (needed later)

### Memory Accesses with Pages

