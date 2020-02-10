#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char* argv[]){

    // Question 2
    int fd = open("question2.txt", O_RDWR | O_CREAT | O_APPEND, S_IWUSR);

    int pid = fork();
    if (pid == 0){
        write(fd, "Testing from child.\n", 30);
    } else if (pid > 0) {
        write(fd, "Testing from parent.\n", 20);
    }
    return 1;
}