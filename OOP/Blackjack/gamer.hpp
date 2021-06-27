class Person
{
private:
    std::string name;
    std::vector<PlayingCard> my_cards;
    int score = 0;

public:
    int get_cards_count()
    {
        return my_cards.size();
    }
    void show_hidden_cards()
    {
        for (PlayingCard &card : my_cards)
        {
            card.set_hidden(false);
        }
    }
    void set_name(std::string value)
    {
        name = value;
    }
    std::string get_name()
    {
        return name;
    }
    void set_score(int value)
    {
        score = value;
    }
    int get_score()
    {
        return score;
    }
    void clear()
    {
        my_cards.clear();
        score = 0;
    }
    void push_card(PlayingCard card)
    {
        my_cards.push_back(card);
    }
    std::vector<PlayingCard> get_cards()
    {
        return my_cards;
    }
    virtual void hello()
    {
        std::cout << "I'm Person \n";
    }
};

class Dealer final: public Person
{
    void hello() override
    {
        std::cout << "I'm Dealer \n";
    }
};

class Gamer final: public Person
{
private:
    int money = 0;

public:
    void set_money(int value)
    {
        money = value;
    }
    int get_money()
    {
        return money;
    }
    void hello() override
    {
        std::cout << "I'm Gamer \n";
    }
};