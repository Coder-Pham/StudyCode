/**
 * @author Nhat M. Nguyen
 * @update 10-09-18
**/


/**
 * Implementation of Strongly Connected Components - Kosaraju's algorithm
 * Time complexity: O(V + E) <- DFS twice
**/


#include <bits/stdc++.h>


using namespace std;


const int MAX_V = (int) 1e3;
const int MAX_E = (int) 1e3;
int nV, nE;
vector<int> adj[MAX_V];
vector<int> adjReverse[MAX_V];
stack<int> reverseOrder;
int mark[MAX_V];
int leaders[MAX_V];
vector<vector<int>> components;


void reverseGraph() {
    for (int u = 0; u < nV; u++) {
        for (int &v : adj[u]) {
            adjReverse[v].push_back(u);
        }
    }
}


void dfsForward(int u) {
    assert(mark[u] == 0);
    mark[u] = 1;

    for (int &v : adj[u]) {
        if (mark[v] == 0) {
            dfsForward(v);
        }
    }

    reverseOrder.push(u);
}


void dfsBackward(int u, int leader, vector<int> &component) {
    assert(mark[u] == 1);
    mark[u] = 0;
    leaders[u] = leader;
    component.push_back(u);

    for (int &v : adjReverse[u]) {
        if (mark[v] == 1) {
            dfsBackward(v, leader, component);
        }
    }
}


void scc() { // Kosaraju's algorithm
    fill(mark, mark + nV, 0);
    for (int u = 0; u < nV; u++) {
        if (mark[u] == 0) {
            dfsForward(u);
        }
    }

    reverseGraph();

    while (!reverseOrder.empty()) {
        int u = reverseOrder.top();
        reverseOrder.pop();
        
        if (mark[u] == 1) {
            vector<int> component;
            dfsBackward(u, u, component);
            components.emplace_back(component);
        }
    }
}


int main() {
    cin >> nV >> nE;
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    scc();
    cout << "Number of SCCs: " << components.size() << '\n';

    cout << "SCCs: \n";
    for (vector<int> &component : components) {
        for (int &u : component) {
            cout << u << ' ';
        }
        cout << '\n';
    }

    cout << "Leader of each vertex: \n";
    for (int i = 0; i < nV; i++) {
        cout << i << " <- " << leaders[i] << '\n';
    }

    return 0;
}


/*
  Sample test case:
 * INPUT
8 14
0 1
1 2
1 4
1 5
2 3
2 6
3 2
3 7
4 0
4 5
5 6
6 5
7 3
7 6
 * OUTPUT
Number of SCCs: 3
SCCs: 
0 4 1 
2 3 7 
6 5 
Leader of each vertex: 
0 <- 0
1 <- 0
2 <- 2
3 <- 2
4 <- 0
5 <- 6
6 <- 6
7 <- 2
 */
