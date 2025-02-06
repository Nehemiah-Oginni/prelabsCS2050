#include <stdio.h>

int** createDynamicArray(int rows, int* columnSizes)
{

    int** array2D = malloc(sizeof(int) + sizeof(int*) * rows);

    array2D[0] = rows; //sets rows at 0th element before shifting to the right to make it the -1st
    
    //(((int)array2D)++);
    array2D++;

    for(int i=0; i<rows; i++)// makes columns diffrent lengths
    {
        array2D[i] = malloc(sizeof(int) + sizeof(int) * columnSizes[i]);
    }
}

int** printDynamicArray(int rows, int* columnSizes)
{

}