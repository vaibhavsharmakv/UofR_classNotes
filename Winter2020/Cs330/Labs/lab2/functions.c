#include "functions.h"
/* FUNCTION: initialize
 * This function should initialize the array 
 * to random values between 1 and 500
 *
 * The arguments are:
 *     array: pointer to an array of integer values
 *     length: size of array
 *
 * It returns:
 *     0: on success
 *     non-zero: on an error
 */
int initialize (int *array, int length)
{
    srand(getpid());
    int i;

    for (i = 0; i < length; i ++)
    {
        array [i] = rand()%500 +1;
    }
  
    return 0;
}

/* FUNCTION: findAndReturnMin
 * This function should find the smallest element in the array and
 * return it through the argument min.
 *
 * The arguments are:
 *     array: pointer to an array of integer values
 *     length: size of array
 *     min: set to the smallest value in array 
 *
 * It returns:
 *     0: on success
 *     non-zero: on an error
 */
int findAndReturnMin (int *array, int length, int* min)
{
    int i;

    *min = array [0];
    for (i = 0; i < length; i ++)
    {
        if (*min < array [i])
        { 
            *min = array [i];
        }
    }

    return 0;
}
