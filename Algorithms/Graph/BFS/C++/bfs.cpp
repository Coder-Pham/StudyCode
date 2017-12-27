/**
 *  Author: Nhat M. Nguyen
 *  Date: 27-12-17
**/

#include <iostream>
#include <queue>
#include <vector>


using namespace std;


int main() {

    /*** Get number of vertices and edges ***/
    int nVertices, nEdges;
    cin >> nVertices >> nEdges;

    /*** Generate boolean vector to check visited vertices ***/
    bool visited[nVertices];
    fill(visited, visited + nVertices, false);

    /*** Get edges and generate adjacent lists ***/
    vector<int> adj[nVertices];
    for (int i = 0; i < nEdges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*** Breadth first search ***/
    queue<int> q;
    // Start at vertex 0
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        cout << u << " ";
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            // Push unvisited neighbors to the queue
            if (!visited[v]) {
                q.push(v);
            }
        }
    }
    cout << "\n";
    return 0;
}


/*
  TEST:

+ IN:
7 6
0 6
3 0
4 6
1 6
3 5
2 3 

+ OUT:
0 6 3 4 1 5 2

 */
