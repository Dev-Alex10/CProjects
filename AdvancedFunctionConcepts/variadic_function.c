#include <stdio.h>
#include <stdarg.h>

int addingNumbers(int count,...);

int main(){
    printf("Sum of 10 + 20  is : %d\n",addingNumbers(2, 10,20));
    printf("Sum of 10 + 20 + 30 is : %d\n",addingNumbers(3, 10,20,30));
    printf("Sum of 10 + 20 + 30 + 40 is : %d\n",addingNumbers(4, 10,20,30,40));
    return 0;
}

int addingNumbers(int count,...){
    va_list parg;
    va_start(parg, count);
    int sum = 0;
    //va_arg(parg,type)
    for (int i = 0; i < count; i++) {
        sum += va_arg(parg,int);
    }
    va_end(parg);

    return sum;
}
