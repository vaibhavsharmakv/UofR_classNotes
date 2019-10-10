#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{ 
    int status; 
    pid_t fork_return; 
 
    fork_return = fork(); 
 
    if (fork_return == 0) /* child process */ 
    { 
      printf("\n I'm the child!"); 
      exit(0); 
    } 
    else if (fork_return > 0)/* parent process */ 
    { 
      wait(&status); 
      printf("\n I'm the parent!"); 
      if (WIFEXITED(status))
          printf("\n Child returned: %d\n", WEXITSTATUS(status));
    } 
    else
    {
      printf("Error\n");
    }
    
}
