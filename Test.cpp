/**Aharon bassous
 * aharonba123@gmail.com
 * 206751976
*/


#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == 1);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == 0);

    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {3, 1, 3}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == 1);

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 5, 2},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == 0);

    vector<vector<int>> graph5 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {9, 0, 1, 5, 2},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "-1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 9},
        {0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 4},
        {1, 1, 0, 1, 0},
        {0, 0, 2, 0, 2},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");

    vector<vector<int>> graph5 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 4},
        {1, 1, 0, 1, 0},
        {0, 3, 2, 0, 2},
        {2, 2, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->0");
}

// 5

TEST_CASE("Test is Bipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    // Create a stringstream to capture the output
    std::stringstream output;

    // Redirect cout to the stringstream
    std::streambuf *oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function that should print output
    ariel::Algorithms::isBipartite(g);

    // Restore cout
    std::cout.rdbuf(oldCoutBuffer);

    CHECK(output.str() == "graph is Bipartite\n\n");
}

TEST_CASE("Test is Bipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);

    // Create a stringstream to capture the output
    std::stringstream output;

    // Redirect cout to the stringstream
    std::streambuf *oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function that should print output
    ariel::Algorithms::isBipartite(g);

    // Restore cout
    std::cout.rdbuf(oldCoutBuffer);

    CHECK(output.str() == "graph is not Bipartite\n\n");
}

TEST_CASE("Test printGraph function")
{
    // Create an object of the class containing the function to test
    ariel::Graph g;

    // Load a graph (you can adjust this according to your implementation)
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    // Create a stringstream to capture the output
    std::stringstream output;

    // Redirect cout to the stringstream
    std::streambuf *oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function that should print output
    g.printGraph();

    // Restore cout
    std::cout.rdbuf(oldCoutBuffer);

    // Check the output against the expected output
    // You should compare the stringstream's content with the expected output
    // For example, if the expected output is "Graph with 3 vertices and 2 edges."
    // Then you would use CHECK(output.str() == "Graph with 3 vertices and 2 edges.\n");
    CHECK(output.str() == "Graph with 3 vertices and 4 edges.\n");
}

TEST_CASE("Test isDirected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isDirected(g) == 0);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isDirected(g) == 0);

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0},
        {0, 0, -3, 0},
        {4, 0, 0, 5},
        {6, 7, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isDirected(g) == 1);
}

TEST_CASE("Test negativeCycle1")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);

    // Create a stringstream to capture the output
    std::stringstream output;

    // Redirect cout to the stringstream
    std::streambuf *oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function that should print output
    ariel::Algorithms::negativeCycle(g);

    // Restore cout
    std::cout.rdbuf(oldCoutBuffer);

    CHECK(output.str() == "Graph does not contain negative weight cycle\n");
}

TEST_CASE("Test negativeCycle2")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 2, 0},
        {0, 0, -8, 0},
        {0, 0, 0, 1},
        {6, 1, 0, 0}};
    g.loadGraph(graph2);

    // Create a stringstream to capture the output
    std::stringstream output;

    // Redirect cout to the stringstream
    std::streambuf *oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function that should print output
    ariel::Algorithms::negativeCycle(g);

    // Restore cout
    std::cout.rdbuf(oldCoutBuffer);

    CHECK(output.str() == "Graph contains negative weight cycle\n");
}

TEST_CASE("Test negativeCycle3")
{
    ariel::Graph g;
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0},
        {0, 0, -3, 0},
        {4, 0, 0, 5},
        {6, 7, 0, 0}};
    g.loadGraph(graph3);

    // Create a stringstream to capture the output
    std::stringstream output;

    // Redirect cout to the stringstream
    std::streambuf *oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function that should print output
    ariel::Algorithms::negativeCycle(g);

    // Restore cout
    std::cout.rdbuf(oldCoutBuffer);

    CHECK(output.str() == "Graph does not contain negative weight cycle\n");
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);

    // Create a stringstream to capture the output
    std::stringstream output;

    // Redirect cout to the stringstream
    std::streambuf *oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Call the function that should print output
    ariel::Algorithms::shortestPath(g, 0, 4);

    // Restore cout
    std::cout.rdbuf(oldCoutBuffer);

    CHECK(output.str() == "Shortest path from 0 to 4 is: -1\n");
}
