#ifndef card_hpp
#define card_hpp
#include <iostream>
#include <string>

enum class Rank
{
    ACE = 11,
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK = 10,
    QUEEN = 10,
    KING = 10
};

enum class Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

class Card
{
private:
    Suit suit_card = Suit::CLUBS;
    Rank rank = Rank::ACE;
    bool card_position = true;

public:
    bool flip()
    {
        return card_position == true ? true : card_position = true;
    }
    int get_value() const
    {
        return static_cast<int>(rank);
    }
    bool is_ace() const
    {
        return Rank::ACE == rank;
    }
};
#endif