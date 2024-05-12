# Graph and Algorithms Library

This library provides classes and algorithms for working with graphs. It includes functionalities for graph representation, traversal, and various graph algorithms.

## Classes

### `Graph`

The `Graph` class represents a graph and provides methods for working with graphs.

#### Methods:

- `Graph()`: Constructor to create an empty graph.
- `loadGraph(const std::vector<std::vector<int>> &graph)`: Load the graph with the provided adjacency matrix.
- `printGraph()`: Print information about the graph, including the number of vertices and edges.
- `isDirected()`: Check if the graph is directed.
- `getSize()`: Get the number of vertices in the graph.
- `getAdjMatrix()`: Get the adjacency matrix of the graph.
- `setAdjMatrix(std::vector<std::vector<int>> Matrix)`: Set the adjacency matrix of the graph.

### `Algorithms`

The `Algorithms` class provides various graph algorithms such as BFS, DFS, Bellman-Ford, checking for bipartite graphs, and detecting cycles.

#### Methods:

- `isDirected(Graph &g)`: Check if the graph is directed.
- `BFS(int startVertex, std::vector<bool> &visited, Graph &g)`: Perform Breadth First Search (BFS) traversal starting from a given vertex.
- `isConnected(Graph &g)`: Check if the graph is connected.
- `reverseEdges(int size, Graph &g)`: Reverse the edges of the graph.
- `DFSUtil(int v, std::vector<bool> &visited, std::stack<int> &stack, Graph &g)`: Utility function for Depth-First Search (DFS) traversal.
- `isDirectedConnected(Graph g)`: Check if the directed graph is strongly connected.
- `shortestPath(Graph graph, int v, int u)`: Find the shortest path between two vertices using the Bellman-Ford algorithm.
- `bellmanFord(Graph graph, int src, int dest)`: Perform the Bellman-Ford algorithm to find the shortest path.
- `printPath(vector<int> &parent, int j)`: Recursively print the shortest path.
- `isBipartiteUtil(vector<vector<int>> &graph, int src, int colorArr[])`: Utility function to check if a graph is Bipartite starting from a given source vertex.
- `isBipartite(Graph &g)`: Check if the graph is Bipartite.
- `isBipartiteCheck(std::vector<vector<int>> g)`: Check if a given graph is Bipartite using BFS traversal.
- `negativeCycle(Graph &graph)`: Check if the graph contains a negative weight cycle.
- `negativeCycleCheck(Graph &graph)`: Check if the graph contains a negative weight cycle using the Bellman-Ford algorithm.
- `isContainsCycle(Graph &g)`: Check if the graph contains a cycle and return the cycle path if found.
- `isContainsCycleUtil(Graph &g, size_t src, vector<Color> *colors, vector<int> *parents, vector<int> *path)`: Utility function to recursively check if the graph contains a cycle starting from a given source vertex.
- `constructCyclePath(vector<int> &path, int start)`: Construct the cycle path from the current traversal path.

## Usage

To use this library, include the necessary header files and instantiate the `Graph` and `Algorithms` classes as needed. You can then use the provided methods to work with graphs and perform various graph algorithms.
