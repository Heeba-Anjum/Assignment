#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int a) : value(a), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->value) {
        root->left = insert(root->left, key);
    } else if (key > root->value) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to find the Lowest Common Ancestor (LCA) in a BST
Node* LCA(Node* root, int x, int y) {
    if (root == nullptr) {
        return nullptr;
    }

    if (x < root->value && y < root->value) {
        return LCA(root->left, x, y);
    } else if (x > root->value && x > root->value) {
        return LCA(root->right, x, y);
    } else {
        return root;
    }
}

int main() {
    // Reading the tree nodes from the user
    cout << "Enter the elements of the BST (enter -1 to stop): ";
    int value;
    Node* root = nullptr;
    while (true) {
       cin >> value;
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }

    // Reading the values of nodes p and q
    int x, y;
    cout << "Enter the values of nodes p and q: ";
    cin >> x >> y;

    // Finding the Lowest Common Ancestor
    Node* lca = LCA(root, x, y);

    // Displaying the result
    if (lca != nullptr) {
        cout << "The Lowest Common Ancestor of nodes " << x << " and " << y << " is: " << lca->value << endl;
    } else {
       cout << "No Lowest Common Ancestor found." << endl;
    }

    return 0;
}
