#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> primMST(const Graph& graph, int startVertex) {
    int numVertices = graph.size();
    vector<int> key(numVertices, INT_MAX);  // Key values used to pick minimum weight edge
    vector<bool> visited(numVertices, false);  // To track visited vertices
    vector<int> parent(numVertices, -1);  // Store MST
    
    // Custom comparator for priority queue (min-heap)
    auto comp = [](const pii& a, const pii& b) {
        return a.second > b.second;
    };
    
    // Priority queue to store vertices and their corresponding key values
    priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
    
    // Start with the given startVertex
    pq.push({startVertex, 0});
    key[startVertex] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        
        visited[u] = true;
        
        // Traverse all adjacent vertices of u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (!visited[v] && weight < key[v]) {
                // Update the key value and parent
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }
    
    return parent;
}

int main() {
    int numVertices = 6;
    Graph graph(numVertices);
    
    // Add edges and their weights to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 4});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 1});
    graph[1].push_back({4, 5});
    graph[2].push_back({4, 6});
    graph[3].push_back({5, 7});
    graph[4].push_back({5, 8});
    
    int startVertex = 0;
    vector<int> parent = primMST(graph, startVertex);
    
    // Printing the minimum spanning tree
    cout << "Minimum Spanning Tree (MST):" << endl;
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
    
    return 0;
}

/**
 * @brief Prim's algorithm to find the minimum spanning tree of a weighted undirected graph
 * 
 * In this program, we use a priority queue to store the vertices and their corresponding key values. 
 * We start with a given start vertex and initialize all key values to infinity except for the start vertex which is set to 0. 
 * We iteratively select the vertex with the minimum key value from the priority queue and 
 * update the key values and parent for its adjacent vertices if they are not visited and have a smaller weight. 
 * The process continues until all vertices are visited.
 * 
 * The primMST function takes the graph and the start vertex as inputs and returns 
 * a vector that represents the parent of each vertex in the minimum spanning tree. 
 * We then print the minimum spanning tree by iterating over the parent vector.
 * 
 * Note: This implementation assumes an adjacency list representation of the graph using a vector of vectors, 
 * where each vertex stores a pair containing the adjacent vertex and the weight of the edge connecting them.
 * 
 */
