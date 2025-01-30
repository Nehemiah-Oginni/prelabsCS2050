#include <stdio.h>
#include <stdlib.h>

/*
Implement a function that returns information relating to a dataset of integers in an array. Specifically,
the function must provide the total number of distinct values (i.e., non-duplicates) in the array and the
smallest value and largest value in the array. Below is a partial prototype for the function. You are free
to determine the full prototype, e.g., other parameters and return value (if there is one).

HINT: The user of this function will expect three pieces of information from it, and since you can’t have
three return values, you’ll need to pass some or all the information to the user by reference.
*/

int getArrayInfo(int *array, int n, int* minval, int *maxval)// n is the size of array
{
    if(n != 0)
    {
        int max = array[0];
        int min = array[0];
        int total = 0;
        for(int i=0; i<n; i++)
        {
            if(array[i] > max)
            {
                max = array[i];
            }
            if(array[i] < min)
            {
                min = array[i];
            }
        }
        *minval = min;
        *maxval = max;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<= n-1; j++)
            {
                printf(" array [%d]= %d,  array [%d]= %d\n ", i, array[i], j, array[j]);
                if(array[i] == array[j])
                {
                    break;
                }
                if(j == n-1)
                {
                    total += 1;
                }
            }
            
        }
        return total + 1;
    }
    return 0;
}

int main (void)
{
    int n = 0;
    int array[n];
    int min = 20;
    int max = 30;
    for(int i=0; i<n; i++)
    {
        array[i]=-5;
    }


    int total = getArrayInfo(array, n, &min, &max);

    printf("max is %d, min is %d and there are %d\n", max, min, total);
}

//as you go through the array you want to compare each element to the current element