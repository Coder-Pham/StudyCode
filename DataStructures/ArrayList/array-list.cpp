#include <cassert>
#include <cstdio>
#include <cstring>


template <typename T>
struct ArrayList {
    static const int DEFAULT_CAPACITY = 128;
    int capacity;
    int size;
    T* keys;

    ArrayList() {
        this->capacity = DEFAULT_CAPACITY;
        this->keys = new T[this->capacity];
        this->size = 0;
    }

    void reallocate() {
        T new_capacity = this->capacity * 2;
        T* new_keys = new T[new_capacity];
        memmove(new_keys, this->keys, this->capacity * sizeof(T));
        delete [] this->keys;
        this->keys = new_keys;
        this->capacity = new_capacity;
    }

    void push(T key) {
        if (this->size == this->capacity) {
            this->reallocate();
        }
        this->keys[this->size] = key;
        this->size++;
    }

    void pop() {
        assert(this->size > 0);
        this->size--;
    }

    void add(T key, int pos) {
        assert(pos >= 0 && pos <= this->size);
        if (this->size == this->capacity) {
            this->reallocate();
        }
        memmove(this->keys + pos + 1, this->keys + pos, (this->size - pos) * sizeof(T));
        this->keys[pos] = key;
        this->size++;
    }

    void remove(int pos) {
        assert(pos >= 0 && pos <= this->size);
        memmove(this->keys + pos, this->keys + pos + 1, (this->size - pos - 1) * sizeof(T));
        this->size--;
    }

    void print() {
        if (this->size > 0) {
            printf("[");
            for (int i = 0; i < this->size - 1; i++) {
                printf("%d, ", this->keys[i]);
            }
            printf("%d]\n", this->keys[this->size - 1]);
        }
        else {
            printf("[]\n");
        }
    }

    T& operator [] (int i) {
        return this->keys[i];
    }

    ~ArrayList() {
        delete[] this->keys;
    }
};


int main() {
    ArrayList<int> a;
    for (int i = 0; i < 10; i++) {
        a.push(i);
    }
    return 0;
}
