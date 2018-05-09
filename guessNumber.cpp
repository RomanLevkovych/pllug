#include <iostream>

int main()
{
    char gameStat;
    unsigned short level = 1;
    unsigned short numberToGuess;
    unsigned short userGuess;
    while (true) {
        std::cout << "Woul'd like to play? [p] - play, [l]- select level, [q] - quit.\n";
         std::cin >> gameStat;
        if (gameStat == 'q')
            break;
        if (gameStat == 'l') {
            unsigned short newLevel; std::cin >> newLevel;
            level = newLevel * 10;
        }
        numberToGuess = rand() % level + 1;
        for (short i = 0; i < 10; ++i) {
            std::cin >> userGuess;
            if (userGuess > numberToGuess)
                std::cout << "Greater\n";
            if (userGuess < numberToGuess)
                std::cout << "Less\n";
            if (userGuess == numberToGuess) {
                std::cout << "You win\n";
                break;
            }
        }

    }
    return 0;
}