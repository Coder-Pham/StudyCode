/**
 *  Author: Pham Trong Nhan 
 *  Date: 3/10/18
**/

// This is an improvement in finding the smallest edge in graph by HEAPSORT
// Because HEAPSORT find the smallest element in heap at a time. Sort from smaller to bigger.
// After find, check it in the spanning tree

#include <iostream>
#include <algorithm>
#include <vector>

struct TEdge
{
    int u, v, w; // Vertices and weight
};

std::vector<TEdge> graph;
std::vector<int> parent; // parent[v] is parent of v, parent[v] = negative => number of children
int n, m;

void heapify(int root, int endnode)
{
    int child;
    TEdge key = graph[root];
    while (root * 2 + 1 < endnode)
    {
        child = root * 2 + 1;
        if ((child < endnode) && (graph[child].w > graph[child + 1].w))
        {
            child++;
        }
        if (graph[child].w >= key.w)
        {
            break;
        }

        graph[root] = graph[child];
        root = child;
    }
    graph[root] = key;
}

int findParent(int vertex)
{
    while (parent[vertex] > 0)
    {
        vertex = parent[vertex];
    }
    return vertex;
}

void UnionTree(int root1, int root2)
{
    // Bigger tree is parent of smaller tree
    int temp = parent[root1] + parent[root2];

    if (parent[root1] < parent[root2])
    {
        parent[root2] = root1;
        parent[root1] = temp;
    }
    else
    {
        parent[root1] = root2;
        parent[root2] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int count = 0;
    int total = 0;

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        graph.resize(i + 1);
        std::cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }
    // All nodes are unconnected
    parent.resize(n, -1);

    for (int i = m / 2; i >= 0; i--)
    {
        heapify(i, n - 1);
    }

    for (int i = m - 1; i >= 0; i--)
    {
        TEdge temp = graph[0];
        graph[0] = graph[i];
        graph[i] = temp;
        heapify(0, i - 1);

        int root1 = findParent(graph[i].u);
        int root2 = findParent(graph[i].v);
        if (root1 != root2)
        {
            count++;
            total += graph[i].w;
            if (count == n - 1)
            {
                break;
            }
            UnionTree(root1, root2);
        }
    }

    std::cout << "Weight: " << total;
    return 0;
}
