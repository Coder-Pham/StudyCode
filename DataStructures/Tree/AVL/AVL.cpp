/** 
 * Author:  Pham T. Nhan
 * Date:    17/12/2018
 * Topic:   AVL Tree
 */

#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node
{
    T key;
    Node *left;
    Node *right;
    int height;
};

template <typename T>
Node<T> *newNode(T value)
{
    Node<T> *node = new Node<T>;
    node->key = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

template <typename T>
int height(Node<T> *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

template <typename T>
Node<T> *rightRotate(Node<T> *root)
{
    Node<T> *child = root->left;
    Node<T> *grand = child->right;

    child->right = root;
    root->left = grand;

    // Update heights
    root->height = max(height(root->left), height(root->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    return child;
}

template <typename T>
Node<T> *leftRotate(Node<T> *root)
{
    Node<T> *child = root->right;
    Node<T> *grand = child->left;

    child->left = root;
    root->right = grand;

    // Update heights
    root->height = max(height(root->left), height(root->right)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;
    return child;
}

template <typename T>
Node<T> *reBalance(Node<T> *root, T value)
{
    // Balance
    int balance;
    if (root == NULL)
        balance = 0;
    else
        balance = height(root->left) - height(root->right);

    // Left Left -> Right Rotate
    if (balance > 1 && value < root->left->key)
        return root = rightRotate(root);
    // Right Right -> Left Rotate
    if (balance < -1 && value > root->right->key)
        return root = leftRotate(root);
    // Left Right
    if (balance > 1 && value > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left
    if (balance < -1 && value < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

template <typename T>
Node<T> *insertNode(Node<T> *root, T value)
{
    // SIMPLE BST INSERT
    if (root == NULL)
        return newNode(value);
    if (root->key > value)
        root->left = insertNode(root->left, value);
    else if (root->key < value)
        root->right = insertNode(root->right, value);

    root->height = max(height(root->left), height(root->right)) + 1;
    return reBalance(root, value);
}

// Min value of right tree
template <typename T>
Node<T> *minValueNode(Node<T> *right)
{
    Node<T> *current = right;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Assign Min value of right subtree to current deleted node
template <typename T>
Node<T> *deleteNode(Node<T> *root, T value)
{
    if (root == NULL)
        return root;
    if (root->key > value)
        root->left = deleteNode(root->left, value);
    else if (root->key < value)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            Node<T> *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node<T> *temp = root->left;
            delete root;
            return temp;
        }
        Node<T> *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    return reBalance(root, value);
}

template <typename T>
void traversalPre(Node<T> *root)
{
    if (root != NULL)
    {
        cout << root->key << endl;
        traversalPre(root->left);
        traversalPre(root->right);
    }
}

int main()
{
    Node<int> *root = NULL;
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    root = insertNode(root, 50);
    root = insertNode(root, 65);
    root = insertNode(root, 45);

    root = deleteNode(root, 70);

    traversalPre(root);
    return 0;
}