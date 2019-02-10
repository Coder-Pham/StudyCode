/**
 * @author Nhat M. Nguyen
 * @update 09-01-2019
**/

/**
 * Yen's algorithm for finding k shortest paths in a graph
 * Info: https://en.wikipedia.org/wiki/Yen%27s_algorithm
**/

#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    int u;
    int d;
    Vertex(int u, int d) : u(u), d(d) {}
    bool operator<(const Vertex& other) const;
};

struct Route {
    int d;
    vector<int> nodes;
    Route() : d(0), nodes() {}
    Route(int d, vector<int> nodes) : d(d), nodes(move(nodes)) {}

    int length() const;
    void addNode(int v);
    bool operator<(const Route& other) const;
    Route operator+(const Route& other);
    int& operator[](int index);
    int operator[](int index) const;
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<vector<int>> adj;
vector<int> removed;
vector<vector<int>> weight;
int nV;
int nE;
const int INF = (int) 1e6;

// Vertex
bool Vertex::operator<(const Vertex& other) const {
    return d > other.d; // min-heap
}

// Route
int Route::length() const {
    return nodes.size();
}

bool Route::operator<(const Route &other) const {
    return d > other.d; // min-heap
}

void Route::addNode(int v) {
    nodes.push_back(v);
    int numNodes = nodes.size();
    if (numNodes == 1) {
        d = 0;
    }
    else {
        d += weight[nodes[numNodes - 2]][nodes[numNodes - 1]];
    }
}

int& Route::operator[](int index) {
    return nodes[index];
}

int Route::operator[](int index) const {
    return nodes[index];
}

Route Route::operator+(const Route &other) {
    assert(nodes[length() - 1] == other.nodes[0]);
    Route newRoute;
    for (int node : nodes) {
        newRoute.addNode(node);
    }
    for (int i = 1; i < other.length(); i++) {
        newRoute.addNode(other[i]);
    }
    return newRoute;
}

ostream& operator<<(ostream& os, const Route& route) {
    os << "Route: [ distance = " << route.d << ", ";
    os << "nodes = ";
    for (int i = 0; i < route.length(); i++) {
        os << (char) (route[i] + 'C') << ' ';
    }
    os << "]\n";
    return os;
}

Route dijkstra(int source, int sink) {
    vector<int> dist(nV, INF);
    vector<int> parent(nV, -1);

    priority_queue<Vertex> pqueue;
    dist[source] = 0;
    pqueue.emplace(source, 0);

    while (!pqueue.empty()) {
        int u = pqueue.top().u;
        pqueue.pop();

        for (int& v : adj[u]) {
            if (removed[v]) continue;
            if (weight[u][v] >= INF) continue;

            if (dist[u] + weight[u][v] < dist[v]) {
                dist[v] = dist[u] + weight[u][v];
                parent[v] = u;
                pqueue.emplace(v, dist[v]);
            }
        }
    }

    vector<int> nodes;
    int node = sink;

    while (true) {
        nodes.push_back(node);
        node = parent[node];
        if (node == source) break;
        if (node == -1) {
            return Route(0, vector<int>());
        }
    }

    nodes.push_back(source);
    reverse(nodes.begin(), nodes.end());

    return Route(dist[sink], nodes);
}

vector<Route> yenKSP(int source, int sink, int k) {
    vector<Route> kShortestRoutes;
    priority_queue<Route> candidatePQueue;

    Route shortestRoute = dijkstra(source, sink);

    if (shortestRoute.d == 0) return kShortestRoutes;

    kShortestRoutes.push_back(shortestRoute);

    for (int ki = 1; ki < k; ki++) {
        Route prevRoute = kShortestRoutes[ki - 1];
        Route rootRoute;

        for (int spurIndex = 0; spurIndex < prevRoute.length() - 1; spurIndex++) {
            int spurNode = prevRoute[spurIndex];
            rootRoute.addNode(spurNode);

            vector<Edge> removedEdges;

            for (Route& route : kShortestRoutes) {
                bool same = true;

                for (int i = 0; i <= spurIndex; i++) {
                    if (route[i] != rootRoute[i]) {
                        same = false;
                        break;
                    }
                }

                if (same) {
                    int u = route[spurIndex];
                    int v = route[spurIndex + 1];
                    removedEdges.emplace_back(u, v, weight[u][v]);
                    weight[u][v] = INF;
                }
            }

            for (int i = 0; i < rootRoute.length() - 1; i++) {
                removed[rootRoute[i]] = true;
            }

            Route spurRoute = dijkstra(spurNode, sink);
            if (spurRoute.d != 0 && spurRoute.d < INF && rootRoute.d < INF) {
                Route candidateRoute = rootRoute + spurRoute;
                candidatePQueue.push(candidateRoute);
            }

            for (Edge& edge : removedEdges) {
                weight[edge.u][edge.v] = edge.w;
            }

            for (int i = 0; i < rootRoute.length() - 1; i++) {
                removed[rootRoute[i]] = false;
            }
        }

        Route candidateRoute;

        while (!candidatePQueue.empty()) {
            Route tryRoute = candidatePQueue.top();
            candidatePQueue.pop();
            bool duplicates = false;
            for (Route& route : kShortestRoutes) {
                if (route.nodes == tryRoute.nodes) {
                    duplicates = true;
                    break;
                }
            }
            if (!duplicates) {
                candidateRoute = tryRoute;
                break;
            }
        }

        if (candidateRoute.d == 0) break;

        kShortestRoutes.push_back(candidateRoute);
    }

    return kShortestRoutes;
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> nV >> nE;
    adj.resize(nV);
    weight.assign(nV, vector<int>(nV, INF));
    removed.assign(nV, 0);
    for (int i = 0; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        weight[u][v] = w;
    }
    vector<Route> kShortestRoutes = yenKSP(0, 5, 10);
    cout << "Number of shortest routes: " << kShortestRoutes.size() << '\n';
    for (Route& route : kShortestRoutes) {
        cout << route;
    }
    return 0;
}
