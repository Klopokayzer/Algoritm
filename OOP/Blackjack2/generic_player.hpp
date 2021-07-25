#ifndef generic_player_hpp
#define generic_player_hpp
#include "hand.hpp"
class GenericPlayer: public Hand
{
protected:
    std::string name;

public:
    GenericPlayer(std::string name1): Hand(), name{ name1 } {}
    virtual bool is_hitting() const = 0;
    bool is_busted() const
    {
        return Hand::getValue() > limit_score;
    }
    void bust() const
    {
        if (is_busted())
        {
            std::cout << name << ": is busted!" << std::endl;
        }
    }
    void print_to(std::ostream &os) const
    {
        os << name << ": ";
        Hand::print_to(os);
    }
};
#endif