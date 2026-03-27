#include <stdio.h>

int fun();
void fun1 (int);
void fun2 (int);

typedef void FuncType(int);

int main(){
    int (*pfun)();

    FuncType *func_ptr = NULL;

    pfun = fun;
    func_ptr = fun1;

    (*func_ptr)(100);
    func_ptr = fun2;
    (*func_ptr)(200);

    printf("Address of function %p\n", pfun);
    (*pfun)();

    return 0;
}

int fun(){
    printf("Fun is fun\n");
    return 0;
}

void fun1(int n){
    printf("Fun1 got %d\n", n);
}


void fun2(int n){
    printf("Fun2 got %d\n", n);
}
