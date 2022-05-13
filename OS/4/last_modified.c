#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef HAVE_ST_BIRTHTIME
#define birthtime(x) x.st_birthtime
#else
#define birthtime(x) x.st_ctime
#endif

int getMonth(char* month)
{
	if(strcmp(month, "Jan") == 0)
		return 1;
	else if(strcmp(month, "Feb") == 0)
		return 2;
	else if(strcmp(month, "Mar") == 0)
		return 3;
	else if(strcmp(month, "Apr") == 0)
		return 4;
	else if(strcmp(month, "May") == 0)
		return 5;
	else if(strcmp(month, "Jun") == 0)
		return 6;
	else if(strcmp(month, "Jul") == 0)
		return 7;
	else if(strcmp(month, "Aug") == 0)
		return 8;
	else if(strcmp(month, "Sep") == 0)
		return 9;
	else if(strcmp(month, "Oct") == 0)
		return 10;
	else if(strcmp(month, "Nov") == 0)
		return 11;
	else if(strcmp(month, "Dec") == 0)
		return 12;
}

int compare(int a_day, int a_month, int a_year, int day, int month, int year)
{
	//printf("Given Date: %d/%d/%d\n",a_day,a_month,a_year);
	//printf("Last modified file date: %d/%d/%d\n",day,month,year);
	if((a_year<=year) && (a_month <= month) && (a_day<=day))
		return 1;
	else
		return 0;
}

int main(int argc, char** argv)
{
	struct dirent *de;
	struct tm* foo;
	int day;
	int month;int year;
	char* path = argv[1];
	DIR *dr = opendir(path);
	char t[ 100 ] = "";
	
	if (dr == NULL)
	{
		printf("Could not open current directory\n" );
		return 0;
	}
	
	struct stat b;
	int x = 1;
	while ((de = readdir(dr)) != NULL)
	{
		char name[1000];
		char file_path[10000];
		strcpy(file_path, path);
		strcpy(name,de->d_name);
		if(!strcmp(name, ".") || !strcmp(name, ".."))
			continue;
			
		strcat(file_path, "/");
		strcat(file_path, name);
		stat(file_path, &b);
		char* token = strtok(ctime(&b.st_mtime), " ");
		
		for(int i = 0; token != NULL; i++)
		{
			token = strtok(NULL, " ");
			switch(i)
			{
				case 1:
					day = atoi(token);
					break;
				case 0:
					month = getMonth(token);
					break;
				case 3:
					year = atoi(token);
					break;
				default:
					break;
			}
		}
		if(compare(atoi(argv[2]), getMonth(argv[3]), atoi(argv[4]), day, month, year))
		{
			
			printf("\n%d.\t%s\t\t\t%s\n", x,name, ctime(&b.st_mtime));
			x++;
		}
		
	}
	closedir(dr);
	return 0;
}
