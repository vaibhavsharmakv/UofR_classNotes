#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
	int status;

        pid_t fork_return;

	//char * myargv[]={(char *)"/bin/date",(char *)"date",NULL};
	char * myargv[]={(char *)"/bin/cp",(char *)"cp",(char *)"-",(char *)"hello2.cpp",NULL};
       
        fork_return = fork();

	if (fork_return == 0)
		//execl("/bin/date","date",NULL);//works
		//execl("date","date",NULL);//doesn't work
		//execlp("date","date",NULL);//works
                execv(myargv[0],&myargv[1]); 
		
	else if (fork_return > 0)
        {
		wait(&status);	
		printf("In the PARENT process\n");
        }
	else
        {
		printf("Error\n");
        }
	return 0;
}

// execv - vectory array of C strings
// execl - list - pointed to null
// Need the path and the name of the command as well. then null at the end 
// execlp - takes in file rather than path - exampple -> ls ls 
//   two things to rememebr 
//     - duplicating the command
//     - using null terminator
