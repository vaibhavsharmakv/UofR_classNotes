#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main (int argc, char *argv [])
{
    int *array;
    int min = 9999;
    int size=0;

    printf("How big is the array?");
    scanf("%i", &size);
    array = (int *) malloc(sizeof(int)*size);

    if (initialize (array, size) != 0 )
    {
        printf ("initialization error\n");
        exit (1);
    }

    if (findAndReturnMin (array, size, &min) != 0 )
    {
        printf ("someFunction error\n");
        exit (1);
    }
    printf ("min value in array is: %d\n", min);
    free(array);
    exit (0);
}

