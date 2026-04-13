#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x) {
    int i = size - 1;

    // shift elements to maintain sorted order
    while(i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

int deleteMin() {
    if(size == 0)
        return -1;

    int val = pq[0];

    for(int i = 1; i < size; i++)
        pq[i - 1] = pq[i];

    size--;

    return val;
}

int peek() {
    if(size == 0)
        return -1;

    return pq[0];
}

int main() {
    int N, x;
    char op[10];

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        }
        else if(strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}