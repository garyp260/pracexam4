#pragma once
#include "GridItem.hpp"
#include <tuple>

class Explorer : public GridItem{
    protected:
        int stamina;
    public:
        Explorer(int gridWidth, int gridHeight){
            this->gridHeight = gridHeight;
            this->gridWidth = gridWidth;
            std::get<0>(coordinates) = 0;
            std::get<1>(coordinates) = 0;
            this->stamina = 2;
        }

        int getStamina(){
            return stamina;
        }

        void jumpPit(){
            if (stamina > 0){
                stamina--;
            }
        }

        bool move(int xOffest, int yOffset){

            int currX = std::get<0>(coordinates);
            int currY = std::get<1>(coordinates);

            if (xOffest > 0 && yOffset > 0){
                return false;
            }

            int newX = currX + xOffest;
            int newY = currY + yOffset;

            if (0 <= newX && newX <= (gridWidth - 1) && 0 <= newY && newY <= (gridHeight - 1)){
                std::get<0>(coordinates) = newX;
                std::get<1>(coordinates) = newY;
                return true;
            } else {
                return false;
            }

        }
};