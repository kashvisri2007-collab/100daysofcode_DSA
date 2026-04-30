#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order
struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (i < n) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
            i++;
        }

        // Right child
        if (i < n) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }

    free(queue);
    return root;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check complete binary tree
int isComplete(struct Node* root, int index, int total) {
    if (!root) return 1;

    if (index >= total)
        return 0;

    return isComplete(root->left, 2 * index + 1, total) &&
           isComplete(root->right, 2 * index + 2, total);
}

// Check heap property
int isHeap(struct Node* root) {
    if (!root) return 1;

    // Leaf node
    if (!root->left && !root->right)
        return 1;

    // Only left child
    if (!root->right)
        return (root->data <= root->left->data);

    // Both children exist
    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isHeap(root->left) &&
            isHeap(root->right));
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int total = countNodes(root);

    if (isComplete(root, 0, total) && isHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}