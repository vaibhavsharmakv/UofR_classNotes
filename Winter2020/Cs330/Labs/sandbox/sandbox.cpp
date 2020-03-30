#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


pid_t fork(void);


using namespace std;

int main(void)
{
   int i;
   
   pid_t fork_return = fork( ); 

   if (fork_return == 0)
   {
    /*in the child process*/
    cout << "Child Print ";
      
   }
   else if(fork_return > 0)
   {
    /*in the Parent process*/
    cout << "Parent Print ";
   }
   else if(fork_return == -1)
   {
      printf("ERROR:\n");
      switch (errno)
      {
         case EAGAIN:
        printf("Cannot fork process: System Process Limit Reached\n");
     case ENOMEM:
        printf("Cannot fork process: Out of memory\n");
      }
      return 1;
   }


   return 0;
}