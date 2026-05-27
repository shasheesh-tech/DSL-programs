#include <iostream>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int h(Node* n) {
    return n ? n->height : 0;
}

int balance(Node* n) {
    return n ? h(n->left) - h(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if(root == NULL) return new Node(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = max(h(root->left), h(root->right)) + 1;
    int b = balance(root);

    if(b > 1 && key < root->left->data) return rightRotate(root);
    if(b < -1 && key > root->right->data) return leftRotate(root);

    if(b > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(b < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minNode(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;

        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    root->height = max(h(root->left), h(root->right)) + 1;
    int b = balance(root);

    if(b > 1 && balance(root->left) >= 0) return rightRotate(root);

    if(b > 1 && balance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(b < -1 && balance(root->right) <= 0) return leftRotate(root);

    if(b < -1 && balance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,10);
    root = insert(root,25);
    root = insert(root,35);
    root = insert(root,50);

    cout << "Inorder: ";
    inorder(root);

    if(search(root,25))
        cout << "\n25 Found";
    else
        cout << "\n25 Not Found";

    root = deleteNode(root,20);

    cout << "\nAfter Deletion Inorder: ";
    inorder(root);

    return 0;
}