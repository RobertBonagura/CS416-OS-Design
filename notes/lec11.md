3-2-20
# Lecture 11 - 
## Pagetables
### Multi-level Page Tables
Uses a radix tree structure - which allows to dynamically store memory.

Page tables are per process - The process does not share its page table with another process.

Upon process creation, only outer page is created, and inner pages are created as needed.

### Quiz: Multilevel
Outer page is the page directory, which is stored in a page.
* In example, outer bit is 4 bits, which explains why we have 2^4 = 16 different entries.

Each directory points to a physical page in the next directory

Page offset is 12 bits, so the offset is represented by the last 2 hex digits.
* First digit is used for outer page
* Second for inner page
* Last two for page offset.

EXAMPLE 1: Translating 0x01ABC

* Page directory 0 points to 0x3
* Go to 0x3 PT, and grab address PPN 1 from 0x3. This value is 0x23
* Offset ABC by 23 
* We return 0x23ABC

EXAMPLE 2: 0x00000
* Got to 0, which again points to 0x3
* Go to 0 index in 0x3, which is 0x10.
* Offset 000 address by 0x10
* Return 0x1000

### How to choose ratio of bits in outer page, inner page and page offset?
Goal:
1. Each page table fits within a page 
    * PTE size * nunber PTE = page size
        * Assume PTE = 4 bytes
        * Page size 2^12 bytes = 4KB
        * 2^2 butes * number PTE = 2^12 bytes
        * number PTE = 2^10
    * number bits for selecting inner page = 10
    
Remaining bits for outer page:
* 30 - 10 - 12 = 8 bits

In previous example, we choose 4 and 4 and 12 combination because:

we defined page size when we boot system, we need a 4K page table.

#### See Quiz: Address format for multilevel Paging slide

### Problem with 2 levels?
Problem: page directories may not fit in a page

Solution: Split page directories into pieces and add another page directory to refer to the page directory pieces.

