#include <iostream>
#include <vector>
#include "dijkstra.hpp"

Dijkstra::Dijkstra(int nodes){
    this->nodes = nodes;
    this->grid = new int*[nodes-1];
    for(int i{}; i < nodes-1; i++){
        this->grid[i] = new int[nodes-1];
    }
    this->adjGrid = new int*[nodes-1];
    for(int i{}; i < nodes-1; i++){
        this->adjGrid[i] = new int[nodes-1];
    }
    this->visited.resize(nodes);
    this->unvisited.resize(nodes);
    this->distance.resize(nodes);
    this->previous.resize(nodes);
    this->source = 0;
    this->target = 0;
    this->current = 0;
}

Dijkstra::~Dijkstra()
{
    for(int i{}; i < this->nodes - 1; i++){
        delete[] this->grid[i];
    }
    delete[] this->grid;
    
    
    for(int i{}; i < this->nodes-1; i++){
        delete[] this->adjGrid[i];
    }
    delete[] this->adjGrid;
    return;
}

void Dijkstra::setSource(){
    std::cout << "origem: ";
    std::cin >> this->source;
    return;
}

void Dijkstra::setTarget(){
    std::cout << "destino: ";
    std::cin >> this->target;
    return;
}

void Dijkstra::setGrid(const int& i, const int& j, const int& value){
    this->grid[i][j] = value;
    return;
}

void Dijkstra::initAdjGrid(){
    int temp{};
    for(int i{}; i < this->nodes-1; i++){
        for(int j{}; j < this->nodes-1; j++){
            if(i == j){
                adjGrid[i][j] = 0;  
            }else{
                std::cout << "mAdj(" << i << ", " << j << "): ";
                std::cin >> temp;

                if(temp < 0){
                    adjGrid[i][j] = infinity;
                }
                adjGrid[i][j] = temp;
            }
        }
    } 

    for(int i{}; i < this->nodes - 1; i++){
        this->unvisited[i] = i;
        this->distance[i] = infinity;
        this->previous[i] = -1;
    }
    this->distance[this->source] = 0;
    return;
}


//check the final algortihm
void Dijkstra::runAlg(){
    this->initAdjGrid();
    this->setSource();
    this->setTarget();
    while(!this->unvisited.empty()){
        int min = infinity;
        for(int i{}; i < this->unvisited.size(); i++){
            if(this->distance[this->unvisited[i]] < min){
                min = this->distance[this->unvisited[i]];
                this->current = this->unvisited[i];
            }
        }
        for(int i{}; i < this->unvisited.size(); i++){
            if(this->unvisited[i] == this->current){
                this->unvisited.erase(this->unvisited.begin() + i);
                break;
            }
        }
        for(int i{}; i < this->nodes - 1; i++){
            if(this->adjGrid[this->current][i] != 0){
                int alt = this->distance[this->current] + this->adjGrid[this->current][i];
                if(alt < this->distance[i]){
                    this->distance[i] = alt;
                    this->previous[i] = this->current;
                }
            }
        }
    }
    return;
}


