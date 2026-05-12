#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

// Edge structure
struct Edge {
    int to;
    int weight;
};

// Dijkstra Function
void dijkstra(int source, int n, vector<vector<Edge>>& adj) {

    // Distance array
    vector<int> dist(n, INF);

    // Parent array
    vector<int> parent(n, -1);

    // Min Heap
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Source distance
    dist[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        // Skip outdated entry
        if (currentDist > dist[u])
            continue;

        // Traverse neighbors
        for (auto edge : adj[u]) {

            int v = edge.to;
            int weight = edge.weight;

            // Relaxation
            if (dist[u] + weight < dist[v]) {

                dist[v] = dist[u] + weight;

                // Store parent
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "\nShortest Distances:\n";

    for (int i = 0; i < n; i++) {

        cout << "Node " << i << " = ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    // Print Shortest Path Tree
    cout << "\nShortest Path Tree:\n";

    int totalCost = 0;

    for (int i = 0; i < n; i++) {

        if (parent[i] != -1) {

            int edgeCost = dist[i] - dist[parent[i]];

            cout << parent[i]
                 << " -> "
                 << i
                 << "  Cost = "
                 << edgeCost
                 << endl;

            totalCost += edgeCost;
        }
    }

    // Print total tree cost
    cout << "\nTotal SPT Cost = "
         << totalCost
         << endl;
}

int main() {

    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    // Adjacency list
    vector<vector<Edge>> adj(n);

    cout << "\nEnter edges (u v weight):\n";

    for (int i = 0; i < e; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        // Directed graph
        adj[u].push_back({v, w});

        // Uncomment for undirected graph
        // adj[v].push_back({u, w});
    }

    int source;

    cout << "\nEnter source node: ";
    cin >> source;

    dijkstra(source, n, adj);

    return 0;
}