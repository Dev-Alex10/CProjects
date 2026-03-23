#include <stdio.h>
#include <math.h>

int convertBinaryToDecimal(long long bin);


long long convertDecimalToBinary(int decimal);


int main (){
    long long bin = 1010; //25

    int decimal = convertBinaryToDecimal(bin);

    printf("Decimal value is %d\n", decimal);

    // Challenge 2
    int decimalByUser;

    printf("Please insert a decimal number");
    scanf("%d" , &decimalByUser);

    long long binary = convertDecimalToBinary(decimalByUser);

    printf("Binary value is %lld", binary);

    return 0;
}

int convertBinaryToDecimal(long long bin){
    int decimal = 0,i = 0,remainder = 0;

    while(bin !=0){
        remainder = bin % 10;
        bin = bin / 10;
        decimal += remainder*pow(2,i);
        ++i;
    }

    return decimal;
}

long long convertDecimalToBinary(int decimal){
    long long binaryNumber = 0;
    int remainder, i = 1;

    while(decimal != 0){
        remainder = decimal % 2;
        decimal = decimal / 2;
        binaryNumber += remainder * i;
        i = i * 10;
    }

    return binaryNumber;
}
