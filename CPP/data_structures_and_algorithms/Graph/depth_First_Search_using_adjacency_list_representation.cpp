#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void dfs(vector<vector<int>>& adjList, int startVertex, vector<bool>& visited) {
    stack<int> stk;
    stk.push(startVertex);

    while (!stk.empty()) {
        int currVertex = stk.top();
        stk.pop();

        if (!visited[currVertex]) {
            cout << currVertex << " ";
            visited[currVertex] = true;
        }

        for (int neighbor : adjList[currVertex]) {
            if (!visited[neighbor]) {
                stk.push(neighbor);
            }
        }
    }
}

int main() {
    int numVertices = 7;
    vector<vector<int>> adjList(numVertices);
    vector<bool> visited(numVertices, false);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 2, 6);

    int startVertex = 0;
    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    dfs(adjList, startVertex, visited);
    cout << endl;

    return 0;
}

/**
 * @brief Depth First Search using adjacency list representation explanation
 * In this program, the addEdge function is used to create an adjacency list representation of the graph. 
 * The dfs function performs the Depth-First Search traversal. 
 * It uses a stack to keep track of vertices to visit. 
 * The algorithm starts by pushing the start vertex onto the stack. 
 * It then enters a loop where it pops a vertex from the stack, checks 
 * if it has been visited, marks it as visited if not, and outputs its value. 
 * Then, it pushes all unvisited neighbors of the current vertex onto the stack. The process continues until the stack is empty.
 * 
 * In the main function, you can customize the number of vertices and the edges of the graph by calling the addEdge function accordingly.
 * The startVertex variable determines the starting point of the DFS traversal.
 * 
 * When you run the program, it will perform DFS on the graph and print the traversal starting from the specified start vertex.
 * 
 */
