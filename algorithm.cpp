#include <iostream>
#include <vector>
#include "dijkstra.hpp"

Dijkstra::Dijkstra(int nodes){
    this->nodes = nodes;
    this->grid = new int*[nodes];
    for(int i{}; i < nodes; i++){
        this->grid[i] = new int[nodes];
    }
    this->adjGrid = new int*[nodes];
    for(int i{}; i < nodes; i++){
        this->adjGrid[i] = new int[nodes];
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
    for(int i{}; i < this->nodes; i++){
        delete[] this->grid[i];
    }
    delete[] this->grid;
    
    
    for(int i{}; i < this->nodes; i++){
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
    for(int i{}; i < this->nodes; i++){
        for(int j{}; j < this->nodes; j++){
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

    for(int i{}; i < this->nodes ; i++){
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
        for(int i{}; i < this->nodes; i++){
            if(this->distance[i] < min){
                min = this->distance[i];
                this->current = i;
            }
        }
        for(int i{}; i < this->nodes; i++){
            if(this->adjGrid[this->current][i] != infinity){
                if(this->distance[i] > this->distance[this->current] + this->adjGrid[this->current][i]){
                    this->distance[i] = this->distance[this->current] + this->adjGrid[this->current][i];
                    this->previous[i] = this->current;
                }
            }
        }
        this->visited.push_back(this->current);
        this->unvisited.erase(this->unvisited.begin() + this->current);

        if(this->current == this->target){
            std::cout << "caminho: ";
            int temp = this->target;
            while(temp != this->source){
                std::cout << temp << " <- ";
                temp = this->previous[temp];
            }
            std::cout << this->source << std::endl;
            std::cout << "custo: " << this->distance[this->target] << std::endl;
            
            break;
        }
    }
    return;
}


