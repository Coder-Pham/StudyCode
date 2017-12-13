// This program implements tree traversal on a full binary tree

#include <iostream>
#include <vector>

using namespace std;


struct Vertex {
    int data = 0;
    Vertex* left = NULL;
    Vertex* right = NULL;
};


struct BinaryTree {
    Vertex* root = NULL;

    BinaryTree(Vertex* root) {
        this->root = root;
    }

    void preOrder(Vertex* v) {
        if (v == NULL) return;

        cout << v->data << " ";
        preOrder(v->left);
        preOrder(v->right);
    }

    void preOrderTraversal() {
        this->preOrder(this->root);
        cout << "\n";
    }

    void inOrder(Vertex* v) {
        if (v == NULL) return;

        this->inOrder(v->left);
        cout << v->data << " ";
        this->inOrder(v->right);
    }

    void inOrderTraversal() {
        this->inOrder(this->root);
        cout << "\n";
    }

    void postOrder() {
        if (v == NULL) return;

        this->postOrder(v->left);
        this->postOrder(v->right);
        cout << v->data << " ";
    }

    void postOrderTraversal() {
        this->postOrder(this->root);
        cout << "\n";
    }
};


int main() {
    // Get the number of layers
    int nLayers = 0;
    cin >> nLayers;

    // Create a root
    Vertex* root = new Vertex;
    BinaryTree* binaryTree = new BinaryTree(root);

    // Get the root's data
    int tmp = 0;
    cin >> tmp;
    root->data = tmp;

    // Get all remaining vertices
    vector<Vertex*> lastLayer;
    lastLayer.push_back(root);

    for (int i = 1; i < nLayers; i++) {
        vector<Vertex*> currentLayer;
        for (int j = 0; j < (int) lastLayer.size(); j++) {
            // Left vertex
            cin >> tmp;
            lastLayer[j]->left = new Vertex;
            lastLayer[j]->left->data = tmp;
            currentLayer.push_back(lastLayer[j]->left);
            // Right vertex
            cin >> tmp;
            lastLayer[j]->right = new Vertex;
            lastLayer[j]->right->data = tmp;
            currentLayer.push_back(lastLayer[j]->right);
        }
        lastLayer = currentLayer;
    }

    // Traversal
    cout << "Preorder traversal: ";
    binaryTree->preOrderTraversal();
    cout << "Inorder traversal: ";
    binaryTree->inOrderTraversal();
    cout << "Postorder traversal: ";
    binaryTree->postOrderTraversal();

    return 0;
}