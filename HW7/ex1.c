#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    if (!f1 || !f2) {
        perror("Error opening file");
        return 1;
    }

    char line1[MAX_LINE];
    char line2[MAX_LINE];
    int line_number = 1;

    while (fgets(line1, MAX_LINE, f1) && fgets(line2, MAX_LINE, f2)) {
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %d:\n", line_number);
            printf("File1: %s", line1);
            printf("File2: %s", line2);
            fclose(f1);
            fclose(f2);
            return 0;
        }
        line_number++;
    }

    if (fgets(line1, MAX_LINE, f1) || fgets(line2, MAX_LINE, f2)) {
        printf("Files differ in length.\n");
    } else {
        printf("Files are identical.\n");
    }

    fclose(f1);
    fclose(f2);
    return 0;
}

