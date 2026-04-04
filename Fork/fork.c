#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t pid0, pid1, pid2, pid3;

    pid0 = getpid();
    printf("parent %d ppid %d\n\n", pid0, getppid());

    pid1 = fork();

    if (pid1 == 0) {
        printf("%d %d \n", pid0, pid1);
        pid1 = getpid();
        pid_t parent = getppid();
        printf("child1  %d\n", pid1);
        printf("child1 parent %d\n\n", parent);
        abort();
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("%d %d \n", pid1, pid2);
        pid2 = getpid();
        pid_t parent = getppid();
        printf("child2  %d\n", pid2);
        printf("child2 parent %d\n\n", parent);
        abort();
    }


    pid3 = fork();
    if (pid3 == 0) {
        printf("%d %d \n", pid2, pid3);
        pid3 = getpid();
        pid_t parent = getppid();
        printf("child3  %d\n", pid3);
        printf("child3 parent %d\n\n", parent);
        abort();
    }

    return 0;
}
