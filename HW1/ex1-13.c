#include <stdio.h>

#define MAXLEN 30           /* maximum word length to track */
#define OVERFLOW (MAXLEN + 1)  /* overflow bucket for longer words */

int main(void) {
    int counts[OVERFLOW + 1] = {0};
    int c, len = 0;

    /* Count word lengths */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (len > 0) {
                if (len <= MAXLEN)
                    counts[len]++;
                else
                    counts[OVERFLOW]++;
                len = 0;
            }
        } else {
            len++;
        }
    }
    if (len > 0) {  /* last word */
        if (len <= MAXLEN)
            counts[len]++;
        else
            counts[OVERFLOW]++;
    }

    /* Horizontal histogram*/
    printf("\nHorizontal histogram of word lengths:\n");
    for (int i = 1; i <= MAXLEN; ++i) {
        if (counts[i] == 0) continue;
        printf("%d: ", i);
        for (int j = 0; j < counts[i]; ++j)
            putchar('#');
        putchar('\n');
    }
    if (counts[OVERFLOW] > 0) {
        printf("overflow: ");
        for (int j = 0; j < counts[OVERFLOW]; ++j)
            putchar('#');
        putchar('\n');
    }

    /*  Vertical histogram*/
    /* find maximum column height */
    int maxcount = 0;
    for (int i = 1; i <= OVERFLOW; ++i)
        if (counts[i] > maxcount) maxcount = counts[i];

    if (maxcount == 0) {
        printf("\nNo words found in input.\n");
        return 0;
    }

    printf("\nVertical histogram:\n");

    /* print rows from top down */
    for (int level = maxcount; level >= 1; --level) {
        for (int i = 1; i <= OVERFLOW; ++i) {
            if (counts[i] >= level)
                printf(" # ");
            else
                printf("   ");
        }
        putchar('\n');
    }

    /* print labels */
    for (int i = 1; i <= MAXLEN; ++i)
        printf("%d ", i);
    if (counts[OVERFLOW] > 0)
        printf("overflow");
    putchar('\n');

    return 0;
}

