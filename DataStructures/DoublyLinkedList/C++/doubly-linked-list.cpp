/**
 * @author Nhat M. Nguyen
 * @date   19-04-18
**/

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* prev;
    Node* next;
};


struct DoublyLinkedList {
    Node* head = NULL;

    Node* search(int key) { // Time complexity: O(n)
        Node* x = this->head;
        while (x != NULL && x->key != key) {
            x = x->next;
        }
        return x;
    }

    void insert(Node* x) { // Time complexity: O(1)
        x->prev = NULL;
        x->next = this->head;
        if (this->head != NULL) {
            this->head->prev = x;
        }
        this->head = x;
    }

    void remove(Node* x) { // Time complexity: O(1)
        if (x->prev != NULL) {
            x->prev->next = x->next;
        }
        else {
            // Special case: deleting head
            this->head = x->next;
        }

        if (x->next != NULL) {
            x->next->prev = x->prev;
        }

        delete x; x = NULL;
    }
};


int main() {
    return 0;
}
