#include <stdio.h>

int length_str(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int is_alphanumer(char c)
{
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

int to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

void getline_custom(char *str)
{
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        str[i++] = c;
    str[i] = '\0';
}

void normalize(const char orig[], char normalized[])
{
    int i = 0, j = 0;
    int orig_length = length_str((char*)orig);
    for (i = 0; i < orig_length; i++)
    {
        if (is_alphanumer(orig[i]))
            normalized[j++] = to_lower(orig[i]);
    }
    normalized[j] = '\0';
}

void is_palindrome(char *str)
{
    int len = length_str(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            printf("The string is not a palindrome\n");
            return;
        }
    }
    printf("The string is a palindrome\n");
}

int main()
{
    char str[100];
    char normalized[100];

    printf("Enter a string: ");
    getline_custom(str);
    normalize(str, normalized);
    is_palindrome(normalized);

    return 0;
}

