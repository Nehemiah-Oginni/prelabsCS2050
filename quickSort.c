#include <stdlib.h>
#include <stdio.h>


// If a should be placed before b, compare function should
// return positive value, if it should be placed after b,
// it should return negative value. Returns 0 otherwise
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main (void)
{
    int array[] = {4, 3, 1,5000, 0, 200, 4};
    int n = sizeof(array) / sizeof(array[0]);

    qsort(array, n, sizeof(int), compare);// qsort(array, array size, size of variables in array, compare)

    for(int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}
