#include <iostream>
#include <vector>
#include "dijkstra.hpp"


Dijkstra::Dijkstra(int vertices){
    this->vertices = vertices;
    this->graph = new int*[vertices];
    this->visited.resize(vertices);
    this->path.resize(vertices);
    for(int i = 0; i < vertices; i++){
        this->graph[i] = new int[vertices];
        this->visited[i] = false;
        this->previous[i] = -1;
        this->path[i] = infinity;
    }
    this->source = 0;
    this->target = 0;
    return;
}

Dijkstra::~Dijkstra(){
    for(int i = 0; i < this->vertices; i++){
        delete[] this->graph[i];
    }
    delete[] this->graph;
    return;
}

void Dijkstra::setGrid(){
    int temp;
    for(int i = 0; i < this->vertices; i++){
        for(int j = 0; j < this->vertices; j++){
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

void Dijkstra::shortestPath(){
    this->path[this->source] = 0;
    int min = infinity;
    int minIndex = 0;
    
    for(int i = 0; i < this->vertices; i++){
        if(this->path[i] < min && !this->visited[i]){
            min = this->path[i];
            minIndex = i;
        }
        for(int adj{}; adj < this->vertices; adj++){
            if(this->graph[minIndex][adj] != 0 && !this->visited[adj]){
                if(this->path[adj] > this->path[minIndex] + this->graph[minIndex][adj]){
                    this->path[adj] = this->path[minIndex] + this->graph[minIndex][adj];
                    this->previous[adj] = minIndex;
                }
            }
        }
    }
    std::cout << "custo: " << this->path[this->target] << std::endl;
    std::cout << "caminho: ";
    //show path from source to target
    std::vector<int> showPath;
    int temp = this->target;
    while(temp != this->source){
        showPath.push_back(temp);
        temp = this->previous[temp];
    }
    for(int i = showPath.size() - 1; i >= 0; i--){
        std::cout << showPath[i] << "->";
    }
    return;
}


void Dijkstra::runAlgorithm(){
    this->setGrid();
    this->setSource();
    std::cout << "monstrar caminho('s' ou 'n'): ";
    char answer;
    std::cin >> answer;
    if(answer == 'n'){return;}
    do{
        this->shortestPath();
        std::cout << "monstrar caminho('s' ou 'n'): ";
        std::cin >> answer;
    }while(answer == 's');
    
    this->setTarget();
    return;
}


