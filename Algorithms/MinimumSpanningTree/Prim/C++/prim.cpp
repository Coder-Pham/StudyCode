/**
 * Author: Nhat M. Nguyen
 * Date: 22-12-17
**/

#include <functional> // std::greater
#include <iostream>
#include <queue>   // std::priority_queue
#include <vector>
#include <utility> // std::pair


using namespace std;


vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap


void prim(int u, vector<pair<int, int>> adj) {
    visited[u] = true;
    for (int i = 0; i < (int) adj.size(); i++) {
        pair<int, int> edge = adj[i];
        int v = edge.second;
        if (!visited[v]) {
            pq.push(edge);
        }
    }
}


int main() {

    /*** Get number of vertices, number of edges ***/
    int nVertices, nEdges;
    cin >> nVertices >> nEdges;

    /*** Get each edge: u, v, w and generate adjacent lists ***/
    vector<pair<int, int>> adj[nVertices];
    for (int i = 0; i < nEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    /*** Generate boolean vector to check if vertices have been visited ***/
    for (int i = 0; i < nVertices; i++) {
        visited.push_back(false);
    }

    /*** Prim's Minimum Spanning Tree ***/
    int minCost = 0;

    visited[0] = true;
    prim(0, adj[0]);

    while (!pq.empty()) {
        pair<int, int> edge = pq.top();
        pq.pop();
        int v = edge.second;
        if (visited[v]) continue;
        int w = edge.first;
        minCost += w;
        prim(v, adj[v]);
    }

    cout << "Min Cost: " << minCost << "\n";

    return 0;
}

/*
  TEST
+ IN:
7 10
0 1 4
0 3 1
1 2 5
1 3 10
1 4 4
2 4 1
3 5 3
4 5 5
4 6 10
5 6 10
+ OUT:
Min cost: 23
*/