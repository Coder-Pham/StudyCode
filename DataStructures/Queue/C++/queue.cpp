/**
 * @author Nhat M. Nguyen
 * @date   20-04-18
**/

#include <iostream>


using namespace std;


const int SIZE = 100;


struct Queue {
    int head;
    int tail;
    int key[SIZE];

    void enqueue(int key) { // Time complexity: O(1)
        if (this->tail == SIZE - 1) {
            this->tail = 0;
        }
        else {
            this->tail++;
        }

        this->key[this->tail] = key;
    }

    int dequeue() {         // Time complexity: O(1)
        int key = this->key[this->head];
        if (this->head == SIZE - 1) {
            this->head = 0;
        }
        else {
            this->head++;
        }
        return key;
    }
};


int main() {
    return 0;
}
