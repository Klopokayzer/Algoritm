#include <iostream>
#include <string>

// Task 1
template<typename T>
class Pair1
{
private:
    T num1 = 0;
    T num2 = 0;

public:
    T first() const
    {
        return num1;
    }
    T second() const
    {
        return num2;
    }
    Pair1(T a, T b): num1{ a }, num2{ b } {}
};

// Task 2
template<typename T1, typename T2>
class Pair
{
private:
    T1 num1 = 0;
    T2 num2 = 0;

public:
    T1 first() const
    {
        return num1;
    }
    T2 second() const
    {
        return num2;
    }
    Pair(T1 a, T2 b): num1{ a }, num2{ b } {}
};

// Task 3
template<typename T>
class StringValuePair final: public Pair<std::string, T>
{
private:
public:
    StringValuePair(std::string a, T b): Pair<std::string, T>(a, b) {}
};
// Task 4
// Go to "Blackjack2"
int main()
{
    // Task 1
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    // Task 2
    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
    // Task 3
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}