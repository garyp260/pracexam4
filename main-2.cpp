#include "Explorer.hpp"
#include "Exit.hpp"
#include "Pit.hpp"
#include "Helper.hpp"
#include <iostream>

int main() {

    int gridWidth = 5;
    int gridHeight = 5;

    Explorer player(gridWidth, gridHeight);


    Exit exit(gridWidth, gridHeight);


    Pit pit1(2, 2, gridWidth, gridHeight);
    Pit pit2(3, 3, gridWidth, gridHeight);


    std::cout << "Initial Player Stamina: " << player.getStamina() << std::endl;

    std::cout << "\nMoving player right by 2 units..." << std::endl;
    if (player.move(2, 0)) {
        std::cout << "Player moved to position (" 
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }


    std::cout << "\nMoving player down by 2 units..." << std::endl;
    if (player.move(0, 2)) {
        std::cout << "Player moved to position ("
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }


    if (Helper::absoluteSquaredDistance(player.getCoordinates(), pit1.getCoordinates()) == 0) {
        std::cout << "Player has encountered an pit at position ("
                  << std::get<0>(pit1.getCoordinates()) << ", "
                  << std::get<1>(pit1.getCoordinates()) << ")" << std::endl;
        bool lost = pit1.interact(&player);
        std::cout << "Player Stamina after fall: " << player.getStamina() << std::endl;
        if (lost) {
            std::cout << "Player has lost the game due to zero stamina." << std::endl;
            return 0;
        }
    }


    std::cout << "\nMoving player right by 2 units..." << std::endl;
    if (player.move(2, 0)) {
        std::cout << "Player moved to position ("
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }

    std::cout << "\nMoving player down by 2 units to reach the exit..." << std::endl;
    if (player.move(0, 2)) {
        std::cout << "Player moved to position ("
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }

    if (Helper::absoluteSquaredDistance(player.getCoordinates(), exit.getCoordinates()) == 0) {
        std::cout << "Player has reached the exit at position ("
                  << std::get<0>(exit.getCoordinates()) << ", "
                  << std::get<1>(exit.getCoordinates()) << ")" << std::endl;
        bool won = exit.interact(&player);
        if (won) {
            std::cout << "Player has won the game!" << std::endl;
        } else {
            std::cout << "Player has not met the winning condition." << std::endl;
        }
    }

    return 0;
}