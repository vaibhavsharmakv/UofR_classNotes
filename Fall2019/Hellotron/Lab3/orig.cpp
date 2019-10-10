#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (void)
{
        pid_t fork_return;
       
        fork_return = fork();
	if (fork_return == 0)
		printf("In the CHILD process\n");
	else if (fork_return > 0)
		printf("In the PARENT process\n");
        else
		printf("Error Forking\n");
	return 0;
}

