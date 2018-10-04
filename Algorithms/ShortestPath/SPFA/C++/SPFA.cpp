/*
    Author: Pham Trong Nhan
    Date: 22/8/2018
    
    This method is Shortest Path Faster Algo, which developed from Bellman-Ford and DFS
    This method is really better than others when N > 500 and N < 5000 
*/

#include <iostream>
#include <algorithm> // std::fill
#include <vector>
#include <climits>

const int maxN = 5000;
const int maxQ = 10000; // Queue max

int start, end, nVertices, nEdges;
int head, tail, number; // number of value in Queue
int c[maxN][maxN];
int queue[maxQ];
std::vector<bool> Free;
std::vector<int> d;

void input()
{
    std::cin >> nVertices >> nEdges;
    for (int i = 0; i < nVertices; i++)
        for (int j = 0; j < nVertices; j++)
            if (i == j)
                c[i][j] = 0;
            else
                c[i][j] = INT_MAX;

    for (int i = 0; i < nEdges; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        c[u][v] = w;
        c[v][u] = w;
    }

    d.resize(nVertices);
    Free.resize(nVertices); // Distance to i from s
}

int PopQueue()
{
    number--;
    if (head == maxQ)
    {
        head = 1;
        return queue[maxQ];
    }
    else
    {
        head++;
        return queue[head - 1];
    }
}

void PushQueue(int v)
{
    number++;
    tail = (tail == maxQ) ? 1 : (tail + 1);
    queue[tail] = v;
}

void SPFA(int s) // Start from s
{
    // Init value for queue and others
    std::fill(d.begin(), d.end(), INT_MAX);
    std::fill(Free.begin(), Free.end(), true);

    head = 0;
    tail = 0;
    number = 1;
    queue[0] = s;
    Free[s] = false;
    d[s] = 0;

    do
    {
        int u = PopQueue();
        Free[u] = true;

        for (int v = 0; v < nVertices; v++)
            if (c[u][v] < INT_MAX)
                if (d[v] > d[u] + c[u][v])
                {
                    d[v] = d[u] + c[u][v];
                    if (Free[v])
                    {
                        PushQueue(v);
                        Free[v] = false;
                    }
                }
    } while (number != 0);
}

int main()
{
    input();
    SPFA(0);

    for (int i = 0; i < nVertices; i++)
    {
        std::cout << "D[" << i << "]= " << d[i] << std::endl;
    }

    return 0;
}