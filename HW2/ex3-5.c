#include <stdio.h>

void reverse(char s[]) {
    int i = 0;
    int j = 0;
    while (s[j] != '\0') 
	j++;
    j--;

    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void itob(int n, char s[], int b) {
    int i = 0;
    int isNegative = 0;

    if (n == 0) {
        s[i++] = '0';
        s[i] = '\0';
        return;
    }

    if (n < 0 && b == 10) { // negative only for decimals
        isNegative = 1;
        n = -n;
    }

    while (n > 0) {
        int rem = n % b;
        if (rem < 10)
            s[i++] = rem + '0';
        else
            s[i++] = rem - 10 + 'a'; // letters for bases > 10
        n = n / b;
    }

    if (isNegative)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    itob(175, s, 16); // hexadecimal
    printf("175 in base 16: %s\n", s);

    itob(35, s, 36); // base 36
    printf("35 in base 36: %s\n", s);

    itob(20, s, 2); // binary
    printf("20 in base 2: %s\n", s);

    return 0;
}

