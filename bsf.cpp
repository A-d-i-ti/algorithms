#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS
void bfs(int start, vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from node " << start << ":\n";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all unvisited neighbors
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Main function
int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> graph(V);  // Adjacency list

    // Add edges (undirected graph)
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    bfs(0, graph, V);  // Start BFS from node 0

    return 0;
}
