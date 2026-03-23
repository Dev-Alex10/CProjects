#include <stdio.h>
#include <stdlib.h>

int is_prime(int number);
int is_even(int number);

int main(){
    FILE *fp = fopen("numbers.txt","r");

    if(fp == NULL){
        printf("Could not open file");
        return 1;
    }

    char buffer[255];

    while(!feof(fp)){
        int number;
        fscanf(fp, "%d", &number);

        if(is_prime(number))
            printf("Number is prime %d\n", number);
        else if(is_even(number))
            printf("Number is even %d\n", number);
        else
            printf("Number is odd %d\n", number);
    }

    fclose(fp);
    return 0;
}


int is_prime(int number){
    if(number < 2)        // 0, 1, and negatives are not prime
        return 0;

    if(number == 2)       // 2 is the only even prime
        return 1;

    if(number % 2 == 0)   // eliminate all other even numbers
        return 0;

    // only check odd divisors up to √number
    for(int i = 3; i * i <= number; i += 2){
        if(number % i == 0)
            return 0;
    }

    return 1;
}

int is_even(int number){
    return !(number & 1);
}

