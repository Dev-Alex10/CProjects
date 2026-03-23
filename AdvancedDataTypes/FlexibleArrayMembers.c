#include <stdio.h>
#include <stdlib.h>

struct myArray{
    int length;
    int array[];
};

int main(){
    int arraySize=0;
    struct myArray *ptr = NULL;

    printf("Size of the array");
    scanf("%d", &arraySize);

    size_t size = sizeof(struct myArray);
    ptr = malloc(size + arraySize * sizeof(int));


    ptr -> length = arraySize;
    ptr -> array[0] = 55;
    ptr  -> array[1] = 200;

    printf("array is: %d,  %d\n",ptr -> array[0], ptr -> array[1]);

    return 0;
}
