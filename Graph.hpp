/**Aharon bassous
 * aharonba123@gmail.com
 * 0545526575
*/


#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

namespace ariel
{

    class Graph
    {
    private:
        std::vector<std::vector<int>> adjMatrix;

    public:
        Graph();
        void loadGraph(const std::vector<std::vector<int>> &graph);
        void printGraph();
        bool isDirected();
        int getSize();
        std::vector<std::vector<int>> getAdjMatrix();
        void setAdjMatrix(std::vector<std::vector<int>> Matrix);
    };

}

#endif // GRAPH_HPP