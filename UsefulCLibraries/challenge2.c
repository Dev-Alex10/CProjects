#include <stdio.h>
#include <stdlib.h>
#define NUM 40

void fill_array(double ar[], int n);
void show_array(const double ar[], int n);
int mycomp(const void *p1, const void *p2);

int main(){
    double vals[NUM];
    fill_array(vals, NUM);

    puts("Random List:");
    show_array(vals, NUM);

    qsort(vals, NUM, sizeof(double),mycomp);
    puts("\nSorted List");
    show_array(vals, NUM);

    return 0;
}

void fill_array(double ar[], int n){
    int index = 0;

    for (index = 0; index < n; index++) {
        ar[index] = (double) rand()/((double) rand() + 0.1);
    }
}

void show_array(const double ar[], int n){
    for (int index = 0; index < n; index++) {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5) 
            putchar('\n');
    }
}

int mycomp(const void *p1, const void *p2){
    const double *a1 = (const double *) p1;
    const double *a2 = (const double *) p2;

    if (*a1 < *a2) {
        return -1;
    }else if (*a1 == *a2) {
        return 0;
    }else {
        return 1;
    }


    return 0;
}
