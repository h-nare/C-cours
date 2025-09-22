#include <stdio.h>

#define MAXLINE 1000

int main(void) {
    char line[MAXLINE];
    int c, len = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (len < MAXLINE - 1)
                line[len++] = c;
        } else {
            line[len] = '\0';
            if (len > 80)
                printf("%s\n", line);
            len = 0;
        }
    }
    if (len > 80) {
        line[len] = '\0';
        printf("%s\n", line);
    }

    return 0;
}
