#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int *ptr);
void allocateMemoryDoubleP(int **ptr);

int main(){
    /*int *ptr = NULL;

    allocateMemory(ptr);
    *ptr = 20;
    printf("Pointer value in main %d\n", *ptr);

    free(ptr);
*/

    int *ptr = NULL;

    allocateMemoryDoubleP(&ptr);
    *ptr = 20;
    printf("Pointer value with double pointer %d\n", *ptr);

    free(ptr);

    return 0;
}

void allocateMemory(int *ptr){
    ptr = (int *) malloc(sizeof(int));
}


void allocateMemoryDoubleP(int **ptr){
    *ptr = (int *) malloc(sizeof(int));
}
