#include <stdio.h>
#include <time.h>

int main() {
    time_t t;
    struct tm *now;

    t = time(NULL);       
    now = localtime(&t);   

    printf("Date: %04d-%02d-%02d\n",
           now->tm_year + 1900,
           now->tm_mon + 1,
           now->tm_mday);

    printf("Time: %02d:%02d:%02d\n",
           now->tm_hour,
           now->tm_min,
           now->tm_sec);

    return 0;
}

