#include <iostream>
#include <vector>
#include "dijkstra.hpp"

Dijkstra::Dijkstra(int nodes){
    this->nodes = nodes;
    this->graph = new int*[nodes];
    for(int i = 0; i < nodes; i++){
        this->graph[i] = new int[nodes];
    }
    this->visited.resize(nodes);
    this->unvisited.resize(nodes);
    this->cost.resize(nodes);
    this->source = 0;
    this->target = 0;
    this->current = 0;
    return;
}

Dijkstra::~Dijkstra(){
    for(int i = 0; i < this->nodes; i++){
        delete[] this->graph[i];
    }
    delete[] this->graph;
    return;
}

void Dijkstra::setGrid(){
    int temp;
    for(int i = 0; i < this->nodes; i++){
        for(int j = 0; j < this->nodes; j++){
            if(i == j){
                this->graph[i][j] = 0;
                continue;
            }
            std::cout << "mAdj(" << i << "," << j << "): ";
            std::cin >> temp;
            temp < 0 ? this->graph[i][j] = infinity : this->graph[i][j] = temp;
        }
    }
    return;
}

inline void Dijkstra::setSource(){
    std::cout << "origem: ";
    std::cin >> this->source;
    return;
}

inline void Dijkstra::setTarget(){
    std::cout << "destino: ";
    std::cin >> this->target;
    return;
}

//check the final algortihm
void Dijkstra::shortestPath(){

    return;
}

void Dijkstra::runAlgorithm(){
    this->setGrid();
    this->setSource();
    this->setCost();
    this->shortestPath();
    std::cout << "monstrar caminho('s' ou 'n'): ";
    char answer;
    std::cin >> answer;
    if(answer == 'n'){return;}
    do{
        this->setTarget();
        std::cout << this->target << " <- ";
        this->target = this->previous[this->target];   
    }while(this->target != -1);
    
    this->setTarget();
    return;
}


