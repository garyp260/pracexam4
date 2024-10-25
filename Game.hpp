#pragma once
#include "GridItem.hpp"
#include "Helper.hpp"
#include "Interactable.hpp"
#include "Explorer.hpp"
#include "Exit.hpp"
#include "Pit.hpp"
#include <tuple>
#include <vector>
#include <iostream>

class Game{
    protected:
        enum GameState{
            PLAYING,
            WIN,
            LOSE
        };
        int width;
        int height;
        Explorer* player;
        Exit* exit;
        std::vector<Pit*> pits;
        GameState state;
    public:
        Game(int width, int height, std::vector<std::tuple<int, int>> pitCoordinates){
            this->width = width;
            this->height = height;
            
            player = new Explorer(width, height);
            exit = new Exit(width, height);

            for (int i = 0; i < pitCoordinates.size(); i++){
                int tempX = std::get<0>(pitCoordinates[i]);
                int tempY = std::get<1>(pitCoordinates[i]);

                if (tempX != 0 && tempY != 0){
                    if (tempX != (width - 1) && tempY != (height -1)){\
                        Pit* newPit = new Pit(tempX, tempY, width, height);
                        pits.push_back(newPit);
                    }
                }
            }

            this->state = PLAYING;
        }

        bool displayState(){
            switch(state){
                case WIN:
                    std::cout << "You win!" << std::endl;
                    return true;
                case LOSE:
                    std::cout << "You lose :(" << std::endl;
                    return true;
                case PLAYING:
                    std::cout << "You lose :(" << std::endl;
                    return false;
            }
        }

        void movePlayer(int dx, int dy){
            if (state != PLAYING) {
                return;
            }

            bool moved = player->move(dx, dy);

            if (moved) {

                for (int i = 0; i < pits.size(); ++i) {
                    Pit* pit = pits[i];

                    int x1 = std::get<0>(player->getCoordinates());
                    int y1 = std::get<1>(player->getCoordinates());
                    int x2 = std::get<0>(pit->getCoordinates());
                    int y2 = std::get<1>(pit->getCoordinates());

                    double result = pow((abs(x2 - x1) + abs(y2 - y1)), 2);


                    if (result == 0) {

                        bool lost = pit->interact(player);
                        if (lost) {
                            state = LOSE;
                            return;
                        }
                    }
                }

                int x1 = std::get<0>(player->getCoordinates());
                int y1 = std::get<1>(player->getCoordinates());
                int x2 = std::get<0>(exit->getCoordinates());
                int y2 = std::get<1>(exit->getCoordinates());

                double result = pow((abs(x2 - x1) + abs(y2 - y1)), 2);
                if (result == 0) {
                    state = WIN;
                }
            }
        }

        void printGrid(){
            for (int i = 0; i < width; i++){
                for (int j = 0; j < height; j++){


                    int playerX = std::get<0>(player->getCoordinates());
                    int playerY = std::get<1>(player->getCoordinates());

                    if (i == (width - 1) && j == (height - 1)){
                        std::cout<< "E";
                    } else if (i == playerX && j == playerY){
                        std::cout<< "X";
                    } else {
                        bool isPit = false;
                        for (int k = 0; k < pits.size(); k++){
                            int tempX = std::get<0>(pits[k]->getCoordinates());
                            int tempY = std::get<1>(pits[k]->getCoordinates());

                            if (i == tempX && j == tempY){
                                std::cout<< "P";
                                isPit = true;
                                break;
                            }
                        }

                        if (isPit == false){
                            std::cout<< "_";
                        }

                    }

                }
                std::cout << std::endl;
            }
        }

        int getPlayerStamina() {
            return player->getStamina();
        }

        ~Game() {
            delete player;
            delete exit;
            for (auto pit : pits) {
                delete pit;
            }
        }
};