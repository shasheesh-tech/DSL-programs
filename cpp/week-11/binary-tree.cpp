#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;

// Recursive tree creation
Node* insert() {
    int x;
    cout << "Enter node data (-1 for no node): ";
    cin >> x;

    if(x == -1)
        return NULL;

    Node* newNode = new Node(x);

    cout << "Enter left child of " << x << endl;
    newNode->left = insert();

    cout << "Enter right child of " << x << endl;
    newNode->right = insert();

    return newNode;
}

// Inorder LVR
void inorder(Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder VLR
void preorder(Node* root) {
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder LRV
void postorder(Node* root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Create Binary Tree\n";
    root = insert();

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}