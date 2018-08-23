/**
 * @author Nhat M. Nguyen
 * @date   23-08-18
**/


#include <bits/stdc++.h>


using namespace std;


template<typename T>
class BinarySearchTree {
public:
    struct Node {
        T key;
        Node* parent;
        Node* left;
        Node* right;
    
        Node(T key) {
            this->key = key;
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
        }
    };
    
    Node* root;
    
    BinarySearchTree() {
        this->root = NULL;
    }
    
    Node* search(T key) {
        Node* node = this->root;
        while (node != NULL && node->key != key) {
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
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    
    Node* min(Node* root) {
        Node* node = root;
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    
    Node* max() {
        Node* node = this->root;
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    }
    
    Node* max(Node* root) {
        Node* node = root;
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    }
    
    Node* prev(Node* node) {
        if (node->left != NULL) {
            return this->max(node->left);
        }

        Node* p = node->parent;
        while (p != NULL && node == p->left) {
            node = p;
            p = p->parent;
        }
        return p;
    }
    
    Node* next(Node* node) {
        if (node->right != NULL) {
            return this->min(node->right);
        }

        Node* p = node->parent;
        while (p != NULL && node == p->right) {
            node = p;
            p = p->parent;
        }
        return p;
    }

    void insert(Node* node) {
        Node* p = NULL;
        Node* tmp = this->root;

        while (tmp != NULL) {
            p = tmp;

            if (node->key < tmp->key) {
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }
        
        if (p == NULL) {
            this->root = node;
            node->parent = NULL;
        }
        else if (node->key < p->key) {
            p->left = node;
            node->parent = p;
        }
        else {
            p->right = node;
            node->parent = p;
        }
    }
        
    void insert(T key) {
        this->insert(new Node(key));
    }
    
    void transplant(Node* node, Node* child) {        
        if (node->parent == NULL) {
            this->root = child;
        }
        else if (node == node->parent->left) {
            node->parent->left = child;
        }
        else if (node == node->parent->right) {
            node->parent->right = child;
        }
        
        if (child != NULL) {
            child->parent = node->parent;
        }
    }
    
    void remove(Node* node) {
        if (node == NULL) {
            return;
        }
        
        if (node->left == NULL) {
            this->transplant(node, node->right);
            
            delete node;
            node = NULL;
        }
        else if (node->right == NULL) {
            this->transplant(node, node->left);
            
            delete node;
            node = NULL;
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
            
            delete node;
            node = NULL;
        }
    }
};
