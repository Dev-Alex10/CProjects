#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS 50

int main(){
    srand(time(NULL));
    printf("%d random numbers\n", NUMBERS);
    for (int i = 0; i < NUMBERS; i++) {
        printf("Number i = %d, value = %f\n", i+1, (rand() % 2001 - 1000) / 2.e3);
    }
    return 0;
}
