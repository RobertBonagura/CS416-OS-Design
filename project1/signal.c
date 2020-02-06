/* signal.c
 *
 * Group Members Names and NetIDs:
 *   1.
 *   2.
 *
 * ILab Machine Tested on:
 *
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* Part 1 - Step 2 to 4: Do your tricks here
 * Your goal must be to change the stack frame of caller (main function)
 * such that you get to the line after "r2 = *( (int *) 0 )"
 */
void segment_fault_handler(int signum) {

    printf("I am slain!\n");


    /* Implement Code Here */
	// Step 2
	int BAD_INSTRUCTION_LENGTH = 5;
	
	// Step 3 - Address of main IP is 0x7fffffffd6e8
	// Step 4 - Address of signum  is 0x7fffffffd61c
	//		   	There diference is 0xcc or 204 bits
	*(&signum + 204) = *(&signum + 204) + BAD_INSTRUCTION_LENGTH;
	
	// Yusup's solution		   	
	//*(&signum + 47) = *(&signum + 47) + 2;

}

int main(int argc, char *argv[]) {

    int r2 = 0;

    /* Part 1 - Step 1: Registering signal handler */
    /* Implement Code Here */
    signal(SIGSEGV, segment_fault_handler);
    r2 = *( (int *) 0 ); // This will generate segmentation fault

    printf("I live again!\n");

    return 0;
}
