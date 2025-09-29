#include <stdio.h>

void expand(char s1[], char s2[])
{
    int i = 0;
    int j = 0;

    while (s1[i])
    {
        if (s1[i] == '-' && i > 0 && s1[i + 1])
        {
            char start = s1[i - 1];
            char end = s1[i + 1];

            if (start >= '0' && start <= '9' && end >= '0' && end <= '9' && start < end)
            {
                for (char c = start + 1; c <= end; c++)
                    s2[j++] = c;
                i += 2;
            }
            else if (start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z' && start < end)
            {
                for (char c = start + 1; c <= end; c++)
                    s2[j++] = c;
                i += 2;
            }
            else if (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z' && start < end)
            {
                for (char c = start + 1; c <= end; c++)
                    s2[j++] = c;
                i += 2;
            }
            else
            {
                s2[j++] = s1[i++];
            }
        }
        else
        {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "a-d0-2";
    char s2[100];

    expand(s1, s2);

    printf("Expanded: %s\n", s2);
    return 0;
}

