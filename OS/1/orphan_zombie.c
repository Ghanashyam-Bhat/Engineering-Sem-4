//1. Write a program to demonstrate orphan or zombie process
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//Zombie Process
int main()
{
    pid_t pid = fork(); 
    if (pid<0)
    {
        printf("Fork Failure\n");
        exit(1);
    }
    else if (pid > 0)
    {
        printf("id of parent= %d\n",getpid());
        sleep(10);
    }
    else
    {
        printf("id of parent = %d , id of child = %d\n",getppid(),getpid());
        sleep(1);
        exit(0);
    }         
    return 0;
}
//ps-s