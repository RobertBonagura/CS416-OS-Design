/* syscall.c
 *
 * Group Members Names and NetIDs:
 *   1.
 *   2.
 *
 * ILab Machine Tested on:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/syscall.h>

double avg_time = 0;

int main(int argc, char *argv[]) {

    /* Implement Code Here */
	
    // Remember to place your final calculated average time
    // per system call into the avg_time variable
    
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	int i = 0;
	while (i < 5000000){
		syscall(SYS_getuid);
		i++;
	}
	gettimeofday(&end, NULL);
	
	float total_time = (end.tv_sec * 1000000 + end.tv_usec) -
		(start.tv_sec * 1000000 + start.tv_usec);
	
	float avg_time = total_time / 5000000;

	printf("Average time per system call is %1.4f microseconds\n", avg_time);

    return 0;
}
