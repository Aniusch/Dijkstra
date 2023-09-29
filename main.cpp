#include <iostream>
#include <vector>
#include "dijkstra.hpp"

int main(){
    int nodes;

    std::cout << "informe a quantidade de nos no grafo: ";
    std::cin >> nodes;
    if(nodes < 1){return 1;}

    Dijkstra dijkstra(nodes);
    dijkstra.runAlgorithm();
    return 0;
}