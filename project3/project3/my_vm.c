#include "my_vm.h"

void* p_mem;
char* p_bitmap;
char* v_bitmap;
int p_numpages;
int v_numpages;
void* page_directory;

/*
Function responsible for allocating and setting your physical memory 
*/
void set_physical_mem() {

    //Allocate physical memory using mmap or malloc; this is the total size of
    //your memory you are simulating
    p_mem = malloc(sizeof(char) * MEMSIZE);
    if (p_mem == NULL){
        perror("Failed to set physical memory\n");
        exit(1);
    }
    memset(p_mem, 0, sizeof(char) * MEMSIZE);
    
    //HINT: Also calculate the number of physical and virtual pages and allocate
    //virtual and physical bitmaps and initialize them
    
    //Calculate number of physical and virtual pages
    p_numpages = MEMSIZE / PGSIZE;
    v_numpages = MAX_MEMSIZE / PGSIZE;
    printf("I have %d physical pages and %d virtual pages\n", p_numpages, v_numpages);

    //Calculate number of bits, and then bytes needed for bit map
    int p_bits_needed = log2(p_numpages); 
    int v_bits_needed = log2(v_numpages);
    printf("I need %d and %d bits respectiely\n", p_bits_needed, v_bits_needed);

    int p_bytes_needed = p_bits_needed / 8 + ((p_bits_needed % 8 > 0) ? 1 : 0);
    int v_bytes_needed = v_bits_needed / 8 + ((v_bits_needed % 8 > 0) ? 1 : 0);
    printf("Therefore, I need %d and %d bytes\n", p_bytes_needed, v_bytes_needed);

    // Initialize bitmaps to all zero
    p_bitmap = malloc(sizeof(char) * p_bytes_needed);
    v_bitmap = malloc(sizeof(char) * v_bytes_needed);
    if (p_bitmap ==  NULL || v_bitmap == NULL){
        perror("Failed to set bitmap\n");
        exit(1);
    }
    memset(p_bitmap, 0, sizeof(char) * p_bytes_needed);
    memset(v_bitmap, 0, sizeof(char) * v_bytes_needed);
    return;
}


/*
 * Part 2: Add a virtual to physical page translation to the TLB.
 * Feel free to extend the function arguments or return type.
 */
int
add_TLB(void *va, void *pa)
{

    /*Part 2 HINT: Add a virtual to physical page translation to the TLB */

    return -1;
}


/*
 * Part 2: Check TLB for a valid translation.
 * Returns the physical page address.
 * Feel free to extend this function and change the return type.
 */
pte_t *
check_TLB(void *va) {

    /* Part 2: TLB lookup code here */

}


/*
 * Part 2: Print TLB miss rate.
 * Feel free to extend the function arguments or return type.
 */
void
print_TLB_missrate()
{
    double miss_rate = 0;	

    /*Part 2 Code here to calculate and print the TLB miss rate*/




    fprintf(stderr, "TLB miss rate %lf \n", miss_rate);
}



/*
The function takes a virtual address and page directories starting address and
performs translation to return the physical address
*/
//(David says you can treat this like void* pointer)
pte_t *translate(pde_t *pgdir, void *va) {
    /* Part 1 HINT: Get the Page directory index (1st level) Then get the
    * 2nd-level-page table index using the virtual address.  Using the page
    * directory index and page table index get the physical address.
    *
    * Part 2 HINT: Check the TLB before performing the translation. If
    * translation exists, then you can return physical address from the TLB.
    */

   //Get the page directory index

   //Get the page table index using the virtual address

   //Get the physical address

    //If translation not successfull
    return NULL; 
}


/*
The function takes a page directory address, virtual address, physical address
as an argument, and sets a page table entry. This function will walk the page
directory to see if there is an existing mapping for a virtual address. If the
virtual address is not present, then a new entry will be added
*/
int
page_map(pde_t *pgdir, void *va, void *pa)
{

    /*HINT: Similar to translate(), find the page directory (1st level)
    and page table (2nd-level) indices. If no mapping exists, set the
    virtual to physical mapping */

    return -1;
}


/*Function that gets the next available page
*/
void *get_next_avail(int num_pages) {
 
    //Use virtual address bitmap to find the next free page
}


/* Function responsible for allocating pages
and used by the benchmark
*/
void *a_malloc(unsigned int num_bytes) {

    /* 
     * HINT: If the physical memory is not yet initialized, then allocate and initialize.
     */
    if (!p_mem){
        set_physical_mem();
    }

   /* 
    * HINT: If the page directory is not initialized, then initialize the
    * page directory. Next, using get_next_avail(), check if there are free pages. If
    * free pages are available, set the bitmaps and map a new page. Note, you will 
    * have to mark which physical pages are used. 
    */
   if (!page_directory){
       init_pagedir();
   }

    return NULL;
}

/* Responsible for releasing one or more memory pages using virtual address (va)
*/
void a_free(void *va, int size) {

    /* Part 1: Free the page table entries starting from this virtual address
     * (va). Also mark the pages free in the bitmap. Perform free only if the 
     * memory from "va" to va+size is valid.
     *
     * Part 2: Also, remove the translation from the TLB
     */
     
    
}


/* The function copies data pointed by "val" to physical
 * memory pages using virtual address (va)
*/
void put_value(void *va, void *val, int size) {

    /* HINT: Using the virtual address and translate(), find the physical page. Copy
     * the contents of "val" to a physical page. NOTE: The "size" value can be larger 
     * than one page. Therefore, you may have to find multiple pages using translate()
     * function.
     */




}


/*Given a virtual address, this function copies the contents of the page to val*/
void get_value(void *va, void *val, int size) {

    /* HINT: put the values pointed to by "va" inside the physical memory at given
    * "val" address. Assume you can access "val" directly by derefencing them.
    */




}



/*
This function receives two matrices mat1 and mat2 as an argument with size
argument representing the number of rows and columns. After performing matrix
multiplication, copy the result to answer.
*/
void mat_mult(void *mat1, void *mat2, int size, void *answer) {

    /* Hint: You will index as [i * size + j] where  "i, j" are the indices of the
     * matrix accessed. Similar to the code in test.c, you will use get_value() to
     * load each element and perform multiplication. Take a look at test.c! In addition to 
     * getting the values from two matrices, you will perform multiplication and 
     * store the result to the "answer array"
     */

       
}

/* Helper Functions */
void init_pagedir(){
    return;
}

