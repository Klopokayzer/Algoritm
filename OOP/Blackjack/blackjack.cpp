#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include "card.hpp"
#include "gamer.hpp"
int const player_limit = 21;
using Deck = std::vector<PlayingCard>;

PlayingCard creating_card(std::string name, std::string suit, int score)
{
    PlayingCard card;
    card.set_name(name);
    card.set_suit(suit);
    card.set_score(score);
    return card;
}

Deck creating_deck()
{
    Deck deck;
    std::array<std::string, 4> suits = { "clubs", "diamonds", "hearts", "spades" };
    for (std::string suit : suits)
    {
        for (int i = 2; i < 11; i++)
        {
            PlayingCard card = creating_card(std::to_string(i), suit, i);
            deck.push_back(card);
        }
        PlayingCard card = creating_card("Jack", suit, 10);
        deck.push_back(card);
        card = creating_card("Queen", suit, 10);
        deck.push_back(card);
        card = creating_card("King", suit, 10);
        deck.push_back(card);
        card = creating_card("Ace", suit, 11);
        deck.push_back(card);
    }
    return deck;
}

void shuffle_deck(Deck &deck)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

void print_cards(std::vector<PlayingCard> cards)
{
    if (cards.empty())
    {
        std::cout << "No cards!" << std::endl;
        return;
    }
    for (size_t i = 0; i < cards.size() - 1; i++)
    {
        PlayingCard card = cards[i];
        if (card.is_hidden())
        {
            std::cout << " 'hidden card' ";
            continue;
        }
        std::cout << card.get_suit() << ": " << card.get_name() << ", ";
    }
    PlayingCard card = cards[cards.size() - 1];
    if (card.is_hidden())
    {
        std::cout << " 'hidden card' ";
    }
    else
    {
        std::cout << card.get_suit() << ": " << card.get_name();
    }
    std::cout << std::endl;
}

int counting_score(std::vector<PlayingCard> cards)
{
    int aces_count = 0;
    int score = 0;
    for (PlayingCard card : cards)
    {
        if (card.is_ace())
        {
            aces_count++;
        }
        score += card.get_score();
    }
    if (player_limit < score && 0 < aces_count)
    {
        score -= aces_count * 10;
    }
    return score;
}

PlayingCard get_last_card(Deck &deck)
{
    if (deck.empty())
    {
        std::cout << "Deck is empty" << std::endl;
        return {};
    }
    PlayingCard last_card = deck.back();
    deck.resize(deck.size() - 1);
    return last_card;
}

void playing_game(Dealer dealer, Gamer player)
{
    Deck deck;
    bool is_playing = true;
    bool hod = true;
    int player_score = 0;
    int dealer_score = 0;
    int const dealer_limit = 17;
    std::string user_answer;
    std::string const playing_next = "y";
    std::string const playing_exit = "n";
    while (is_playing == true)
    {
        if (player.get_money() <= 0)
        {
            is_playing = false;
            continue;
        }
        if (deck.empty())
        {
            deck = creating_deck();
            shuffle_deck(deck);
        }
        if (player.get_cards_count() < 2 && hod == true)
        {
            player.push_card(get_last_card(deck));
            hod = false;
            continue;
        }
        if (dealer.get_cards_count() < 2 && hod == false)
        {
            PlayingCard last_card = get_last_card(deck);
            if (1 == dealer.get_cards_count())
            {
                last_card.set_hidden(true);
            }
            dealer.push_card(last_card);
            hod = true;
            continue;
        }
        std::cout << dealer.get_name() << " cards: " << std::endl;
        print_cards(dealer.get_cards());
        std::cout << player.get_name() << " cards: " << std::endl;
        print_cards(player.get_cards());
        std::cout << std::endl << "Add a card? (y/n) \n";
        std::cin >> user_answer;
        if (playing_next == user_answer)
        {
            player.push_card(get_last_card(deck));
        }
        player_score = counting_score(player.get_cards());
        if (player_limit <= player_score)
        {
            dealer.show_hidden_cards();
            std::cout << dealer.get_name() << " cards: " << std::endl;
            print_cards(dealer.get_cards());
            std::cout << player.get_name() << " cards: " << std::endl;
            print_cards(player.get_cards());
            player_score = 0;
            dealer_score = 0;
            dealer.clear();
            player.clear();
            std::cout << "You lost!" << std::endl << std::endl;
            continue;
        }
        if (playing_exit == user_answer)
        {
            dealer.show_hidden_cards();
            std::cout << dealer.get_name() << " cards: " << std::endl;
            print_cards(dealer.get_cards());
            dealer_score = counting_score(dealer.get_cards());
            while (dealer_score <= dealer_limit)
            {
                if (deck.empty())
                {
                    deck = creating_deck();
                    shuffle_deck(deck);
                }
                PlayingCard last_card = get_last_card(deck);
                dealer.push_card(last_card);
                dealer_score = counting_score(dealer.get_cards());
            }
            if (dealer_score > player_limit)
            {
                std::cout << "You win!" << std::endl << std::endl;
                player_score = 0;
                dealer_score = 0;
                dealer.clear();
                player.clear();
                continue;
            }
            if (dealer_score == player_score)
            {
                std::cout << "Dead heat!" << std::endl << std::endl;
                player_score = 0;
                dealer_score = 0;
                dealer.clear();
                player.clear();
                continue;
            }
            if (dealer_score > player_score)
            {
                std::cout << "You lost!" << std::endl << std::endl;
                player_score = 0;
                dealer_score = 0;
                dealer.clear();
                player.clear();
                continue;
            }
            else
            {
                std::cout << "You win!" << std::endl << std::endl;
                player_score = 0;
                dealer_score = 0;
                dealer.clear();
                player.clear();
                continue;
            }
        }
    }
}

int main()
{
    Dealer dealer;
    dealer.set_name("Dealer Ivan");
    Gamer player;
    std::string user_name;
    int user_money = 0;
    // std::cout<<"Enter name: ";
    // std::cin>>user_name;
    // std::cout<<"Enter money: ";
    // std::cin>>user_money;
    user_money = 4000;
    user_name = "Vasya";
    player.set_name(user_name);
    player.set_money(user_money);
    playing_game(dealer, player);
    return 0;
}
