/**
 * @author   Nhat M. Nguyen
 * @created  20-04-18
 * @updated  13-09-19
**/

#include <cassert>
#include <iostream>

using namespace std;

const int MAXSIZE = 100;

struct Stack {
    int keys[MAXSIZE];
    int size = 0;

    bool isEmpty() {
        return size == 0;
    }

    void push(int key) { // Time complexity: O(1)
        keys[size] = key;
        size++;
    }

    int pop() {     // Time complexity: O(1)
        size--;
        return keys[size + 1]; 
    }
};

int main() {
    return 0;
}
