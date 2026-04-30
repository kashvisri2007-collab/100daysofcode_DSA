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

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        // Both nodes in left subtree
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        // Both nodes in right subtree
        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        // Split point → LCA found
        else
            return root;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;
    int x;

    // Insert nodes into BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}