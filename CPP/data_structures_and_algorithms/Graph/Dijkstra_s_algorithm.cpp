#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;  // Pair of vertex and its distance

void dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();  // Number of vertices
    
    // Create a vector to store the distances from the source
    vector<int> distance(n, numeric_limits<int>::max());
    
    // Priority queue to store vertices with their distances
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // Set distance of source vertex to 0 and push it to the priority queue
    distance[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the smallest distance
        pq.pop();
        
        // Process all neighboring vertices of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            // If a shorter path to v is found, update the distance and push it to the priority queue
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    
    // Print the shortest distances from the source vertex
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    int n = 5;  // Number of vertices
    int source = 0;  // Source vertex

    // Weighted graph representation using an adjacency list
    vector<vector<pii>> graph(n);
    
    // Adding edges and weights to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({3, 3});
    graph[2].push_back({4, 5});
    graph[3].push_back({4, 2});
    
    dijkstra(graph, source);
    
    return 0;
}


/**
 * @brief Dijkstra's algorithm explanation
 * This program uses Dijkstra's Algorithm to find the shortest path between a given source vertex and all other vertices in a weighted graph.
 * 
 * In this program, we represent the graph using an adjacency list, where each vertex is associated with 
 * a vector of pairs representing its neighboring vertices and the corresponding edge weights. 
 * The dijkstra function implements Dijkstra's Algorithm using a priority queue to 
 * process vertices in increasing order of their distances from the source. 
 * 
 * It initializes the distance of the source vertex to 0 and iteratively explores the neighboring vertices, 
 * updating their distances if a shorter path is found. Finally, it prints the shortest distances from the source vertex.
 * 
 * In the main function, we create a graph with five vertices and add edges with weights. 
 * We specify the source vertex as 0 and call the dijkstra function to find the shortest distances from the source vertex.
 * 
 */
