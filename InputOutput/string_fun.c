#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char *buffer = NULL;    // let getline manage memory, start as NULL
    size_t buffsize = 0;    // getline will set this automatically
    char user_choice;
    ssize_t characters_read;       // getline returns ssize_t, not stored in b
    FILE *fp = NULL;

    fp = fopen("test.txt", "r");  // "rw" is invalid, use "r" for read
                                  //
    if(fp == NULL){
        puts("Error opening file");
        return 1;
    }

    scanf("%c", &user_choice);

    // getline return value goes in line_len, not b
    // -1 means EOF or error
    while((characters_read = getline(&buffer, &buffsize, fp)) != -1){
        // strchr checks if user_choice exists in the line
        if(strchr(buffer, user_choice) != NULL){
            printf("Characters read %zu\n", characters_read);
            fputs(buffer, stdout);
        }
    }

    free(buffer);    // getline allocates memory, you must free it
    fclose(fp);
    return 0;
}
