#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); 
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value); 
    } else {
        root->right = insert(root->right, value); 
    }
    return root;
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
