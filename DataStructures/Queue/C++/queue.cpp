/**
 * @author   Nhat M. Nguyen
 * @created  20-04-18
 * @updated  13-09-19
**/

#include <cassert>
#include <iostream>

using namespace std;

const int CAPACITY = 100;

struct Queue {
    int keys[CAPACITY];
    int size = 0;
    int head = 0;
    int tail = CAPACITY - 1;

    bool empty() {
        return size == 0;
    }

    void enqueue(int key) { // Time complexity: O(1)
        if (tail == CAPACITY - 1) {
            tail = 0;
        }
        else {
            tail++;
        }

        keys[tail] = key;
        size++;
    }

    int dequeue() {         // Time complexity: O(1)
        assert(size > 0);
        int key = keys[head];
        
        if (head == CAPACITY - 1) {
            head = 0;
        }
        else {
            head++;
        }

        return key;
    }
};

int main() {
    return 0;
}
