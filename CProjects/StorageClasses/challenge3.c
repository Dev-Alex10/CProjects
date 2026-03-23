#include <stdio.h>

int counter = 0;

extern void display(void);

int main(){
    for(int i = 0; i < 5; i++)
    display();

    return 0;
}
