#include <stdio.h>
#include <stdlib.h>

//prototype
float* copyFloatArray(float inputArray[], int * outputLength);
int linearSearch(float inputArray[]);
void freeFloatArray(float **array);


int main (void)
{

}
/* function returns a pointer to the newly created array. It also has an “output” parameter where you can
store the length of the input array (which, of course, should be the same as the length of the copy). How will you know
how long the input array is? The value 0.0 will act as a sentinel. Just keep going through the input array until you find
the sentinel and that will be the last valid entry in the array. */
float* copyFloatArray(float inputArray[], int * outputLength)
{
    if(inputArray == NULL || outputLength == NULL)
    {
        printf(" ummmm nah we cant do that\n");
    }
    else
    {
        *outputLength = linearSearch(inputArray);

        float* newArray = NULL;

        float* newArray = malloc(*outputLength * sizeof(float));

        if(newArray != NULL)
        {
        for(int i=0; i < *outputLength; i++)
        {
            newArray[i] = inputArray[i];
        }
        }
        else
        {
            printf("malloc didnt work :(");
        }
    }
    
}

//goes through array until it finds the wanted value "0.0" 
//then returns index (the length of the array)
int linearSearch(float inputArray[])
{
    float arrayEnd = 0.0;
    int i = 0;
    while(1)
    {
        if(inputArray[i] == arrayEnd)
        {
            return i;
        }
        i++;
    }
    return -1;
}

// frees the array pointer then sets it to null
void freeFloatArray(float **array)
{
    if(*array != NULL)
    {
    free(*array);
    *array = NULL;
    }
    else
    {
        printf("array already empty");
    }
}