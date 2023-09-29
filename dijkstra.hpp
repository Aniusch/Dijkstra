#ifndef HEADER_H 
#define HEADER_H

#define infinity 9999

class Dijkstra
{
public:
    int* nodes;
    int** grid;
    int** adjGrid;
    std::vector<int> visited;
    std::vector<int> unvisited;
    std::vector<int> distance;
    std::vector<int> previous;
    int source;
    int target;
    int current;

    Dijkstra(int& nodes);
    ~Dijkstra();
    void setSource();
    void setTarget();
    void setGrid(const int& i, const int& j, const int& value);
    void initAdjGrid();
    void algorithm();
    
};

#endif // HEADER_H