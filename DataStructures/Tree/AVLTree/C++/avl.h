/**
 * @author Nhat M. Nguyen
 * @update 29-08-18
**/


#pragma once


#include <bits/stdc++.h>
#include "bst.h"


using namespace std;


/**
 * This code has been tested though with some small cases,
 * but it is not guaranteed to be bug-free!
**/


template<typename T>
class AVLNode {
public:
    T key;
    AVLNode* parent;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode() { // constructor for nil
        this->key = 0;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
        this->height = -1;
    }

    AVLNode(T key, AVLNode* nil) {
        this->key = key;
        this->parent = nil;
        this->left = nil;
        this->right = nil;
        this->height = -1;
    }

    void updateHeight() {
        assert(this->left != NULL);
        assert(this->right != NULL);
        this->height = max(this->left->height, this->right->height) + 1;
    }
};


template<typename T>
class AVLTree : public BSTree<T, AVLNode<T>> {
public:
    AVLTree() : BSTree<T, AVLNode<T>>() {}

    void leftRotate(AVLNode<T>* x) {
        AVLNode<T>* y = x->right;
        
        x->right = y->left;
        if (y->left != this->nil) {
            y->left->parent = x;
        }
        
        y->parent = x->parent;
        if (x->parent == this->nil) {
            this->root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right= y;
        }
                
        x->parent = y;
        y->left = x;

        x->updateHeight();
        y->updateHeight();

    }
    
    void rightRotate(AVLNode<T>* y) {
        AVLNode<T>* x = y->left;
        
        y->left = x->right;
        if (x->right != this->nil) {
            x->right->parent = y;
        }
        
        x->parent = y->parent;
        if (y->parent == this->nil) {
            this->root = x;
        }
        else if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }
        
        y->parent = x;
        x->right = y;

        x->updateHeight();
        y->updateHeight();
    }

    void rebalance(AVLNode<T>* node) {
        if (node == this->nil) return;

        node->updateHeight();

        if (node->left->height >= node->right->height + 2) {
            if (node->left->left->height >= node->left->right->height) {
                this->rightRotate(node);
            }
            else {
                this->leftRotate(node->left);
                this->rightRotate(node);
            }
        }
        else if (node->right->height >= node->left->height + 2) {
            if (node->right->right->height >= node->right->left->height) {
                this->leftRotate(node);
            }
            else {
                this->rightRotate(node->right);
                this->leftRotate(node);
            }
        }

        this->rebalance(node->parent);
    }

    void insert(AVLNode<T>* node) {
        BSTree<T, AVLNode<T>>::insert(node);
        this->rebalance(node);
    }

    void insert(T key) {
        this->insert(new AVLNode<T>(key, this->nil));
    }

    void remove(AVLNode<T>* node) {
        BSTree<T, AVLNode<T>>::remove(node);
        this->rebalance(node->parent);
    }
};
