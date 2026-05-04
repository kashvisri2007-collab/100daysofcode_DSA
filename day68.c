#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add directed edge u -> v
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Kahn's Algorithm
void topologicalSort(int V, struct Node* adj[]) {
    int indegree[V];

    // Step 1: Initialize indegree
    for (int i = 0; i < V; i++)
        indegree[i] = 0;

    // Step 2: Compute indegree
    for (int i = 0; i < V; i++) {
        struct Node* temp = adj[i];
        while (temp != NULL) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    // Step 3: Create queue
    int queue[V];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    // Step 4: Process queue
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }

    // Step 5: Cycle check
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    topologicalSort(V, adj);

    return 0;
}