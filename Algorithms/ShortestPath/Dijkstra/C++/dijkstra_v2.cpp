/**
 * Author:  Pham Trong Nhan
 * Date:    6/10/2018
 * Note:    This method will try to fix the previous node then move onto its decendant.
 * Assume start from 0 to every nodes
 * IMPORTANT NEVER use INT_MAX from <climits>, it makes my code wrong in very ridiculous way.
**/

#include <iostream>
#include <algorithm>
#include <vector>

const int MAX = 1e5;

int main()
{
    int nVertices, nEdges;
    std::cin >> nVertices >> nEdges;

    // Init graph
    std::vector<std::vector<int>> graph(nVertices);
    std::vector<int> dist(nVertices);
    // Fix the min value for that node
    std::vector<bool> visited(nVertices);
    std::fill(visited.begin(), visited.end(), false);

    for (int row = 0; row < nVertices; row++)
    {
        graph[row].resize(nVertices);
        std::fill(graph[row].begin(), graph[row].end(), MAX);
        graph[row][row] = 0;
    }

    for (int i = 0; i < nEdges; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for (int i = 0; i < nVertices; i++)
    {
        dist[i] = graph[0][i];
    }

    // Dijkstra
    while (true)
    {
        int u = -1;
        int min = MAX;
        // find all free nodes
        for (int i = 0; i < nVertices; i++)
            if ((!visited[i]) && (dist[i] < min))
            {
                u = i;
                min = dist[i];
            }

        // Find to the end
        if (u == -1)
        {
            break;
        }
        visited[u] = true;
        for (int v = 0; v < nVertices; v++)
        {
            if ((!visited[v]) && (graph[u][v] + dist[u] < dist[v]))
            {
                dist[v] = graph[u][v] + dist[u];
            }
        }
    }

    for (int i = 0; i < nVertices; i++)
    {
        std::cout << "D[" << i << "] = " << dist[i] << std::endl;
    }
}
