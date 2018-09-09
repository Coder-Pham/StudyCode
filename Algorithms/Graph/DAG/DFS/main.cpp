/**
 * @author Nhat M. Nguyen
 * @update 09-09-18
**/



#include <bits/stdc++.h>


using namespace std;


const int MAX_N_V = (int) 1e6;
const int MAX_N_E = (int) 1e6;


vector<int> adj[MAX_N_V];
int mark[MAX_N_V];
bool isDAG;
stack<int> st;


void dfs(int u) {
    if (mark[u] == 1) return;
    if (mark[u] == 0) { // back edge
        isDAG = false;
        return;
    }
    mark[u] = 0;
    for (int &v : adj[u]) {
        dfs(v);
    }
    mark[u] = 1;
    st.push(u);
}


int main() {
    int nV, nE;
    cin >> nV >> nE;

    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    fill(mark, mark + nV, -1);
    
    isDAG = true;
    for (int u = 0; u < nV && isDAG; u++) {
        dfs(u);
    }

    cout << "Topological order: \n";
    for (int i = 0; i < nV; i++) {
        cout << st.top() << '\n';
        st.pop();
    }
}
