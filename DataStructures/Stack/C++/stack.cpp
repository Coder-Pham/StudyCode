/**
 * @author Nhat M. Nguyen
 * @date   19-04-18
**/

#include <iostream>


using namespace std;


const int MAXSIZE = 100;


struct Stack {
    int key[MAXSIZE];
    int size = 0;

    bool is_empty() {
        if (this->size == 0) {
            return true;
        }
        return false;
    }

    void push(int key) { // Time complexity: O(1)
        this->key[size] = key;
        this->size++;
    }

    int pop() {     // Time complexity: O(1)
        this->size--;
        return this->key[this->size + 1]; 
    }
};


int main() {
    return 0;
}
