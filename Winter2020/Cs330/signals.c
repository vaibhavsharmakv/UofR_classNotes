

// original code from http://jan.netcomp.monash.edu.au/OS/l8_1.html
// now available from: https://jan.newmarch.name/ProgrammingUnix/processes/lecture.html
// modified for Posix signals
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     //added this to the original
#include <signal.h>
#include <sys/types.h>
#include <time.h>

static void intHandler (int signalNo, siginfo_t *info, void *context)
{     
      printf("Signal received %d. \n", signalNo);
      if (signalNo == SIGTRAP){
        printf("Child received signal \n");
      }else{
        printf("Parent received signal \n");
      }
      

      exit(2);
       
}

int main(int argc, char *argv[])
{
       pid_t pid;

       //Variables needed for signals
       sigset_t interruptMask;             
       struct sigaction act;

       if ((pid = fork()) < 0)
       {
               fprintf(stderr, "fork failed\n");
               exit(1);
       }

       if (pid == 0)
       {
	       //set the stage (the bitmask)
               sigemptyset (&interruptMask);
               sigaddset (&interruptMask, SIGTRAP);  


               //Hook up the signalhandler to SIGINT 
               act.sa_sigaction = &intHandler;
               act.sa_flags = SA_SIGINFO;
               sigemptyset (&(act.sa_mask));
               if (sigaction (SIGTRAP, &act, NULL) == -1)
               {
                       perror("sigaction cannot set SIGTRAP");
                       exit(SIGTRAP);
               }
               while (1)
                       printf("Child Waiting\n");
       }

       //nanosleep((const struct timespec[]){{0, 500000L}}, NULL);
       nanosleep((const struct timespec[]){{0, 500000L}}, NULL);
       kill(pid, SIGTRAP);
      while (1)
                        printf("Parent Waiting\n");
       exit(0);
}



