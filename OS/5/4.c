#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 

int main(){
struct stat info;
char* filename = "a.txt";

if(stat(filename, &info) == 0)
{
    char *buf;
    buf=(char *)malloc(10*sizeof(char));
    buf=getlogin();
    printf("\n User Name: %s \n",buf);

    printf("Owner ID: %d",info.st_uid);
    struct passwd *pw = getpwuid(info.st_uid);
    struct group  *gr = getgrgid(info.st_gid);
    printf("\nOwner name : %s\n",pw->pw_name);
    printf("Owner Group name : %s\n",gr->gr_name);

    if (!strcmp(pw->pw_name,buf))
    {
        unlink(filename);  
        printf("\nFile removed");
    }
}
else 
{
    printf("Error opening file information");
}
}