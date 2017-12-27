/**
 *  Author: Nhat M. Nguyen
 *  Date: 27-12-17
**/

#include <algorithm> // std::fill
#include <iostream>
#include <utility> // std::pair
#include <vector>


using namespace std;


const int INF = (int) 1e6;
vector<vector<int>> dist;


int main() {

    /*** Get number of vertices and edges ***/
    int nVertices, nEdges;
    cin >> nVertices >> nEdges;

    /*** Generate distance matrix ***/
    dist.resize(nVertices);
    for (int i = 0; i < nVertices; i++) {
        dist[i].resize(nVertices);
        fill(dist[i].begin(), dist[i].end(), INF);
    }

    for (int i = 0; i < nVertices; i++) {
        dist[i][i] = 0;
    }

    /*** Get edges and generate fill distance matrix ***/
    for (int i = 0; i < nEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    /*** Floyd-Warshall ***/
    for (int k = 0; k < nVertices; k++) {
        for (int i = 0; i < nVertices; i++) {
            for (int j = 0; j < nVertices; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    /*** Output ***/
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
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
0 2 9 1 4 5 
2 0 9 3 4 7 
9 9 0 8 5 7 
1 3 8 0 3 4 
4 4 5 3 0 7 
5 7 7 4 7 0

 */