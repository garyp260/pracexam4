#include "Game.hpp"
#include <iostream>

int main() {

    int width = 5;
    int height = 5;


    std::vector<std::tuple<int, int>> pitCoordinates = {
        {2, 2},
        {3, 1},
        {1, 3}
    };


    Game game(width, height, pitCoordinates);


    std::cout << "Initial Game State:" << std::endl;
    game.printGrid();


    game.displayState();


    std::cout << "\nMove player down by 1:" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player right by 1:" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player down by 1:" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();


    std::cout << "\nMove player right by 1 (into obstacle at (2,2)):" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();


    std::cout << "Player Stamina after falling in pit: " << game.getPlayerStamina() << std::endl;

    std::cout << "\nMove player down by 1:" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player right by 1:" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player down by 1 (should reach the goal):" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player right by 1 (should reach the goal):" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();

    if (game.displayState()) {
        std::cout << "Game Over!" << std::endl;
    } else {
        std::cout << "Game is still ongoing." << std::endl;
    }

    return 0;
}