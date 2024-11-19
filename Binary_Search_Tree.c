#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with given data into the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data); // Insert in the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // Insert in the right subtree
    }
    
    // Return the unchanged root pointer
    return root;
}

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left; // Go to the leftmost node
    }
    return root;
}

// Function to delete a node with given data from the BST
struct Node* deleteNode(struct Node* root, int data) {
    // If the tree is empty
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (data < root->data) {
        root->left = deleteNode(root->left, data); // Search in the left subtree
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // Search in the right subtree
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);   // Visit left subtree
        printf("%d ", root->data);      // Visit node
        inorderTraversal(root->right);  // Visit right subtree
    }
}

// Example usage
int main() {
    struct Node* root = NULL; // Initialize the root of the BST

    // Insert nodes into the BST
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    // Print the in-order traversal of the BST
    printf("In-order traversal of the BST before deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Delete a node
    root = deleteNode(root, 10); // Delete node with value 10

    // Print the in-order traversal of the BST after deletion
    printf("In-order traversal of the BST after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}