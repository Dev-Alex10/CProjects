#include <stdio.h>
#include <stdbool.h>

#define SOLID 0
#define DOTTED 1
#define DASHED 2

/* Primary Colors */
#define BLUE 4
#define GREEN 2
#define RED 1

/* mixed colors */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow",   "blue", "magenta", "cyan", "white"};

struct Box{
    bool isOpaque           : 1;
    unsigned int fillColor  : 3; // black 000,red 001,green 010 ,yellow 011,blue 100,magenta 101,cyan 110,white 111 (decimal is 1,2,3,4,5,6,7, respectively)
    unsigned int            : 4;
    bool showBorder         : 1;
    unsigned int borderColor: 3; // same as fill color
    unsigned int borderStyle: 2; //solid, dotted, dashed(0,1,2)
    unsigned int            : 2;
};

void showSettings(const struct Box *pb);

int main (){

    struct Box boxData = {true, YELLOW, true, GREEN, DASHED};

    printf("Original box settings: \n");
    showSettings(&boxData);

    boxData.isOpaque = false;
    boxData.fillColor = WHITE;
    boxData.borderColor = MAGENTA;
    boxData.borderStyle = SOLID;

    printf("\nModded box settings:\n");
    showSettings(&boxData);

    return 0;
}

void showSettings(const struct Box *pb) {
    printf("Box is %s.\n", pb->isOpaque == true ? "opaque": "transparent");
    printf("The fill color is %s.\n", colors[pb->fillColor]);
    printf("Border %s.\n",  pb->showBorder == true ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->borderColor]);
    printf ("The border style is ");

    switch(pb->borderStyle)
    {
        case SOLID  : printf("solid.\n"); break;
        case DOTTED : printf("dotted.\n"); break;
        case DASHED : printf("dashed.\n"); break;
        default     : printf("unknown type.\n");
    }
}
