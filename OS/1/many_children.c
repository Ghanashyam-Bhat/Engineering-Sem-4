//2. Create 4 children process for parent process and assign different task for each children
    //In code there must be atleast 3 exec functions
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    for(int i=0;i<4;i++)
    {
        pid_t pid;
        pid=fork();
        if(pid==0 && i==0)
        {
            printf("\nParent id= %d , child id= %d",getppid(),getpid());
            execlp("/bin/ps","/bin/ps",NULL);
        }
        else if(pid==0 && i==1)
        {
            printf("\nParent id= %d , child id= %d",getppid(),getpid());
            char *const parmList[] = {"/bin/ls",NULL};
            execv("/bin/ls",parmList);
        }
        else if(pid==0 && i==2)
        {
            printf("\nParent id= %d , child id= %d",getppid(),getpid());
            char *bp="/bin/ls";
            execl(bp,bp,NULL);
        }
        else if(pid==0 && i==3)
        {
            printf("\nParent id= %d , child id= %d",getppid(),getpid());
            execlp("/bin/ps","/bin/ps",NULL);
        }
    }
    printf("\nParent id= %d",getpid());
    wait(NULL);
    return 0;
}
