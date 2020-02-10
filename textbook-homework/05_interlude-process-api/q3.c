#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char* argv[]){

    // Question 3 
    // I thought adding in I/O would cause the parent to block
    // and cause the child to execute first. 
    // Have only run on Mac, not yet tested on Linux.
    int pid = fork();
    if (pid == 0){
        printf("Hello\n");
    } else if (pid > 0) {
        int fd = open("question2.txt", O_RDONLY);
        read(fd, NULL, 100);
        close(fd);
        printf("Goodbye\n");
    }  
    return 1;
}