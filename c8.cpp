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





⚙️ Main Logic

Structure Node:
Holds three things:

data → value of the node

left → pointer to left child

right → pointer to right child

Class BST:

Has a pointer root (start of tree).

Contains four main functions:

a) insert() → Adds a new node in correct BST position

If root is NULL → creates new node

If value < root → goes left

If value > root → goes right

b) inorder() → Displays nodes in sorted order (Left → Root → Right).

c) longestPath() → Finds height of the tree (max depth).

d) findMin() → Traverses to the leftmost node (minimum value).

🖥️ Main Function Flow

User enters how many nodes to add and their values.

Tree is built using insert().

Displays all values using inorder().

Then menu allows to:

Insert new node

Find longest path (tree height)

Find minimum value

⏱️ Time Complexities
Operation	Time Complexity
Insert	O(h) (height of tree)
Inorder	O(n)
Find Min	O(h)
Longest Path	O(n)
