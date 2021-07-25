#include "card.hpp"
#include "hand.hpp"
#include "game.hpp"

int main()
{
    std::string name;
    std::cout << "Enter your name: " << std::endl;
    std::cin >> name;
    Game game({ "Peter", name });
    return 0;
}