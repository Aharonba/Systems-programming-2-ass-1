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
