#include <stdio.h>

int main(){

    int number, number2, bit;

    printf("Enter number:");
    scanf("%d", &number);


    printf("\nEnter nth bit: ");
    scanf("%d", &bit);

    // 10 bin = 1010
    // 2 bin = 0010
    number2 = (number >> bit) & 1;
    printf("The %d bit is set to: %d\n",bit,number2);


    number2 = (1 << bit) | number;
    printf("\nNumber before setting %d bit: %d (in decimal)\n",bit,number);
    printf("Number after setting %d bit: %d (in decimal)\n",bit,number2);

    return 0;
}
