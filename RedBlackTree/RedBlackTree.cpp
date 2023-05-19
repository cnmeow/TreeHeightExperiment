// Implementing Red-Black Tree in C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

typedef Node *NodePtr;

class RedBlackTree {
private:
    NodePtr root;
    NodePtr TNULL;
    
    void initializeNULLNode(NodePtr node, NodePtr parent) {
        node->data = 0;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = 0;
    }
    
    // For balancing the tree after insertion
    void insertFix(NodePtr k) {
        NodePtr u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;
                
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = 0;
    }
    
public:
    RedBlackTree() {
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }
    
    
    void leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
    
    void rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    
    // Inserting a node
    void insert(int key) {
        NodePtr node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;
        
        NodePtr y = nullptr;
        NodePtr x = this->root;
        
        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        
        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }
        
        if (node->parent == nullptr) {
            node->color = 0;
            return;
        }
        
        if (node->parent->parent == nullptr) {
            return;
        }
        
        insertFix(node);
    }
    
    NodePtr getRoot() {
        return this->root;
    }
    
    int getHeight(NodePtr root) {
        if (root != TNULL) {
            int lHeight = getHeight(root->left),
            rHeight = getHeight(root->right);
            return 1 + max(lHeight, rHeight);
        }
        return 0;
    }
};
int main() {
    ofstream fo("RedBlackHeight.txt"); // Output file
    for (int f = 1; f <= 10; ++f) {
        RedBlackTree bst;
        ifstream fi("dataset" + to_string(f) +".txt"); // Input file
        int n; fi >> n;
        
        // Add value in input file into RedBlackTree
        for (int i = 0 ; i < n; ++i) {
            int a; fi >> a; bst.insert(a);
        }
        fo << bst.getHeight(bst.getRoot()) <<'\n';
    }
}
