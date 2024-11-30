#include <iostream>

using namespace std;

// Structure for each node in the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
    public:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = new Node();
        if (newNode) {
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
        }
        return newNode;
    }

    // Function to insert a node into the BST
    Node* insertNode(Node* root, int data) {
        if (root == nullptr) {
            root = createNode(data);
        }
        else if (data <= root->data) {
            root->left = insertNode(root->left, data);
        }
        else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }

    // Function to delete a node from the BST
    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) {
            return root;
        }
        else if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            // Node found, delete it

            // Case 1: No child or one child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Two children
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Function to find the minimum node in the BST
    Node* findMinNode(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Function to display the BST in in-order traversal
    void displayInOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        displayInOrder(root->left);
        cout << root->data << " ";
        displayInOrder(root->right);
    }

    // Function to display the BST
    void displayTree() {
        cout << "Binary Search Tree (In-order traversal): ";
        displayInOrder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int choice, data;

    while (true) {
        cout << "Binary Search Tree Menu:" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Display Tree" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to be inserted: ";
            cin >> data;
            bst.root = bst.insertNode(bst.root, data);
            cout << "Node inserted successfully." << endl;
            break;
        case 2:
            cout << "Enter data to be deleted: ";
            cin >> data;
            bst.root = bst.deleteNode(bst.root, data);
            cout << "Node deleted successfully." << endl;
            break;
        case 3:
            bst.displayTree();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
