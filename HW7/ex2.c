#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <keyword> <file>\n", argv[0]);
        return 1;
    }

    char *keyword = argv[1];
    FILE *file = fopen(argv[2], "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE];
    int line_number = 1;

    while (fgets(line, MAX_LINE, file)) {
        if (strstr(line, keyword)) {  // check if keyword is in line
            printf("%d: %s", line_number, line);
        }
        line_number++;
    }

    fclose(file);
    return 0;
}

