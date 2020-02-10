#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char* argv[]){

    // Question 4 
    int pid = fork();
    if (pid == 0){
        exec("/bin/ls");
    } else if (pid > 0) {
        int fd = open("question2.txt", O_RDONLY);
        read(fd, NULL, 100);
        close(fd);
    }  
    return 1;
}