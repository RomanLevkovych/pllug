#include <iostream>
#include <string>
#include <cstdlib>
#include <array>

bool isWinner(std::string player, std::string ai);

int main()
{
    std::string input;
    std::array<std::string, 3> possibleAnswers {"rock", "paper", "scissor"};
    std::cout << "If you want to exit game, enter \"exit\" \n";
    std::string rules = "Enter rock, paper or scissor: ";
    do {
    std::cout << rules;
    std::cin >> input;
    std::string answ;
    if (input == "exit")
        break;
    if (isWinner(input, possibleAnswers[rand() % 3]))
        std::cout << "Winner\n";
    else
        std::cout << "Looser\n";
    
    } while(input != "exit");
    return 0;
}

bool isWinner(std::string player, std::string ai)
{
    if ((player == "scissor" && ai == "paper") ||
        (player == "paper" && ai == "rock") ||
        (player == "rock" && ai == "scissor"))
        return true;
    return false;
}