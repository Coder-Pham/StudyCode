/**
 *  Author: Nhat M. Nguyen
 *  Date: 27-12-17
 *  Note: this is the improved version of dijkstra - by implementing priority-queue
**/

#include <algorithm> // std::fill
#include <iostream>
#include <queue> //std::priority_queue
#include <utility> // std::pair
#include <vector>


using namespace std;


const int INF = (int) 1e6; // Infinite distance: should be > max_w * max_nEdges
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


void relax(int u, int v, int w) {
    if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
    }
}


int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /*** Get number of vertices and edges ***/
    int nVertices, nEdges;
    cin >> nVertices >> nEdges;

    /*** Get edges and generate adjacent lists ***/
    vector<pair<int, int>> adj[nVertices];
    for (int i = 0; i < nEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    /*** Generate distance array ***/
    dist.resize(nVertices);
    fill(dist.begin(), dist.end(), INF);


    /*** Generate boolean vector to check visited vertices ***/
    bool visited[nVertices];
    fill(visited, visited + nVertices, false);

    /*** Dijkstra ***/
    dist[0] = 0;
    pq.push(make_pair(dist[0], 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;        
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (visited[v]) continue;
            relax(u, v, w);
        }
    }

    for (int i = 0; i < nVertices; i++) {
        printf("Dist[%d] = %d\n", i, dist[i]);
    }
    return(0);
}


/*
  TEST:

+ IN:
6 7
0 3 1
0 1 2
3 4 3
1 4 4
3 5 4
4 2 5
5 2 7

+ OUT:
Dist[0] = 0
Dist[1] = 2
Dist[2] = 9
Dist[3] = 1
Dist[4] = 4
Dist[5] = 5

 */

