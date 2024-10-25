#pragma once
#include "Interactable.hpp"
#include <cmath>
#include <tuple>

class Pit : public Interactable{
    protected:
        InteractableType type;
    public:
        Pit(int x, int y, int width, int height){
            this->coordinates = std::make_pair(x, y);
            this->gridWidth = width;
            this->gridHeight = height;
            this->type = PIT;
        }

        bool interact(Explorer* player){
            int x1 = std::get<0>(player->getCoordinates());
            int y1 = std::get<1>(player->getCoordinates());
            int x2 = std::get<0>(this->coordinates);
            int y2 = std::get<1>(this->coordinates);

            double result = pow((abs(x2 - x1) + abs(y2 - y1)), 2);
            
            if (result == 0){
                player->jumpPit(); 
                if (player->getStamina() == 0){
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        InteractableType getType(){
            return PIT;
        }
};