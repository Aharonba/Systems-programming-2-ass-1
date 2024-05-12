/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

/**Aharon bassous
 * aharonba123@gmail.com
 * 0545526575
*/

#include "Algorithms.hpp"
using ariel::Algorithms;
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                           // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;               // Should print: "1" (true).
    Algorithms::shortestPath(g, 0, 2);                        // Should print: 0 1 2.
    std::cout << Algorithms::isContainsCycle(g) << std::endl; // Should print: "-1" (false).
    Algorithms::isBipartite(g);                               // Should print: "graph is Bipartite".

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                           // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;               // Should print: "0" (false).
    Algorithms::shortestPath(g, 0, 4);                        // Should print: "-1" (there is no path between 0 and 4).
    std::cout << Algorithms::isContainsCycle(g) << std::endl; // Should print:  0->1->2->0".
    Algorithms::isBipartite(g);                               // Should print: "graph is not Bipartite".

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                           // Should print: "Graph with 5 vertices and 10 edges."
    cout << Algorithms::isConnected(g) << endl;               // Should print: "1" (true).
    Algorithms::shortestPath(g, 0, 4);                        // Should print: 0->2->3->4.>
    std::cout << Algorithms::isContainsCycle(g) << std::endl; // Should print: "0->1->2->0" (true).
    Algorithms::isBipartite(g);                               // Should print: "graph is not Bipartite".

    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {0, 0, -3, 0},
        {4, 0, 0, 5},
        {6, 7, 0, 0}};
    g.loadGraph(graph4);
    Algorithms::negativeCycle(g);                             // Should print: "Graph does not contain negative weight cycle".
    Algorithms::shortestPath(g, 1, 3);                        // Should print: "1 2 3"
    std::cout << Algorithms::isContainsCycle(g) << std::endl; // Should print: "0->1->2->0"
    Algorithms::isBipartite(g);                               // Should print: "graph is not Bipartite."

    vector<vector<int>> graph5 = {
        {0, 1, 2, 0},
        {0, 0, -8, 0},
        {0, 0, 0, 1},
        {6, 7, 0, 0}};
    g.loadGraph(graph5);
    Algorithms::negativeCycle(g);                             // Should print: "Graph does have contain negative weight cycle".
    Algorithms::shortestPath(g, 2, 1);                        // Should print: "2 3 1"
    std::cout << Algorithms::isContainsCycle(g) << std::endl; // Should print: "0->1->2->3->0
    Algorithms::isBipartite(g);                               // Should print: "graph is not Bipartite"..

    return 0;
}
