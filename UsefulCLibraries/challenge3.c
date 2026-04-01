#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t cur_time = 0;
    char* cur_t_string;
    cur_time = time(NULL);

    if (cur_time == ((time_t) - 1)) {
        (void) fprintf(stderr, "Failure to get current time. \n");
        exit(EXIT_FAILURE);
    }

    cur_t_string = ctime(&cur_time);

    if (cur_t_string == NULL) {
        (void) fprintf(stderr, "Failure to convert current time. \n");
        exit(EXIT_FAILURE);
    }
    (void) printf("\n The current time is: %s \n", cur_t_string);
    exit(EXIT_SUCCESS);
}
