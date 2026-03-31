#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if(top == MAX - 1) {
        return;
    }
    stack[++top] = val;
}

void pop() {
    if(top == -1) {
        return;
    }
    top--;
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        pop();
    }

    if(top == -1) {
        printf("Stack is empty");
    } else {
        for(int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}