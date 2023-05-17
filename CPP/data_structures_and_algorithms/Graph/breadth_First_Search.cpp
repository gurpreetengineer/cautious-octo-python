#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        
        cout << vertex << " ";
        
        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 7;  // Number of vertices
    
    vector<vector<int>> graph(n);
    
    // Add edges to the graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[2].push_back(6);
    
    int startVertex = 0;
    
    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    bfs(graph, startVertex);
    cout << endl;
    
    return 0;
}

/**
 * @brief Breadth First Search explanation
 * In this program, we define a function bfs that takes a graph represented as an adjacency list and a starting vertex as input. 
 * We use a queue and a visited array to perform the BFS traversal. 
 * We initialize the visited array with false values and mark the starting vertex as visited. 
 * Then, we enqueue the starting vertex and start the BFS loop.
 * 
 * Inside the BFS loop, we dequeue a vertex from the queue, print it, and enqueue its unvisited neighbors. 
 * We mark the neighbors as visited to avoid visiting them multiple times. 
 * The process continues until the queue becomes empty, indicating that all vertices have been visited.
 * 
 * In the main function, we create a sample graph represented as an adjacency list and specify the starting vertex. 
 * We then call the bfs function to perform the BFS traversal and print the result.
 * 
 * Note: The example graph in the program is a directed graph, but 
 * the BFS algorithm can be used for both directed and undirected graphs by appropriately constructing the adjacency list.
 * 
 */
