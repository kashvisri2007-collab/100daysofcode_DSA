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

// DFS function
int dfs(int node, int visited[], int recStack[], struct Node* adj[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, adj))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Function to detect cycle
int hasCycle(int V, struct Node* adj[]) {
    int visited[V], recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj))
                return 1;
        }
    }
    return 0;
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
        addEdge(adj, u, v); // directed
    }

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}