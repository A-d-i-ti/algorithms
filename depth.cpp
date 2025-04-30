#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    // Visit all unvisited neighbors
    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs(neighbor, graph, visited);
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

    vector<bool> visited(V, false);

    cout << "DFS traversal starting from node 0:\n";
    dfs(0, graph, visited);

    return 0;
}
