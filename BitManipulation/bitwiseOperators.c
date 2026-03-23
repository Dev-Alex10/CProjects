#include <stdio.h>

long long convertDecimalToBinary(int decimal);

int main(){

    int number, number2;

    printf("Enter 2 numbers, press enter");
    scanf("%d\n%d", &number, &number2);
    long long negativeBin,negativeBin2, andBin, orBin, xorBin, shiftBin, shiftBin2;
    negativeBin = convertDecimalToBinary(~(number));
    negativeBin2 = convertDecimalToBinary(~(number2));
    printf("~ result: %lld  %lld\n",negativeBin, negativeBin2);

    andBin = convertDecimalToBinary(number & number2);
    printf("& result: %lld \n",andBin);

    orBin = convertDecimalToBinary(number | number2);
    printf("| result: %lld \n", orBin);

    xorBin = convertDecimalToBinary(number ^ number2);
    printf("^ result: %lld \n", xorBin);

    shiftBin = convertDecimalToBinary(number << 1);
    shiftBin2 = convertDecimalToBinary(number2 << 1);
    printf("<< result: %lld  %lld\n",shiftBin,shiftBin2);
    printf("<< decimal result: %d  %d\n",number << 1,number2 << 1);

    long long shiftBin3,shiftBin4;
    shiftBin3 = convertDecimalToBinary(number >> 1);
    shiftBin4 = convertDecimalToBinary(number2 >> 1);
    printf(">> result: %lld  %lld\n",shiftBin3 , shiftBin4);
    printf(">> decimal result: %d  %d\n",number >> 1,number2 >> 1);

    long long bin1 = convertDecimalToBinary(number);
    long long bin2 = convertDecimalToBinary(number2);
    printf("Binary result: %lld  %lld\n", bin1, bin2);

    return 0;
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
