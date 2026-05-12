#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Edge structure
struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> dist(V, INT_MAX);

    // Initialize source
    dist[source] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "\nGraph contains negative weight cycle!\n";
            return;
        }
    }

    // Print result
    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, E, edges, source);

    return 0;
}