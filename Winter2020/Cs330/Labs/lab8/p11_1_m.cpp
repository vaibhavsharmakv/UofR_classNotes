//
// Creating threads
//
// Based on p11.1.cxx from Interprocess Communications in Linux
// By: John Shapley Gray
// Adapted for CS330 by Alex Clarke
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

extern "C" 
{
   void * say_it( void * );
}

int main(int argc, char *argv[])
{
   int num_threads;
   pthread_t *thread_ids;

   //Use unbuffered output on stdout
   setvbuf(stdout, (char *) NULL, _IONBF, 0);

   cout << "How many threads? ";
   cin >> num_threads;
   thread_ids = new pthread_t[num_threads];

   cout << "Making Threads" << endl;

   // generate threads 
   for (int i = 0; i < num_threads; i++)
   {
      if( pthread_create(&thread_ids[i],NULL,say_it,&i) > 0)
      {
            cerr << "pthread_create failure" << endl;
            return 2;
      }
   }

   // wait a bit
   cout << "Making Changes in a Moment" << endl;
   sleep(1);

   // modify contents of arguments to threads
   for (int i = 0; i < num_threads; i++)
   {
      thread_ids[i] = i;
   }

   //wait a bit more
   sleep(2);

   system("bash -c 'read -sn 1 -p \"Press any key to quit...\" ' ");
   delete [] thread_ids;
   return 0;
}

// Print out the thread number twice
void * say_it(void *num)
{
   cout << "I am thread #" << *(unsigned int *)(num) << "." << endl;
   sleep (2);
   cout << "I am thread #" << (unsigned int)pthread_self()  << "." << endl;
   return NULL;
}
