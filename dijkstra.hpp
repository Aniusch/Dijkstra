#ifndef HEADER_HPP
#define HEADER_HPP

#include <vector>
#include <limits>

#define infinity std::numeric_limits<int>::max()

class Dijkstra{
private:
    int vertices;
    int source;
    int target;
    std::vector<bool> visited;
    std::vector<int> path;
    std::vector<int> previous;
    int** graph;
public:
    Dijkstra(int vertices);
    ~Dijkstra();
    void setGrid();
    void setSource();
    void setTarget();
    int findMin();
    void shortestPath();
    void runAlgorithm();
};

#endif // HEADER_HPP