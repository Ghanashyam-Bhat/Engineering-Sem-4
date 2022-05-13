#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int fd[2],count = 1; pipe(fd);
    pid_t childpid = fork();
    FILE *fp;  
    char buffer[100],readbuffer[100];

    if (childpid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (childpid > 0) //Parent Process
    {
        printf("PID of parent %d\n", getpid());
        close(fd[0]);
        fp = fopen("input.txt", "r");
        fgets(buffer,100,fp);
        write(fd[1], buffer, (strlen(buffer) + 1));
        close(fd[1]);
    }
    else //Child Process
    {
        printf("PID of child %d\n", getpid());
        printf("PID of parent %d\n", getppid());

        close(fd[1]);
        read(fd[0], readbuffer, sizeof(readbuffer));
        for(int i=0;readbuffer[i];i++)
        {
            if(readbuffer[i]==' ')
                count++;
        }
        printf("Word count: %d\n", count);
        close(fd[0]);
    }
}