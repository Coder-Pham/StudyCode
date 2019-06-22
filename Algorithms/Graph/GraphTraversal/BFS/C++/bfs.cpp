/**
 * @author Nhat M. Nguyen
 * @update 30-11-2018
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int nv, ne;
    cin >> nv >> ne;

    bool visited[nv];
    fill(visited, visited + nv, false);

    /*** Get edges and generate adjacent lists ***/
    vector<int> adj[nv];

    for (int i = 0; i < ne; i++) {
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

        for (int &v : adj[u]) {
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
