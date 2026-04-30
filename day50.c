#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST (to build tree)
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// BST Search
struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter BST elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element %d found in BST\n", key);
    else
        printf("Element %d not found in BST\n", key);

    return 0;
}