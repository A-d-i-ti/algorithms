#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

const int V = 5;  // Number of vertices

// Find the vertex with the minimum key value that is not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

// Print the MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

// Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];    // Stores the MST
    int key[V];       // Minimum weight edge to a vertex
    bool mstSet[V];   // Whether vertex is included in MST

    // Initialize keys and mstSet
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;       // Start from vertex 0
    parent[0] = -1;   // Root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex
        mstSet[u] = true;

        // Update key and parent of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
}

// Driver code
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
