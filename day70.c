#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

// Min heap node
struct HeapNode {
    int v, dist;
};

// Min heap
struct MinHeap {
    int size;
    struct HeapNode arr[MAX];
};

// Create adjacency node
struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->w = w;
    node->next = NULL;
    return node;
}

// Add edge (directed)
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(struct MinHeap* h, int i) {
    while (i > 0 && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(struct MinHeap* h, int v, int dist) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Pop min
struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

// Check empty
int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

// Dijkstra
void dijkstra(int V, struct Node* adj[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (!isEmpty(&heap)) {
        struct HeapNode cur = pop(&heap);
        int u = cur.v;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Input edges: u v w
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(V, adj, src);

    return 0;
}