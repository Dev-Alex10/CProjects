#include <stdio.h>
#include <ctype.h>

int main(){
    int ch = 0, count = 0, word_counter = 0;

    while((ch = getchar())!= EOF){
        if(ch == '\n' || ch == ' '){
            word_counter++;
            continue;
        }
        count++;
    }

    printf("Counter: %d\n", count);
    printf("Number of words: %d\n", word_counter);


    // Challenge 2
    int ch2 = 0;
    FILE *fp = NULL;

    fp = fopen("test.txt", "rw");

    if(fp == NULL){
        printf("Could not open text.txt file");
        return 0;
    }

    while(1){
        ch2 = fgetc(fp);

        if(isupper(ch2))
            ch2 = tolower(ch2);
        else
            ch2 = toupper(ch2);

        if(ch2 == EOF)
            break;

        printf("%c", ch2);
        //fputc to put to a file
    }



    return 0;
}
