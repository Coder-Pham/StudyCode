/**
 * @author Nhat M. Nguyen
 * @date   02-06-18
**/


#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;


const int N = (int) 1e6;
vector<int> adj_lists[N];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    int num_vertices;
    cin >> num_vertices;

    int num_edges;
    cin >> num_edges;

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_lists[u].push_back(v);
    }

    // Calculate in-degree
    vector<int> in_degree(num_vertices, 0);
    
    for (int u = 0; u < num_vertices; u++) {
        for (int &v : adj_lists[u]) {
            in_degree[v]++;
        }
    }

    // Kahn's algorithm
    vector<int> result;
    queue<int> q;
    
    for (int u = 0; u < num_vertices; u++) {
        if (in_degree[u] == 0) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int &v : adj_lists[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int) result.size() != num_vertices) {
        cout << "Not a directed acrylic graph!\n";
    }
    else {
        cout << "Topological order:\n";
        for (int &u : result) {
            cout << u << " ";
        }
        cout << "\n";
    }

    return 0;
}
