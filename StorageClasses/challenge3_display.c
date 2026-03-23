#include <stdio.h>

extern int counter;

void display(){
    counter++;
    printf("Display Counter %d\n", counter);
}

