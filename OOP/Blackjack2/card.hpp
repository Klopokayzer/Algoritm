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
    TEN = 10'000,
    JACK,
    QUEEN,
    KING
};

inline std::string to_string(Rank value)
{
    switch (value)
    {
        case Rank::ACE: return "ACE";
        case Rank::TWO: return "TWO";
        case Rank::THREE: return "THREE";
        case Rank::FOUR: return "FOUR";
        case Rank::FIVE: return "FIVE";
        case Rank::SIX: return "SIX";
        case Rank::SEVEN: return "SEVEN";
        case Rank::EIGHT: return "EIGHT";
        case Rank::NINE: return "NINE";
        case Rank::TEN: return "TEN";
        case Rank::JACK: return "JACK";
        case Rank::QUEEN: return "QUEEN";
        case Rank::KING: return "KING";
        default: return "unclear( " + std::to_string(static_cast<int>(value)) + " )";
    }
}

inline std::ostream &operator<<(std::ostream &os, Rank const &value)
{
    return os << to_string(value);
}

enum class Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

inline std::string to_string(Suit value)
{
    switch (value)
    {
        case Suit::CLUBS: return "CLUBS";
        case Suit::DIAMONDS: return "DIAMONDS";
        case Suit::HEARTS: return "HEARTS";
        case Suit::SPADES: return "SPADES";
        default: return "unclear( " + std::to_string(static_cast<int>(value)) + " )";
    }
}

inline std::ostream &operator<<(std::ostream &os, Suit const &value)
{
    return os << to_string(value);
}

class Card
{
private:
    Suit suit_card = Suit::CLUBS;
    Rank rank = Rank::ACE;
    bool card_flipped = true;

public:
    bool flip()
    {
        return card_flipped == true ? true : card_flipped = true;
    }
    int get_value() const
    {
        int const temp = static_cast<int>(rank);
        return temp >= 10'000 ? 10 : temp;
    }
    bool is_ace() const
    {
        return Rank::ACE == rank;
    }
    friend std::ostream &operator<<(std::ostream &os, const Card &value)
    {
        if (value.card_flipped == true)
        {
            os << "XX" << std::endl;
        }
        else
        {
            os << value.suit_card << "-" << value.rank << std::endl;
        }
        return os;
    }
};
#endif