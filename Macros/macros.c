#include <ctype.h>
#include <stdio.h>

//2
#define SUM(x,y) (x) + (y)
//3
#define SQUARE(x) (x) * (x)
#define CUBE(x) (x) * (x) * (x)
//4
#define IS_UPPER(c) (c >= 'A' && c <= 'Z')
#define IS_LOWER(c) (c >= 'a' && c <= 'z')

int main(){
    // Challenge 1 Print predefined constants
    printf("_LINE_ %d\n", __LINE__);
    printf("_FILE_ %s\n", __FILE__);
    printf("_DATE_ %s\n", __DATE__);
    printf("_TIME_ %s\n", __TIME__);
    printf("_STDC_  %d\n", __STDC__);

    // Challenge 2 2 parameters sum
    int x,y;
    puts("\nWrite two numbers to sum");
    scanf("%d %d", &x, &y);
    printf("Sum of %d and %d is %d\n", x, y, SUM(x, y));

    // Challenge 3 square and cube macro
    puts("\nEnter number to square and cube");
    scanf("%d", &x);
    printf("Square of %d is %d\n", x, SQUARE(x));
    printf("Cube of %d is %d\n", x, CUBE(x));

    // Challenge 4 os lowerCase or upperCase
    char c;
    puts("\nEnter any character:");
    // c = getchar(); // Can only be used when first called, or else it picks the previous entry
    scanf("%s", &c);
    if (IS_UPPER(c)) {
        printf("The character %c is uppercase", c);
    } else if(IS_LOWER(c)) {
        printf("\nThe character %c is lowercase", c);
    } else {
        printf("The character is not in the alphabet\n");
    }


    return 0;
}
