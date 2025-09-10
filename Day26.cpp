#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect cycle
bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        // If already visited and not the parent → cycle
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, vector<vector<int>>& edges) {
    // Build adjacency list
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    // Check for cycle in all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    if (hasCycle(V, edges))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
