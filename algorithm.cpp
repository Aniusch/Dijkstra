#include <iostream>
#include <vector>
#include "dijkstra.hpp"


Dijkstra::Dijkstra(int vertices){
    this->vertices = vertices;
    this->graph = new int*[vertices];
    for(int i = 0; i < vertices; i++){
        this->graph[i] = new int[vertices];
    }
    this->visited.resize(vertices);
    this->path.resize(vertices);
    this->previous.resize(vertices);
    this->source = 0;
    this->target = 0;
    for(int i{}; i < this->vertices; i++){
        this->path[i] = infinity;
        this->visited[i] = false;
        this->previous[i] = -1;
    }
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
            std::cout << "mAdj(" << i+1 << "," << j+1 << "): ";
            std::cin >> temp;
            temp < 0 ? this->graph[i][j] = infinity : this->graph[i][j] = temp;
        }
    }
    return;
}

void Dijkstra::setSource(){
    int temp{};
    std::cout << "origem: ";
    std::cin >> temp;
    this->source = temp - 1;
    return;
}

void Dijkstra::setTarget(){
    int temp{};
    std::cout << "destino: ";
    std::cin >> temp;
    this->target = temp - 1;
    return;
}

int Dijkstra::findMin(){
    int min = infinity;
    int minIndex = 0;
    for(int i = 0; i < this->vertices; i++){
        if(this->path[i] < min && !this->visited[i]){
            min = this->path[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Dijkstra::shortestPath(){
    this->setTarget();
    this->path[this->source] = 0;
    int nearest{};

    for(int i = 0; i < this->vertices; i++){
        nearest = this->findMin();
        this->visited[nearest] = true;
        for(int j = 0; j < this->vertices; j++){
            if(this->graph[nearest][j] != infinity && !this->visited[j]){
                if(this->path[nearest] + this->graph[nearest][j] < this->path[j]){
                    this->path[j] = this->path[nearest] + this->graph[nearest][j];
                    this->previous[j] = nearest;
                }
            }
        }
    }

    if(this->path[this->target] == infinity){
        std::cout << "custo: inf" << '\n';
        std::cout << "nao existe um caminho entre " << this->source + 1 << " e " << this->target + 1 << std::endl;
        return;
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
    std::cout << this->source + 1;
    for(int i = showPath.size() - 1; i >= 0; i--){
        temp = showPath[i] + 1;
        std::cout << "->" << temp;
    }
    std::cout << std::endl;
    
    return;
}


void Dijkstra::runAlgorithm(){
    this->setGrid();
    this->setSource();
    std::cout << "monstrar caminho('s' ou 'n'): ";
    char answer;
    std::cin >> answer;
    if(answer == 'n'){return;}
    while (answer == 's'){
        this->shortestPath();
        std::cout << "monstrar caminho('s' ou 'n'): ";
        std::cin >> answer;
    }

    this->setTarget();
    return;
}


