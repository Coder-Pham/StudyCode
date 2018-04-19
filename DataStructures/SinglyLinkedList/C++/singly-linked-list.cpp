/**
 * @author Nhat M. Nguyen
 * @date   21-11-17
**/


#include <iostream>


using namespace std;


struct Node {
    int key;
    Node* next;

    Node(int _key, Node* _next) {
        key = _key;
        next = _next;
    }
};


struct SinglyLinkedList {
    Node* head = NULL;
    Node* tail = NULL;
    
    void insert(int key) {
        if (tail == NULL) {
            head = new Node(key, NULL);
            tail = head;
        }
        else {
            tail->next = new Node(key, NULL);
            tail = tail->next;
        }
    }

    void insert_head(int key) {
        head = new Node(key, head);
    }

    void insert_pos(int pos, int key) {
        if (pos == 0) {
            insert(key);
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        temp = new Node(key, temp);
        prev->next = temp;
    }

    void delete_head() {
        Node* temp = head;
        head = head->next;
        delete temp; temp = NULL;
    }

    void delete_pos(int pos) {
        if (pos == 0) {
            delete_head();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp; temp = NULL;
    }

    /** 
     *  Search
     *  Time complexity: O(n)
    **/
    Node* search(int key) {
        Node* tmp = this->head;
        while (tmp != NULL && tmp->key != key) {
            tmp = tmp->next;
        }
        return tmp;
    }

    void reverse() {
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
            cout << "Node number: " << cnt << "\t Key: " << temp->key << "\n";
            cnt++;
            temp = temp->next;
        }
    }

    void recursive_show(Node* p) {
        if (p == NULL) return;
        cout << "Data: " << p->key << "\n";
        recursive_show(p->next);
    }

    void recursive_show_reverse(Node* p) {
        if (p == NULL) return;
        recursive_show_reverse(p->next);
        cout << "Data: " << p->key << "\n";
    }
};

int main() {
    SinglyLinkedList linkedList;
    for (int i = 0; i < 10; i++) {
        linkedList.insert(i);
    }
    linkedList.recursive_show(linkedList.head);
    cout << endl;
    linkedList.recursive_show_reverse(linkedList.head);
    return 0;
}
