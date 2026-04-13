#include <stdio.h>

#define MAX 1000

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int N, x;

    scanf("%d", &N);

    // Input queue elements
    for(int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue → stack
    while(front <= rear) {
        push(dequeue());
    }

    // Move stack → queue
    while(top >= 0) {
        enqueue(pop());
    }

    // Print reversed queue
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}