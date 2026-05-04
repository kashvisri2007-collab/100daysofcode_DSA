#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    struct Node* newNode2 = createNode(src);
    newNode2->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode2;
}

// DFS cycle detection
int dfs(struct Graph* graph, int vertex, int* visited, int parent) {
    visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adj = temp->vertex;

        if (!visited[adj]) {
            if (dfs(graph, adj, visited, vertex))
                return 1;
        }
        else if (adj != parent) {
            return 1;  // cycle found
        }

        temp = temp->next;
    }
    return 0;
}

// Check cycle
int hasCycle(struct Graph* graph) {
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}