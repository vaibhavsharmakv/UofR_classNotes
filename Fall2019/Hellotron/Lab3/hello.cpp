#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main(void)
{
   printf("Hello \n");
   fork();
   fork();
   printf("bye\n");
   return 0;
}
// it wont print because your process image is being replaced 
