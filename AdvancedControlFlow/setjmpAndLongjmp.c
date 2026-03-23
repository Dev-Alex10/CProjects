#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery();

int main(){
    while(1){

        if(setjmp(buf)){
            printf(" Back in main");
            break;
        }else{
            error_recovery();
        }
    }

    return 0;
}

void error_recovery(){
    printf("Error\n");
    longjmp(buf,1);
}
