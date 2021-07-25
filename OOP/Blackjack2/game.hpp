#ifndef game_hpp
#define game_hpp
#include "deck.hpp"
#include "house.hpp"
#include "player.hpp"
class Game
{
private:
    Deck deck;
    House dealer;
    std::vector<Player> players;

public:
    Game(std::vector<std::string> names): dealer{ "dealer" }
    {
        deck.populate();
        deck.shuffle();
        for (std::string value : names)
        {
            players.emplace_back(value);
        }
    }
    void print()
    {
        std::cout << dealer << std::endl;
        for (Player &value : players)
        {
            std::cout << value << std::endl;
        }
    }
    void play()
    {
        for (int i = 0; i < 2; i++)
        {
            for (Player &value : players)
            {
                deck.deal(value);
            }
            deck.deal(dealer);
        }
        dealer.flip_first_card();
        print();
        for (Player &value : players)
        {
            deck.additional_cards(value);
        }
        dealer.flip_first_card();
        std::cout << dealer << std::endl;
        deck.additional_cards(dealer);
        print();
    }
};
#endif