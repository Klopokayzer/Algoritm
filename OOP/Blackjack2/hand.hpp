#ifndef hand_hpp
#define hand_hpp
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "card.hpp"
int const limit_score = 21;
class Hand
{
private:
    std::vector<Card const *> deck;

public:
    void add(Card const *value)
    {
        assert(nullptr != value && "Card::add");
        deck.push_back(value);
    }
    void clear()
    {
        deck.clear();
    }
    int getValue() const
    {
        int aces_count = 0;
        int score = 0;
        for (Card const *card : deck)
        {
            assert(nullptr != card && "Card::getValue");
            if (card->is_ace())
            {
                aces_count++;
            }
            score += card->get_value();
        }
        if (limit_score < score && 0 < aces_count)
        {
            score -= aces_count * 10;
        }
        return score;
    }
};

class GenericPlayer: public Hand
{
private:
    std::string name;

public:
    virtual bool is_hitting() = 0;
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
};
#endif