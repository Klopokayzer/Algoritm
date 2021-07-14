#include <iostream>
#include <string>
#include <regex>

// Task 1
int number()
{
    std::string a;
    int b = 0;
    std::regex is_number{ "\\d+" };
    while (true)
    {
        std::cout << "Enter number" << std::endl;
        std::getline(std::cin, a);
        if (std::regex_match(a, is_number))
        {
            try
            {
                b = std::stoi(a);
            }
            catch (const std::logic_error &e)
            {
                std::cout << "Error!" << std::endl;
                continue;
            }
            break;
        }
        std::cout << "Error!" << std::endl;
        continue;
    }
    return b;
}

// Task2
template<class CharT, class Traits>
std::basic_ostream<CharT, Traits> &endll(std::basic_ostream<CharT, Traits> &os)
{
    return os << "\n\n" << std::flush;
}

int main()
{
    // Task 1
    int a = number();
    std::cout << a << endll;
    std::cout << a;
    return 0;
}
