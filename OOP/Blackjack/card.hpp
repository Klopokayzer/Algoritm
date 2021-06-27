class PlayingCard
{
private:
    std::string name;
    int score = 0;
    std::string suit;
    bool hidden = false;

public:
    void set_hidden(bool value)
    {
        hidden = value;
    }
    bool is_hidden()
    {
        return hidden;
    }
    void set_name(std::string value)
    {
        name = value;
    }
    std::string get_name()
    {
        return name;
    }
    void set_suit(std::string value)
    {
        suit = value;
    }
    std::string get_suit()
    {
        return suit;
    }
    void set_score(int value)
    {
        score = value;
    }
    int get_score()
    {
        return score;
    }
    bool is_ace()
    {
        return name == "Ace";
    }
    PlayingCard() = default;
};