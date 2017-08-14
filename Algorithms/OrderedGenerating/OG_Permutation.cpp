#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n;

void init (vector<int> &v) {
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
}

void printSeq(vector<int> v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int lastDecElement(vector<int> v) {
    int i = n - 1;
    while ((i > 0) && (v[i - 1] > v[i])) {
        i--;
    }
    return i;
}

void reverseSubSeq(vector<int> &v, int start) {
    // reverse the subsequence of v
    // starting at v[start]
    int left = start;
    int right = n - 1;
    while (left < right) {
        swap(v[left], v[right]);
        left++; right--;
    }
}

void ogPerm(vector<int> &v) {
    // print current sequence
    printSeq(v);

    // check if the current sequence is the last
    int p = lastDecElement(v);
    if (p == 0) return;

    // generate the next sequence if any
    int i = n - 1;
    while (v[p - 1] > v[i]) {
        i--;
    }
    swap(v[i], v[p - 1]); 
    reverseSubSeq(v, p);

    // keep on generating
    ogPerm(v);
}

int main() {
    scanf("%d", &n);
    vector<int> v(n);
    init(v);
    ogPerm(v);
    return 0;
}
