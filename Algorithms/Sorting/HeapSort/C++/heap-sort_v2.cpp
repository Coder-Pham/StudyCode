/**
*   Author: Pham Trong Nhan
*   Date: 3/10/18
**/

#include <iostream>
#include <algorithm>

int *a;
// Make a heap
void heapify(int root, int endnode)
{
    int child;
    int key = a[root];
    // If not a leaf
    while (root * 2 + 1 <= endnode)
    {
        child = root * 2 + 1;
        // Check the left with the right
        if ((child < endnode) && (a[child] < a[child + 1]))
        {
            child++;
        }
        if (a[child] < key)
            break;

        a[root] = a[child];
        root = child;
    }
    a[root] = key;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    a = new int(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    // Heapify from every nodes that is not a leaf
    // Heapify from bottom-up
    for (int i = (n / 2); i >= 0; i--)
        heapify(i, n - 1);

    // Swap the largest key to the end of tree
    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        // Heapify the leftover nodes in tree
        heapify(0, i - 1);
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}
