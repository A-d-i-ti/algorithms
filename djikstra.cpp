#include <iostream>
using namespace std;

const int V = 5;      // Number of vertices
const int INF = 1e9;  // A large number representing infinity

// Find the vertex with the minimum distance
int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Shortest distance from src to i
    bool visited[V];  // True if vertex i is included in shortest path

    // Initialize all distances
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;  // Distance to source is 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print results
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << "\n";
}

// Main function
int main() {
    // Adjacency matrix (0 means no edge)
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    dijkstra(graph, 0);  // Source vertex is 0

    return 0;
}
