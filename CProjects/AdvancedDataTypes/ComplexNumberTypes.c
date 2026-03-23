#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(){

    double complex z1 = I*I;
    printf("real: %+.2f \timaginary: %+.2fi",creal(z1),cimag(z1));

    double complex z2 = pow(I,2);
    printf("\nreal: %+.2f \timaginary: %+.2fi",creal(z2),cimag(z2));

    double PI = acos(-1);
    double complex z3= exp(I * PI);
    printf("\nreal: %+.2f \timaginary: %+.2fi",creal(z3),cimag(z3));

    double complex z4 = 1 + 2*I,z5 = 1 - 2*I;
    printf("\nreal: %+.2f \timaginary: %+.2fi",creal(z4*z5),cimag(z4*z5));
    //creal();
    //cimag();

    return 0;
}
