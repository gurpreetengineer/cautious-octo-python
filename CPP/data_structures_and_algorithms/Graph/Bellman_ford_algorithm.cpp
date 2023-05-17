#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> distance(numVertices, numeric_limits<int>::max());
    distance[source] = 0;

    // Relax edges numVertices-1 times
    for (int i = 0; i < numVertices - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
            cout << "Graph contains a negative cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances from the source vertex
    for (int i = 0; i < numVertices; ++i) {
        cout << "Distance from source to vertex " << i << ": ";
        if (distance[i] == numeric_limits<int>::max()) {
            cout << "INF";
        } else {
            cout << distance[i];
        }
        cout << endl;
    }
}

int main() {
    int numVertices = 5;
    int source = 0;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, -2},
        {1, 3, 3},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, numVertices, source);

    return 0;
}

/**
 * @brief Bellman-Ford algorithm explanation
 * 
 * The Bellman-Ford algorithm is used to find the shortest paths from a single source vertex to all other vertices in 
 * a weighted graph, even in the presence of negative edge weights (as long as there are no negative cycles).
 * 
 * In this program, we define a struct Edge to represent the edges in the graph, with source, destination, and weight attributes. 
 * The bellmanFord function takes a vector of edges, the number of vertices, and the source vertex as input. 
 * It initializes the distance array with numeric_limits<int>::max() values, except for the source vertex which is set to 0.
 * 
 * The algorithm then relaxes the edges numVertices-1 times, where each 
 * relaxation updates the distance from the source vertex to each other vertex if a shorter path is found. 
 * After the relaxation step, it checks for negative cycles by performing an additional iteration. 
 * If any distance is further updated during this iteration, it means there is a negative cycle in the graph.
 * 
 * Finally, the function prints the shortest distances from the source vertex to all other vertices.
 * 
 * In the main function, we define the graph using the vector of edges and call bellmanFord with the appropriate parameters.
 * 
 */
