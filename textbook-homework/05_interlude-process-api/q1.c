#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[]){

    // Question 1
    int x = 10;
    int* ptr = &x;
    *ptr = 100;
    int pid = fork();
    if (pid == 0){
        printf("Child: x is %d\n", x);
        (*ptr)++;
        printf("Child increased the value, it is now %d\n", x);
    } else if (pid > 0) {
        printf("Parent: x is %d\n", x);
        (*ptr)++;
        printf("Parent increased the value, it is now %d\n", x);
    }  

    // Question 2
    return 1;
}