#ifndef hand_hpp
#define hand_hpp
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <random>
#include "card.hpp"
int const limit_score = 21;
int const limit_house_score = 16;
class Hand
{
protected:
    std::vector<Card *> deck;

public:
    Hand() = default;
    virtual ~Hand();
    void print_to(std::ostream &os) const
    {
        for (Card *card : deck)
        {
            os << *card << " ";
        }
    }
    void add(Card *value)
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
#endif