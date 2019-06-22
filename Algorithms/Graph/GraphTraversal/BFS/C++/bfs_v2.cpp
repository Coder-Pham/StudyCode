/** 
 * Author:  Pham Trong Nhan
 * Date:    6/10/2018
**/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int nVertices, nEdges;
    std::cin >> nVertices >> nEdges;

    std::vector<int> graph[nVertices];
    std::vector<int> visited(nVertices);
    std::fill(visited.begin(), visited.end(), false);
    std::queue<int> q;

    for (int i = 0; i < nEdges; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int u = q.front();
        std::cout << u << " ";
        q.pop();
        for (auto i : graph[u])
        {
            if (!visited[i])
            {
                visited[i] = false;
                q.push(i);
            }
        }
    }
    return 0;
}
