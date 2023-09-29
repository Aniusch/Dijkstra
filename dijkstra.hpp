#ifndef HEADER_HPP
#define HEADER_HPP

#include <vector>
#include <limits>

#define infinity std::numeric_limits<int>::max()


class Dijkstra
{
public:
    int nodes;
    int source;
    int target;
    int current;
    std::vector<int> visited;
    std::vector<int> unvisited;
    std::vector<int> previous;
    int** graph;

    Dijkstra(int nodes);
    ~Dijkstra();

    void setGrid();
    inline void setSource();
    inline void setTarget();
    inline void initCost();
    void shortestPath();
    void runAlgorithm();
    

};

#endif // HEADER_HPP