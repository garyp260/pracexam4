#pragma once
#include "GridItem.hpp"
#include "Explorer.hpp"
#include <tuple>

class Interactable : public GridItem{
    public:
        enum InteractableType{
            EXIT,
            PIT
        };

        Interactable(int x, int y, int width, int height){
            this->gridWidth = width;
            this->gridHeight = height;
            this->coordinates = std::make_tuple(x, y);
            activeGridItemCount++;
        }

        Interactable(){
            this->gridWidth = 0;
            this->gridHeight = 0;
            this->coordinates = std::make_tuple(0, 0);
            activeGridItemCount++;
        }

        virtual bool interact(Explorer* player) = 0;

        virtual InteractableType getType() = 0;

        int getActiveInteractableCount(){
            return activeGridItemCount;
        }

        ~Interactable(){
            activeGridItemCount--;
        }

};