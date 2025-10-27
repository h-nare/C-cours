#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 10000
#define MAXLEN 1024

int main(int argc, char *argv[]) {
    int n = 10;
    if (argc == 2 && argv[1][0] == '-')
        n = atoi(argv[1] + 1);

    char *lines[MAXLINES];
    char buffer[MAXLEN];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), stdin)) {
        lines[count] = malloc(strlen(buffer) + 1);
        strcpy(lines[count], buffer);
        count++;
        if (count >= MAXLINES)
            break;
    }

    int start = count - n;
    if (start < 0)
        start = 0;

    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    return 0;
}

