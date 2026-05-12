#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void bfs (vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<bool> visited(n,false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal :";
    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neighbor : graph[node]) {
            if (!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main(){
    int vertices,edges;
    cout << "Enter the number of vertices:";
    cin >> vertices;

    vector<vector<int>> graph(vertices);

    cout << "Enter the number of edges:";
    cin >> edges;

    cout << "Enter the edges (e,v) format (0-based indexing):\n ";

    for(int i=0;i<edges;i++){
        int u,v;
        cin >> u >>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter the starting node for BFS:";
    cin >> start;
    bfs(graph, start);
    return 0;
}