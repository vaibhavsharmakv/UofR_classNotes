/*+------------------+
       |  TEXT            | 0x400ca6
       |                  |
       |  instructions in | 0x40096b = proc1
       |  machine code    | 0x400a50 = proc2
       |                  |
       +------------------+ 0x400ca6 = etext
       |  DATA            | 0x60169c = g1   global initialized
       |  - initialized   | 0x6016a0 = g3
       |    variables     | 0x6016a8 = ls1  static initialized
       |                  | 0x6016a4 = ls3
       |                  | 
       | ---------------  | 0x6016ac = edata
       |                  | 0x6016e0 = g0   global uninitialized
       |                  | 0x601700 = g2   big array 
       |                  | 0x602e70 = g4
       |  - uninitialized | 0x602e7c = ls0  static uninitialized
       |    variables     | 0x602e78 = ls2
       |                  |
       |                  | 
       | ---------------  | 0x602e80 = end 
       |  - heap for      | 0x1160010 pointed to by heap1
       |  dynamic         | 0x1160030 pointed to by heap2
       |  allocation      |
       |                  |
       |                  |
       +------------------+ 
                |
                |
                V

                .
                .
                .

                ^
                |
                |
       +------------------+
       |  STACK           | 0x7ffe5cf73da8 = lc4, lc6   | Activation record for 
       |  - function      | 0x7ffe5cf73dac = lc3, lc5   | proc1 or proc2
       |    activation    |
       |    records       |
       |  - local         | 0x7ffe5cf73dc4 = lc2       | Activation record for
       |    automatic     | 0x7ffe5cf73dc8 = lc1       | main
       |    variables     | 0x7ffe5cf73dcc = lc0       |
       +------------------+
*/
/*
Solution 4 : Smaller
Solution 5 : Yes, stack POP previous variables and PUSH new ones at the same adress to use memory better. 
Solution 6 : Recursive fuction is storing variables in the stack so it can just POP them when recursing back to the base case
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

int g0;       /* global variable, uninitialized */
int g1 = 14;  /* global variable, initialized */
int g2[1500]; /* global variable, uninitialized */
int g3 = 16;  /* global variable, initialized */
int g4;       /* global variable, uninitialized */

long int multiplyNumbers(int n); 
void recurisveFactorial();

  int
  main()
{
  extern int etext[], edata[], end[];

  int lc0;      /* local variable, stored on stack */
  int lc1 = 27; /* local variable, stored on stack; mix init and uninit */
  int lc2;      /* local variable, stored on stack */
        static int ls0; /* local static variable, uninitialized data */
        static int ls1 = 19;      /* local static variable, initialized data */
        int *pheap1;
        int *pheap2;

        pheap1 = (int *) malloc(sizeof(int));
        pheap2 = (int *) malloc(sizeof(int));

        printf("\n\n---------- main -------------------\n\n");
        printf("%14p (%15lu): Last address\n", 
    0xffffffffffff, 999999999999999);

        printf("%14p (%15lu): Address etext\n", 
    etext, etext);
        printf("%14p (%15lu): Address edata\n", 
    edata, edata);
        printf("%14p (%15lu): Address end\n", 
    end, end);

        printf("%14p (%15lu): Address of code for proc1\n", 
    &proc1, &proc1);
        printf("%14p (%15lu): Address of code for proc2\n", 
    &proc2, &proc2);

        printf("%14p (%15lu): Address of uninitialized global variable g0\n", 
    &g0, &g0);
        printf("%14p (%15lu): Address of initialized   global variable g1\n", 
    &g1, &g1);
        printf("%14p (%15lu): Address of uninitialized global array    g2\n", 
    &g2[0], &g2[0]);
        printf("%14p (%15lu): Address of initialized   global variable g3\n", 
    &g3, &g3);
        printf("%14p (%15lu): Address of uninitialized global variable g4\n", 
    &g4, &g4);

        printf("%14p (%15lu): Address heap1 in heap space\n", 
    pheap1, (unsigned long) pheap1);
        printf("%14p (%15lu): Address heap2 in heap space\n", 
    pheap2, (unsigned long) pheap2);

  printf("%14p (%15lu): Address of local variable lc0\n", 
    &lc0, &lc0);
  printf("%14p (%15lu): Address of local variable lc1\n", 
    &lc1, &lc1);
  printf("%14p (%15lu): Address of local variable lc2\n", 
    &lc2, &lc2);

  printf("%14p (%15lu): Address of local uninitialized static var ls0\n", 
    &ls0, &ls0);
  printf("%14p (%15lu): Address of local initialized   static var ls1\n", 
    &ls1, &ls1);

  
  recurisveFactorial();

    return 0;
}



void recurisveFactorial(){

  
  int input;
  printf("Enter a positive integer: ");
  scanf("%d", &input);
  printf("Factorial of %d = %ld", input, multiplyNumbers(input));
  cout << endl;
  
  printf("\n\n------------ Factorial -----------------\n\n");
  printf("%14p (%15lu): Address of code for recurisveFactorial\n", 
    &recurisveFactorial, &recurisveFactorial);
  printf("%14p (%15lu): Address of local variable input\n", 
    &input, &input);
  
  
  
}

long int multiplyNumbers(int input){

  printf("%14p (%15lu): Address of variable input during recursion\n", 
    &input, &input);
  if (input >= 1)
    return input * multiplyNumbers(input - 1);
  else
    return 1;
}