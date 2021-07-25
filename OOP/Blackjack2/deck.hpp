#ifndef deck_hpp
#define deck_hpp
#include "hand.hpp"
#include "generic_player.hpp"
class Deck final: public Hand
{
public:
    void populate()
    {
        if (!deck.empty())
        {
            deck.clear();
        }
        auto const the_end_rank = static_cast<int>(Rank::LAST);
        auto const the_end_suit = static_cast<int>(Suit::LAST);
        for (int i = 1; i < the_end_rank; i++)
        {
            for (int k = 0; k < the_end_suit; k++)
            {
                Card *card = new Card{ static_cast<Suit>(k), static_cast<Rank>(i) };
                deck.push_back(card);
            }
        }
    }
    void shuffle()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
    }
    void deal(Hand &value)
    {
        auto card = deck.back();
        deck.pop_back();
        value.add(card);
    }
    void additional_cards(GenericPlayer &value)
    {
        while (value.is_hitting())
        {
            auto card = deck.back();
            deck.pop_back();
            value.add(card);
            value.bust();
        }
    }
};
#endif