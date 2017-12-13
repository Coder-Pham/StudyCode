#include <iostream>

#define debug(x) { cerr << #x << " = " << (x) << "\n"; }

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int _data, Node* _next) {
        data = _data;
        next = _next;
    }
};

struct LinkedList {
    Node* head = NULL;
    Node* tail = NULL;
    
    void insertToEnd(int data) {
        if (tail == NULL) {
            head = new Node(data, NULL);
            tail = head;
        }
        else {
            tail->next = new Node(data, NULL);
            tail = tail->next;
        }
    }

    void insertToStart(int data) {
        head = new Node(data, head);
    }

    void insertToPos(int pos, int data) {
        if (pos == 0) {
            insertToStart(data);
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        temp = new Node(data, temp);
        prev->next = temp;
    }

    void deleteFromStart() {
        Node* temp = head;
        head = head->next;
        delete[] temp;
    }

    void deletePos(int pos) {
        if (pos == 0) {
            deleteFromStart();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete[] temp;
    }

    void iterReverse() {
        Node* temp = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (temp != NULL) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        swap(head, tail);
    }

    void show() {
        if (tail == NULL) {
            cout << "The linked list is currently empty! \n";
            return;
        }

        Node* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            cout << "Node number: " << cnt << "\t Data: " << temp->data << "\n";
            temp = temp->next;
            cnt++;
        }
    }

    void recursiveShow(Node* p) {
        if (p == NULL) return;
        cout << "Data: " << p->data << "\n";
        recursiveShow(p->next);
    }

    void recursiveShowReverse(Node* p) {
        if (p == NULL) return;
        recursiveShowReverse(p->next);
        cout << "Data: " << p->data << "\n";
    }
};

int main() {
    LinkedList linkedList;
    for (int i = 0; i < 10; i++) {
        linkedList.insertToEnd(i);
    }
    linkedList.recursiveShow(linkedList.head);
    cout << endl;
    linkedList.recursiveShowReverse(linkedList.head);
    return 0;
}
