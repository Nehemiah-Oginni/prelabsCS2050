#include <stdio.h>
#include <stdlib.h>


int** createDynamicArray(int rows, int* columnSizes)
{

    int** array2D = malloc(sizeof(int) + sizeof(int*) * rows);

    ((int*)array2D)[0] = rows; //sets rows at 0th element before shifting to the right to make it the -1st
    // casts int pointer 

    array2D = (int**)(((int*)array2D));

    //(((int)array2D)++);
    (int*)array2D++;

    for(int i=0; i<rows; i++)
    {
        array2D[i] = malloc(sizeof(int) + sizeof(int) * columnSizes[i]);// makes columns diffrent lengths
        array2D[i][0] = columnSizes[i];// puts col size at 0th element(in cols)
        array2D[i]++; // change address to the first col data
    }
}

int** printDynamicArray(int** array2d /* int* columnSizes */) //
{
    int* p = (((int*)array2d)-1);

    for(int i=0; i < *p-1; i++)
    {
        for(int j=0; j < array2d[i][-1]; j++)
        {
            printf("%d ", array2d[i][j]);
        }
        printf("\n");
    }
}

void freeArray(int** array2D)
{
    int* p = (((int*)array2D)-1); // makes pointer simpler

    for(int i=0; i < *p-1; i++)
    {
        free(array2D[i]-1);
    }
    free(p);//frees memory
}

// struct practice****************************************************************************************

int main (void)
{
    typedef struct petStruct
    {
        int age;
        char name[20];
        void (*funcPtr)();
    }pet;//replaces the name of the struct with the word pet

    pet* snoopy = NULL;// snoopy is a pointer so it is 8 bytes
    //snoopy = malloc(sizeof(*snoopy));     <-- size of strct
    //size of specific per can be used when you derefrence it


}   
void setPetAge(struct petStruct *pet, int age)
{
    //(*pet).age = age;     
}
