#include <stdio.h>
#include <stdlib.h>


void findArraySize(int *array)
{
    printf("array size is %d\n", array[-1]);
    
    for(int i=0; i < array[-1]; i++)
    {
        printf("array[%d] is %d\n", i, array[i]);
    }
}


int main (void)
{
    int size = (rand() % (1 - 10 + 1)) + 1; // (rand() % (max - min + 1)) + min
    int *array = malloc(size * sizeof(int) + sizeof(int));//makes enough memory to hold all the integers of the array + one more

    array[0] = size;// places the size at the beginning of the array
    array++;// moves what part of the array the name is pointing to. (the size is now in -1)

    for(int i=0; i<size; i++)
    {
        int randnum = rand() % 10;
        array[i] = randnum;
    }
    
    findArraySize(array);

    array--;

    free(array);
}