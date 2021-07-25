#ifndef player_hpp
#define player_hpp
#include "generic_player.hpp"
class Player final: public GenericPlayer
{
public:
    Player(std::string name): GenericPlayer(name) {}
    friend std::ostream &operator<<(std::ostream &os, const Player &value)
    {
        value.print_to(os);
        return os;
    };
    bool is_hitting() const override
    {
        std::string answer;
        if (is_busted() == true)
        {
            return false;
        }
        while (answer != "y" || answer != "n")
        {
            std::cout << name << "Add card? Enter 'y' or 'n'." << std::endl;
            std::cin >> answer;
            std::transform(answer.begin(), answer.end(), answer.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            if (answer == "y")
            {
                return true;
            }
            if (answer == "n")
            {
                return false;
            }
        }
    }
    void win() const
    {
        std::cout << name << " is win!" << std::endl;
    }
    void lose() const
    {
        std::cout << name << " is lose!" << std::endl;
    }
    void draw() const
    {
        std::cout << name << " is draw!" << std::endl;
    }
};
#endif