#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Binary search tree class
class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        }
        else {
            node->right = insertNode(node->right, key);
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* minNode = getMinNode(node->right);
            node->key = minNode->key;
            node->right = deleteNode(node->right, minNode->key);
        }
        return node;
    }

    Node* getMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool searchNode(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->key == key) {
            return true;
        }
        if (key < node->key) {
            return searchNode(node->left, key);
        }
        else {
            return searchNode(node->right, key);
        }
    }

public:
    BST() {
        this->root = nullptr;
    }

    void insert(int key) {
        this->root = insertNode(this->root, key);
    }

    void remove(int key) {
        this->root = deleteNode(this->root, key);
    }

    bool search(int key) {
        return searchNode(this->root, key);
    }
};

// Test program
int main() {
    BST bst;

    // Insert some nodes
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);

    // Search for a node
    if (bst.search(7)) {
        cout << "7 is in the tree" << endl;
    }
    else {
        cout << "7 is not in the tree" << endl;
    }

    // Remove a node
    bst.remove(3);

    // Search for a node again
    if (bst.search(3)) {
        cout << "3 is in the tree" << endl;
    }
    else {
        cout << "3 is not in the tree" << endl;
    }

    return 0;
}
