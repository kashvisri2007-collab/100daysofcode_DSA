#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;
int size = 0;

int empty() {
    return size == 0;
}

int getSize() {
    return size;
}

void push_front(int x) {
    if(size == MAX) return;

    if(empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
    size++;
}

void push_back(int x) {
    if(size == MAX) return;

    if(empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
    size++;
}

void pop_front() {
    if(empty()) return;

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    size--;
}

void pop_back() {
    if(empty()) return;

    if(front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }

    size--;
}

int getFront() {
    if(empty()) return -1;
    return deque[front];
}

int getBack() {
    if(empty()) return -1;
    return deque[rear];
}

void display() {
    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    for(int c = 0; c < size; c++) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", getSize());

    pop_front();
    pop_back();

    display();

    return 0;
}