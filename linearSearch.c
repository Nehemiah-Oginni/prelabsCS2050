#include <stdio.h>
#include <stdlib.h>

//prototype 
int linearSearch(int array[], int value, int n);//goes through array until it finds the wanted value then returns index


int main(void)
{
    int size = 8;

    int array[] = {56, 32, 22, 78, 2, 6, 60, 40};

    int index = linearSearch(array, 60, size);

    if(index != -1)
    {
        printf("Element found at index: %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }
}

int linearSearch(int array[], int value, int n)//goes through array until it finds the wanted value then returns index
{
    for(int i=0; i < n; i++)
    {
        if(array[i] == value)
        {
            return i;
        }
    }
    return -1;
}