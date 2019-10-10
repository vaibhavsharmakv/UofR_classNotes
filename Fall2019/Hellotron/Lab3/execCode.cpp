#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int i;
   for (i=0; i<argc; i++)
   {
	printf("Argument %i: %s\n", i, argv[i]);
   }
   execvp(argv[1], &argv[1]);
   perror("exec failure");
   exit(1);
}



