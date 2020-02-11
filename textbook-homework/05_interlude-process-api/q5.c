#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main (int argc, char* argv[]){

    // Question 5 
    int pid = fork();
    if (pid == 0){
        printf("Child here (%d)\n", getpid());
        int something = wait(NULL);
        printf("something is %d\n", something);
    } else if (pid > 0) {
        printf("Parent here (%d)\n", getpid());
        int somethingElse = wait(NULL);
        printf("something else is %d\n", somethingElse);
    }  
    return 1;
}