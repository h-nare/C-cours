#include <stdio.h>

void escape(char s[], const char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}

void unescape(char s[], const char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            i++;
            switch (t[i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case '\\':
                    s[j++] = '\\';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}

int main() {
    char t[] = "Hello\tWorld\nGoodbye\\End";
    char s[100];

    escape(s, t);
    printf("Escaped: %s\n", s);

    char u[100];
    unescape(u, s);
    printf("Unescaped:\n%s\n", u);

    return 0;
}
