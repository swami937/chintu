#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class BST {
public:
    Node* root;
    BST() { root = NULL; }

    
    Node* insert(Node* root, int val) {
        if (root == NULL) {
            Node* temp = new Node;
            temp->data = val;
            temp->left = temp->right = NULL;
            return temp;
        }
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    
    int longestPath(Node* root) {
        if (root == NULL) return 0;
        int l = longestPath(root->left);
        int r = longestPath(root->right);
        return (l > r ? l : r) + 1;
    }

    
    int findMin(Node* root) {
        if (root == NULL) return -1;
        while (root->left != NULL)
            root = root->left;
        return root->data;
    }
};

int main() {
    BST t;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        t.root = t.insert(t.root, val);
    }

    cout << "\nInorder traversal: ";
    t.inorder(t.root);

    cout << "\n\n1. Insert new node\n2. Longest path\n3. Minimum value\n";
    int ch;
    cout << "Enter choice: ";
    cin >> ch;

    switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            t.root = t.insert(t.root, val);
            cout << "Updated tree: ";
            t.inorder(t.root);
            break;

        case 2:
            cout << "Longest path length: " << t.longestPath(t.root);
            break;

        case 3:
            cout << "Minimum value in tree: " << t.findMin(t.root);
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}

