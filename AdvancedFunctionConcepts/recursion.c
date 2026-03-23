#include <stdio.h>
#include <stddef.h>
#include <string.h>

int sum(int number);
int greatest_denominator(int number1, int number2);
char *reverse(char *string);

int main(){
    //Challenge 1
    printf("Recursion %d\n", sum(5));

    //Challenge 2
    printf("greates commom denominator between %d and %d is: %d\n",10, 50 ,greatest_denominator(10, 50));

    //Challenge 3
    char string[100];
    char *reverse_string = NULL;

    printf("Enter the string: ");
    scanf("%s", string);
    reverse_string = reverse(string);

    printf("Reverse string of %s is %s\n", string, reverse_string);
    return 0;
}

int sum(int number){
    int result = 0;

    if (number == 1) {
        result = 1;
    }else {
        result = number + sum(number-1);
    }
    return result;
}

int greatest_denominator(int number1, int number2){

    while (number1 != number2) {
        if (number1 > number2) {
            return greatest_denominator(number1 - number2, number2);
        }else {
            return greatest_denominator(number1,number2 - number1);
        }
    }

    return number1;
}

char *reverse(char *string){
    static char reverse_string[100];
    size_t size = strlen(string);

    if (*string) {
        reverse(string + 1);
        reverse_string[size - 1] = *string;
        printf("char is: %s, string is %s\n",reverse_string,string);
    }

    return reverse_string;
}
