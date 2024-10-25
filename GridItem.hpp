#pragma once
#include <tuple>

class GridItem{
    protected:
        std::tuple<int, int> coordinates;
        int gridWidth;
        int gridHeight;
        static int activeGridItemCount;
    public:

        GridItem(int x, int y, int width, int height){
            this->coordinates = std::make_tuple(x, y);
            this->gridWidth = width;
            this->gridHeight = height;
            activeGridItemCount++;
        }

        GridItem(){
            this->coordinates = std::make_tuple(0, 0);
            this->gridWidth = 0;
            this->gridHeight = 0;
            activeGridItemCount++;
        }

        void setCoordinates(int x, int y){
            std::get<0>(coordinates) = x;
            std::get<1>(coordinates) = y;
        }

        std::tuple<int,int> getCoordinates(){
            int x = std::get<0>(coordinates);
            int y = std::get<1>(coordinates);
            return std::make_tuple(x, y);
        }

        int getGridWidth(){
            return gridWidth;
        }

        int getGridHeight(){
            return gridHeight;
        }

        int getActiveGridItemCount(){
            return activeGridItemCount;
        }

        virtual ~GridItem(){
            activeGridItemCount--;
        }
};

int GridItem::activeGridItemCount = 0;