#ifndef house_hpp
#define house_hpp
#include "generic_player.hpp"
class House final: public GenericPlayer
{
public:
    House(std::string name): GenericPlayer(name) {}
    friend std::ostream &operator<<(std::ostream &os, const House &value)
    {
        value.print_to(os);
        return os;
    };
    bool is_hitting() const override
    {
        if (getValue() <= limit_house_score)
        {
            return true;
        }
        return false;
    }
    void flip_first_card()
    {
        if (deck.empty())
        {
            return;
        }
        deck.front()->flip();
    }
};
#endif