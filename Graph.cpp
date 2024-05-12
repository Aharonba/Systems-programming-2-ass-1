#include "Graph.hpp"
using namespace ariel;

Graph::Graph() {}

void Graph::loadGraph(const std::vector<std::vector<int>> &graph)
{
    // Before loading the graph I check that the matrix is square
    size_t numRows = graph.size();

    for (size_t i = 1; i < numRows; ++i)
    {
        if (graph[i].size() != numRows)
        {
            std::cerr << "Error: Provided matrix is not square." << std::endl;
            return;
        }
    }

    adjMatrix = graph;
}

/**
 * Print information about the graph.
 * Prints the number of vertices and edges in the graph.
 */
void Graph::printGraph()
{
    int numOfEdge = 0;

    // Count the number of non-zero elements in the adjacency matrix to find the number of edges
    for (std::vector<std::vector<int>>::size_type i = 0; i < adjMatrix.size(); i++)
    {
        for (std::vector<int>::size_type j = 0; j < adjMatrix[i].size(); j++)
        {
            if (adjMatrix[i][j] != 0)
            {
                numOfEdge++;
            }
        }
    }

    // Print the number of vertices and edges
    std::cout << "Graph with " << adjMatrix.size() << " vertices and " << numOfEdge << " edges." << std::endl;
}

/**
 * Check if the graph is directed.
 * 
 * @return True if the graph is directed, false otherwise.
 */
bool Graph::isDirected()
{
    size_t numRows = adjMatrix.size();
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numRows; j++)
        {
            // Check if there's an edge from i to j but not from j to i
            if ((adjMatrix[(size_t)i][(size_t)j]) != (adjMatrix[(size_t)j][(size_t)i]))
            {
                return true;
            }
        }
    }
    // If no such edge is found, the graph is undirected
    return false;
}

int Graph::getSize()
{
    return adjMatrix.size();
}

std::vector<std::vector<int>> Graph::getAdjMatrix()
{
    return adjMatrix;
}

void Graph::setAdjMatrix(std::vector<std::vector<int>> Matrix)
{
    adjMatrix = Matrix;
}