#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    if(c == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int k = 0;

    scanf("%s", infix);

    for(int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if(isalnum(c)) {
            postfix[k++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else {
            while(top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}