#include <iostream>

using namespace std;

// Structure for each node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in a binary tree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary tree
Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to display the binary tree (in-order traversal)
void displayTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);
}

// Driver code
int main() {
    Node* root = nullptr;
    int choice, value;
    while (true) {
        cout << "Binary Tree Menu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display Tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node inserted successfully.\n";
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Node deleted successfully.\n";
                break;
            case 3:
                cout << "Displaying the tree: ";
                displayTree(root);
                cout << endl;
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;
    }

    return 0;
}
