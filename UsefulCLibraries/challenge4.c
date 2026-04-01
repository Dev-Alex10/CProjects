#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t now = 0;
    time(&now);

    struct tm beg_month;
    beg_month = *localtime(&now);

    beg_month.tm_hour = 0;
    beg_month.tm_min = 0;
    beg_month.tm_sec = 0;
    beg_month.tm_mday = 1;

    double seconds = difftime(now, mktime(&beg_month));

    printf("\n %.f seconds passed since the beginning of the month.\n", seconds);

    exit(EXIT_SUCCESS);
}
