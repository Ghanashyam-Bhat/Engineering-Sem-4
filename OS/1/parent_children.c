#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
 
int main()
{
    int status;
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    pid_t pid3 = fork();
    pid_t pid4 = fork();

    if(pid1<0 || pid2<0 ||pid3<0 || pid4<0)
    {
        printf("\nFork Failure");
        exit(0);
    }
    else if(pid1>0 && pid2>0 && pid3>0 && pid4>0)
    {
        printf("\nParent id= %d",getpid());
        wait(&status);
    }
    else if(pid1==0 && pid2>0 && pid3>0 && pid4>0)
    {
        printf("\nParent id= %d , child id= %d",getppid(),getpid());
        execl("/sqrt.c","5",NULL);
        exit(0);
    }
    else if(pid1>0 && pid2==0 && pid3>0 && pid4>0)
    {
        printf("\nParent id= %d , child id= %d",getppid(),getpid());
        exit(0);
    }
    else if(pid1>0 && pid2>0 && pid3==0 && pid4>0)
    {
        printf("\nParent id= %d , child id= %d",getppid(),getpid());
        exit(0);
    }
     else if(pid1>0 && pid2>0 && pid3>0 && pid4==0)
    {
        printf("\nParent id= %d , child id= %d",getppid(),getpid());
        exit(0);
    }
}