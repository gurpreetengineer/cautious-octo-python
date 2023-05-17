#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& topoStack, int vertex) {
    visited[vertex] = true;
    
    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfs(adjList, visited, topoStack, neighbor);
        }
    }
    
    topoStack.push(vertex);
}

vector<int> topologicalSort(vector<vector<int>>& adjList, int numVertices) {
    vector<bool> visited(numVertices, false);
    stack<int> topoStack;
    
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(adjList, visited, topoStack, i);
        }
    }
    
    vector<int> sortedOrder;
    while (!topoStack.empty()) {
        sortedOrder.push_back(topoStack.top());
        topoStack.pop();
    }
    
    return sortedOrder;
}

int main() {
    int numVertices = 6;
    vector<vector<int>> adjList(numVertices);
    
    // Add edges to the adjacency list
    adjList[5].push_back(2);
    adjList[5].push_back(0);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);
    
    // Perform topological sorting
    vector<int> sortedOrder = topologicalSort(adjList, numVertices);
    
    // Print the sorted order
    cout << "Topological Sorting Order: ";
    for (int vertex : sortedOrder) {
        cout << vertex << " ";
    }
    cout << endl;
    
    return 0;
}

/**
 * @brief Topological Sorting using Depth First Search explanation
 * 
 * In this program, we use a depth-first search (DFS) approach to perform topological sorting. 
 * We maintain a stack (topoStack) to store the sorted order of vertices. 
 * We start by initializing a vector of visited flags (visited) and iterate through all the vertices in the graph. 
 * For each unvisited vertex, we recursively perform DFS, marking the visited flag as true and visiting all its unvisited neighbors.
 * 
 * After completing the DFS traversal, we push the current vertex onto the topoStack. 
 * Finally, we extract the elements from the topoStack and add them to the sortedOrder vector.
 * 
 * In the example given, we create a graph with six vertices and add directed edges between them. 
 * The program then performs topological sorting on the graph and prints the sorted order.
 * 
 */
