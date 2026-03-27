#include <stdio.h>

int main(){
    int **ipp,*ip, i = 10;

    ip = &i;
    ipp = &ip;

    printf("i value using pointer %d\n", *ip);
    printf("i value using double pointer %d\n", **ipp);
    printf("i memory address using pointer %p\n", ip);
    printf("i memory address using double pointer %p\n", *ipp);
    printf("Pointer value using pointer %p\n", ip);
    printf("Pointer value using double pointer %p\n", *ipp);
    printf("Pointer memory using pointer %p\n", &ip);
    printf("Pointer memory using double pointer %p\n", ipp);
    printf("Double pointer memory %p\n", &ipp);
    printf("Double pointer value %p\n", ipp);

    return 0;
}
