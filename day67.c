#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS for topo sort
void dfs(int v, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    // push to stack after visiting all neighbors
    stack[++(*top)] = v;
}

void topologicalSort(int V, struct Node* adj[]) {
    int visited[V];
    int stack[V];
    int top = -1;

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // handle multiple components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    // print in reverse order of stack
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    topologicalSort(V, adj);

    return 0;
}