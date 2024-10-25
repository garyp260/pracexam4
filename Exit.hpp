#pragma once
#include "Interactable.hpp"
#include "Helper.hpp"
#include "Explorer.hpp"
#include <tuple>

class Exit : public Interactable{
    protected:
        InteractableType type;
    public:
        Exit(int width, int height){
            this->gridWidth = width;
            this->gridHeight = height;
            this->type = EXIT;
            this->coordinates = std::make_tuple(width - 1, height - 1);
        }

        bool interact(Explorer* player){
            int x1 = std::get<0>(player->getCoordinates());
            int y1 = std::get<1>(player->getCoordinates());
            int x2 = std::get<0>(this->coordinates);
            int y2 = std::get<1>(this->coordinates);

            double result = pow((abs(x2 - x1) + abs(y2 - y1)), 2);
            
            if (result == 0){
                return true;
            } else{
                return false;
            }
        }

        InteractableType getType(){
            return this->type;
        }
};