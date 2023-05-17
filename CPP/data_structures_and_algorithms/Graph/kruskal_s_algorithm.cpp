#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct Subset {
    int parent, rank;
};

// Find the parent of a vertex using path compression
int findParent(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findParent(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Perform union of two subsets using rank-based optimization
void unionSets(Subset subsets[], int x, int y) {
    int xroot = findParent(subsets, x);
    int yroot = findParent(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function to sort edges based on weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void kruskalMST(Graph graph) {
    int V = graph.V;
    vector<Edge> result;
    int e = 0;
    int i = 0;

    // Sort the edges in non-decreasing order of weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];

        int x = findParent(subsets, nextEdge.src);
        int y = findParent(subsets, nextEdge.dest);

        // Include the edge if it doesn't form a cycle
        if (x != y) {
            result.push_back(nextEdge);
            unionSets(subsets, x, y);
            e++;
        }
    }

    cout << "Minimum Spanning Tree edges:" << endl;
    for (i = 0; i < e; i++) {
        cout << result[i].src << " -- " << result[i].dest << " : " << result[i].weight << endl;
    }

    delete[] subsets;
}

int main() {
    Graph graph;
    graph.V = 4; // Number of vertices
    graph.E = 5; // Number of edges

    // Example graph with weighted edges
    graph.edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(graph);

    return 0;
}


/**
 * @brief Kruskal's algorithm explanation
 * To implement Kruskal's algorithm for finding a minimum spanning tree in a graph efficiently, 
 * you need to use a disjoint set data structure to keep track of the connected components and the union-find operations.
 * 
 * In this program, the Graph struct represents the graph with the number of vertices (V) and edges (E), 
 * and the Edge struct represents an edge with its source vertex (src), destination vertex (dest), and weight (weight). 
 * The Subset struct is used to represent a subset in the disjoint set data structure, 
 * with parent pointing to the parent of the subset and rank indicating the rank of the subset.
 * 
 * The findParent function performs the find operation of the union-find algorithm with path compression optimization. 
 * It recursively finds the parent of a vertex and updates the parent of each visited vertex to the root parent.
 * 
 * The unionSets function performs the union operation of the union-find algorithm with rank-based optimization. 
 * It merges two subsets based on their ranks to keep the tree height minimum.
 * 
 * The compareEdges function is a compare function used to sort the edges in non-decreasing order of weight.
 * 
 * The kruskalMST function implements Kruskal's algorithm. It starts by sorting the edges based on their weights. 
 * Then, it iterates through the sorted edges and includes an edge in the minimum spanning tree (result) if it doesn't form a cycle. 
 * It uses the union-find operations to check for cycle formation. Finally, it prints the edges of the minimum spanning tree.
 * 
 * In the main function, a sample graph is created with 4 vertices and 5 edges. 
 * The kruskalMST function is called to find the minimum spanning tree for the graph.
 * 
 * Please note that this implementation assumes that the input graph is connected. 
 * If the graph can be disconnected, you may need to modify the code accordingly.
 * 
 */
