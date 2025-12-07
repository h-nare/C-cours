#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int num_stack[MAX];
char op_stack[MAX];
int num_top = -1, op_top = -1;

void push_num(int x) { num_stack[++num_top] = x; }
int pop_num() { return num_stack[num_top--]; }

void push_op(char c) { op_stack[++op_top] = c; }
char pop_op() { return op_stack[op_top--]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

int apply(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '%') return a % b;
    return 0;
}

void solve_top() {
    int b = pop_num();
    int a = pop_num();
    char op = pop_op();
    push_num(apply(a, b, op));
}

int evaluate(char *s) {
    int i = 0;

    while (s[i]) {
        if (isspace(s[i])) {
            i++;
            continue;
        }

        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            push_num(num);
            continue;
        }

        if (s[i] == '(') {
            push_op(s[i]);
            i++;
            continue;
        }

        if (s[i] == ')') {
            while (op_top >= 0 && op_stack[op_top] != '(')
                solve_top();
            pop_op(); 
            i++;
            continue;
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%') {
            while (op_top >= 0 && precedence(op_stack[op_top]) >= precedence(s[i]))
                solve_top();
            push_op(s[i]);
            i++;
            continue;
        }

        i++;
    }

    while (op_top >= 0)
        solve_top();

    return pop_num();
}

int main() {
    char line[256];

    printf("Infix Calculator (Ctrl+D to exit)\n");

    while (printf("> "), fflush(stdout), fgets(line, sizeof(line), stdin)) {
        num_top = op_top = -1;
        int result = evaluate(line);
        printf("= %d\n", result);
    }

    printf("\nExiting.\n");
    return 0;
}

