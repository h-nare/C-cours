#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[])
{
    int i = 0, j;
    char temp;

    // find last character index
    for (j = 0; s[j] != '\0'; j++);
    j--;

    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char line[MAXLINE];
    int c, len = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != '\n')
        {
            if (len < MAXLINE - 1)
                line[len++] = c;
            else
            {
                line[len] = '\0';
                reverse(line);
                printf("%s\n", line);
                len = 0;
            }
        }
        else // newline
        {
            line[len] = '\0';
            reverse(line);
            printf("%s\n", line);
            len = 0;
        }
    }

    // handle last line if no newline at EOF
    if (len > 0)
    {
        line[len] = '\0';
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

