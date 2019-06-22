/**
 * @author Nhat M. Nguyen
 * @date   02-06-18
**/

#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


const int N = (int) 1e6;
vector<int> adj_lists[N];
bool visited[N];


void dfs(int u) {
    visited[u] = true;

    cout << "visiting " << u << "\n";

    for (int &v : adj_lists[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num_edges;
    cin >> num_edges;
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_lists[u].push_back(v);
        adj_lists[v].push_back(u);
    }

    fill(visited, visited + num_edges, false);

    dfs(0);

    return 0;
}
