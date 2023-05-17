#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSortBFS(vector<vector<int>>& graph, vector<int>& inDegree) {
    int n = graph.size();
    vector<int> result;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    int n = 6;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    // Add edges to the graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(4);
    graph[4].push_back(5);

    // Compute in-degrees for each vertex
    for (int i = 0; i < n; i++) {
        for (int neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }

    // Perform topological sorting using BFS
    vector<int> sortedOrder = topologicalSortBFS(graph, inDegree);

    // Print the sorted order
    cout << "Topological Sorting: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/**
 * @brief Topological sorting using Breadth-First Search (BFS) with a queue and an adjacency list representation of the graph explanation
 * 
 * In this program, we first create an adjacency list representation of the graph using a vector of vectors. 
 * Each vector represents a node and contains its neighbors. 
 * 
 * Then, we calculate the in-degrees for each vertex by counting the number of incoming edges. 
 * We use a queue to store the nodes with in-degree 0 and perform the BFS algorithm. 
 * We dequeue a node, add it to the result, and decrement the in-degrees of its neighbors. 
 * 
 * If a neighbor's in-degree becomes 0, we enqueue it. 
 * 
 * Finally, we return the result, which represents the topologically sorted order of the graph.
 * 
 * In the example given, the graph has 6 nodes, and we perform topological sorting using BFS. 
 * The program prints the sorted order, which is the topological order of the graph: 0 1 2 3 4 5.
 * 
 */
