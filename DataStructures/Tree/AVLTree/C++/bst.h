/**
 * @author Nhat M. Nguyen
 * @update 29-08-18
**/


#pragma once


#include <bits/stdc++.h>


using namespace std;


/**
 * This BSTree class is intended to be used as the parent class
 * for other types of tree: AVL, Red-Black, etc.
**/


template<typename T>
class BSTNode {
public:
    T key;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;

    BSTNode() { // constructor for nil
        this->key = 0;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }

    BSTNode(T key, BSTNode* nil) {
        this->key = key;
        this->parent = nil;
        this->left = nil;
        this->right = nil;
    }
};


template<typename T, typename Node=BSTNode<T>>
class BSTree {
public:
    Node* root;
    int size;
    Node* nil; // sentinel to handle special cases

    BSTree() {
        this->nil = new Node();
        this->root = this->nil;
        this->size = 0;
    }

    Node* search(T key) {
        Node* node = this->root;
        while (node != this->nil && node->key != key) {
            if (key < node->key) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return node;
    }

    Node* min() {
        Node* node = this->root;
        while (node->left != this->nil) {
            node = node->left;
        }
        return node;
    }

    Node* min(Node* root) {
        Node* node = root;
        while (node->left != this->nil) {
            node = node->left;
        }
        return node;
    }
    
    Node* max() {
        Node* node = this->root;
        while (node->right != this->nil) {
            node = node->right;
        }
        return node;
    }
    
    Node* max(Node* root) {
        Node* node = root;
        while (node->right != this->nil) {
            node = node->right;
        }
        return node;
    }
    
    Node* prev(Node* node) {
        if (node->left != this->nil) {
            return this->max(node->left);
        }

        Node* p = node->parent;
        while (p != this->nil && node == p->left) {
            node = p;
            p = p->parent;
        }
        return p;
    }
    
    Node* next(Node* node) {
        if (node->right != this->nil) {
            return this->min(node->right);
        }

        Node* p = node->parent;
        while (p != this->nil && node == p->right) {
            node = p;
            p = p->parent;
        }
        return p;
    }

    void insert(Node* node) {
        Node* p = this->nil;
        Node* tmp = this->root;

        while (tmp != this->nil) {
            p = tmp;

            if (node->key < tmp->key) {
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }
        
        if (p == this->nil) {
            this->root = node;
            node->parent = this->nil;
        }
        else if (node->key < p->key) {
            p->left = node;
            node->parent = p;
        }
        else {
            p->right = node;
            node->parent = p;
        }

        this->size++;
    }
        
    void insert(T key) {
        this->insert(new Node(key, this->nil));
    }
    
    void transplant(Node* node, Node* child) {        
        if (node->parent == this->nil) {
            this->root = child;
        }
        else if (node == node->parent->left) {
            node->parent->left = child;
        }
        else if (node == node->parent->right) {
            node->parent->right = child;
        }
        
        if (child != this->nil) {
            child->parent = node->parent;
        }
    }
    
    void remove(Node* node) {
        if (node == this->nil) {
            return;
        }
        
        if (node->left == this->nil) {
            this->transplant(node, node->right);
        }
        else if (node->right == this->nil) {
            this->transplant(node, node->left);
        }
        else {
            /**
             * If node has both children, there are two different cases:
             * 1. node's successor is node's right child. simply replace
             *    node with its right child.
             * 2. node's successor is min of node's right branch.
             *    + step 1: replace successor with its right child
             *    + step 2: replace node with successor
            **/
            Node* successor = this->min(node->right);
            
            if (successor != node->right) {
                this->transplant(successor, successor->right);
                successor->right = node->right;
                successor->right->parent = successor;
            }
            
            this->transplant(node, successor);
            successor->left = node->left;
            successor->left->parent = successor;
        }

        delete node;
        node = this->nil;

        this->size--;
    }

    void preOrder(Node* node) {
        if (node == this->nil) return;

        cout << node->key << ' ';
        this->preOrder(node->left);
        this->preOrder(node->right);
    }

    void preOrderTraverse() {
        this->preOrder(this->root);
        cout << '\n';
    }

    void inOrder(Node* node) {
        if (node == this->nil) return;

        this->inOrder(node->left);
        cout << node->key << ' ';
        this->inOrder(node->right);
    }

    void inOrderTraverse() {
        this->inOrder(this->root);
        cout << '\n';
    }

    void postOrder(Node* node) {
        if (node == this->nil) return;

        this->postOrder(node->left);
        cout << node->key << ' ';
        this->postOrder(node->right);
    }

    void postOrderTraverse() {
        this->postOrder(this->root);
        cout << '\n';
    }

    #define GAPLENGTH 8

    // void printNode(Node* node, int nodeLevel, stack<int> &levelStack) {
    //     if (node == this->nil) return;

    //     int* stackEnd = &levelStack.top() + 1;
    //     int* stackBegin = stackEnd - levelStack.size();
    //     vector<int> pending(stackBegin, stackEnd);
    //     int k = 0;

    //     for (int i = 0; i < nodeLevel; i++) {
    //         if (k < (int) pending.size() && pending[k] == i) {
    //             cout << "│";
    //             for (int j = 1; j < GAPLENGTH; j++) {
    //                 cout << ' ';
    //             }
    //             k++;
    //         }
    //         else {
    //             for (int j = 0; j < GAPLENGTH; j++) {
    //                 cout << ' ';
    //             }
    //         }
    //     }

    //     if (nodeLevel == 0) {
    //         cout << "└─";
    //         cout << "[root : ";
    //     }
    //     else {
    //         if (node == node->parent->left) {
    //             if (node->parent->right == this->nil) {
    //                 cout << "└─";
    //             }
    //             else {
    //                 cout << "├─";
    //                 levelStack.push(nodeLevel);
    //             }
    //             cout << "[left : ";
    //         }
    //         else {
    //             cout << "└─";
    //             cout << "[right: ";
    //             assert(levelStack.top() == nodeLevel);
    //             levelStack.pop();
    //         }
    //     }

    //     cout << node->key << ']' << '\n';
    //     this->printNode(node->left, nodeLevel + 1, levelStack);
    //     this->printNode(node->right, nodeLevel + 1, levelStack);
    // }

    void print() {
        stack<int> levelStack;
        this->printNode(this->root, 0, levelStack);
    }
};
