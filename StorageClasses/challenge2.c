#include <stdio.h>

int sum(int num){

    static int totalSum = 0;
    totalSum += num;

    return totalSum;
}


int main(){

    printf("%d ",sum(25));
    printf("%d ",sum(15));
    printf("%d ",sum(30));

    return 0;
}
