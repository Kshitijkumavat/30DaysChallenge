#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> adj(vertices);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int start, end;
    cout << "Enter start and end: ";
    cin >> start >> end;

    if (start == end) {
        cout << "Shortest path length: 0";
        return 0;
    }

    vector<int> distance(vertices, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                if (neighbor == end) {
                    cout << "Shortest path length: " << distance[neighbor];
                    return 0;
                }
                q.push(neighbor);
            }
        }
    }
    cout << "No path found (-1)";
}
