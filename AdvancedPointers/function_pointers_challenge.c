#include <stdio.h>
#include <string.h>
#include <malloc.h>

// some random numbers
int array1[] = {10,20,30,40,50,60,70,80,90,100};
int array2[] = { 38, 27, 87, 63, 59, 223, 132, 1, 19, 7 };


int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

/// Array of pointers to functions
// INSERT YOUR FUNCTION POINTER INITIALIZATION HERE = { &add,&sub,&mult,&div };
int (*fpArray[])(int,int) = { &add,&sub,&mult,&div };
// performs the given operation on elements of the arrays
int* performOp(int *a, int *b, int size,int (*pfun)(int,int));

// displays the elements of an array
void display(int *x, int size);

int main( ){

    int choice = 0;

    unsigned int size = 0;

    int *result = NULL;

    // set size to minimum size of the two arrays
    size = sizeof(array1);

    if (sizeof(array2) < size)
        size = sizeof(array2);

    size = size / sizeof(int);

    while(choice != 5)
    {
        printf("\n\nWhich operation do you want to perform? \n");
        printf("1.Add \n");
        printf("2.Subtract \n");
        printf("3.Multiply \n");
        printf("4.Divide \n");
        printf("5.None ... \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 5) break;
        if(choice < 1 || choice > 5) continue;

        int j = choice - 1;

        result = performOp(array1,array2,size,fpArray[j]);

        printf("\n\nThe Results are ...\n");
        display(result,size);

        if(result!=NULL)  
            free(result);

    }

    return 0;
}


// performs the given operation on all elements of the arrays A and B
int* performOp(int *a, int *b, int size, int (*pfun)(int,int))
{
    int *results = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        //printf("Numbers are %d, %d, the fun is %p\n",a[i],b[i],pfun);
        //printf("Result is %d\n", pfun(a[i], b[i]));
        results[i] = (pfun(a[i],b[i]));
    }

    return results;
}


// function for displaying the results stored in array x
void display(int *x, int size)
{
    if (x == NULL) return;
    

    for (int i = 0; i < size; i++) {
        printf("%d ", x[i]) ;
    }

    printf("\n");
}
