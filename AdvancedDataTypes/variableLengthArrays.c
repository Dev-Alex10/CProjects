#include <stdio.h>

int main(){
    int i, sum=0,size=0;

    printf("Enter the size of the array \n");

    scanf("%d",&size);

    int array[size];

    printf("Enter %d element in the array: ", size);

    for(i=0; i < size; i++){
        scanf("%d", &array[i]);
    }

    for(i = 0; i < size; i++){
        sum += array[i];
    }

    printf("Sum of all elements = %d", sum);
    return 0;
}
