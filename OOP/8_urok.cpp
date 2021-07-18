#include <iostream>
#include <string>
#include <cstdlib>

// Task 1
class DivisionByZero final: public std::exception
{
    std::string message;

public:
    const char *what() const noexcept override
    {
        return message.c_str();
    }
    auto get_message() const
    {
        return message;
    }
    DivisionByZero(std::string mess): std::exception(), message{ mess } {}
    ~DivisionByZero() override = default;
};
namespace my_std
{
    template<typename T>
    auto div(T a, T b)
    {
        if (0 == b)
        {
            throw DivisionByZero{ "Error" };
        }
        return a / b;
    }
}
// Task 2
class Ex final: public std::exception
{
    int x = 0;

public:
    const char *what() const noexcept override
    {
        return std::to_string(x).c_str();
    }
    Ex(int value): std::exception(), x{ value } {}
    friend std::ostream &operator<<(std::ostream &os, Ex const &value)
    {
        return os << value.x;
    }
};

class Bar
{
    int y = 0;

public:
    Bar() = default;
    void set(int a)
    {
        if (y + a > 100)
        {
            throw Ex{ a * y };
        }
        y = a;
    }
    int get() const
    {
        return y;
    }
};
// Task 3
enum class Direction
{
    south = 1,
    west,
    north,
    east
};

std::string to_string(Direction value)
{
    switch (value)
    {
        case Direction::south: return "south";
        case Direction::west: return "west";
        case Direction::north: return "north";
        case Direction::east: return "east";
        default: return "unclear( " + std::to_string(static_cast<int>(value)) + " )";
    }
}

std::ostream &operator<<(std::ostream &os, Direction value)
{
    return os << to_string(value);
}

const int field_boundary_max = 10;
const int field_boundary_min = 1;

struct robot_data
{
    int x = 0;
    int y = 0;
    Direction direction = Direction::south;
    std::string to_string() const
    {
        return "x = " + std::to_string(x) + ", y = " + std::to_string(y) + ", direction: " + ::to_string(direction);
    }
};

class OffTheField final: public std::exception
{
private:
    robot_data r_d;
    std::string message;

public:
    const char *what() const noexcept override
    {
        return message.c_str();
    }
    OffTheField(robot_data value): std::exception(), r_d{ value }
    {
        message = "Off the field! " + r_d.to_string();
    }
};

class IllegalCommand final: public std::exception
{
private:
    robot_data r_d;
    std::string message;

public:
    const char *what() const noexcept override
    {
        return message.c_str();
    }
    IllegalCommand(robot_data value): std::exception(), r_d{ value }
    {
        message = "Invalid direction! " + r_d.to_string();
    }
};

class Robot final
{
private:
    robot_data r_d;

public:
    void set_direction(Direction value)
    {
        r_d.direction = value;
    }
    void set_position(int x1, int y1)
    {
        r_d.x = x1;
        r_d.y = y1;
    }
    int get_x() const
    {
        return r_d.x;
    }
    int get_y() const
    {
        return r_d.y;
    }
    void move()
    {
        switch (r_d.direction)
        {
            case Direction::south:
            {
                std::cout << "It south" << std::endl;
                if (field_boundary_min > (r_d.y - 1))
                {
                    throw OffTheField{ r_d };
                }
                r_d.y--;
                break;
            }
            case Direction::west:
            {
                if (field_boundary_min > (r_d.x - 1))
                {
                    throw OffTheField{ r_d };
                }
                r_d.x--;
                break;
            }
            case Direction::north:
            {
                if (field_boundary_max < (r_d.y + 1))
                {
                    throw OffTheField{ r_d };
                }
                r_d.y++;
                break;
            }
            case Direction::east:
            {
                if (field_boundary_max < (r_d.x + 1))
                {
                    throw OffTheField{ r_d };
                }
                r_d.x++;
                break;
            }
            default: throw IllegalCommand{ r_d };
        }
    }
    friend std::ostream &operator<<(std::ostream &os, Robot const &value)
    {
        return os << "position: "
                  << "x= " << value.r_d.x << ", y= " << value.r_d.y << ", direction: " << value.r_d.direction << ".";
    }
};

std::pair<int, int> start_position()
{
    std::pair<int, int> res;
    std::cout << "Enter start position:" << std::endl;
    std::cout << "x = ";
    std::cin >> res.first;
    std::cout << "y = ";
    std::cin >> res.second;
    return res;
}

int random(int a, int b)
{
    return a + std::rand() % (b - a + 1);
}

std::pair<int, int> start_random_position()
{
    std::pair<int, int> res;
    res.first = random(field_boundary_min, field_boundary_max);
    res.second = random(field_boundary_min, field_boundary_max);
    return res;
}

Direction get_user_direction()
{
    int value;
    std::cout << "Enter num direction: ";
    for (int i = 1; i < 5; i++)
    {
        std::cout << i << " - " << static_cast<Direction>(i) << ", ";
    }
    std::cout << std::endl;
    std::cin >> value;
    return static_cast<Direction>(value);
}

int main()
{
    // Task 1
    try
    {
        my_std::div(1, 0);
    }
    catch (const DivisionByZero &e)
    {
        std::cerr << e.get_message() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // Task 2
    Bar foo;
    int value;
    while (true)
    {
        std::cout << "y= " << foo.get() << std::endl;
        std::cin >> value;
        if (0 == value)
        {
            break;
        }
        try
        {
            foo.set(value);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
    // Task 3
    Robot robot;
    auto start_pos = start_random_position();
    robot.set_position(start_pos.first, start_pos.second);
    std::cout << "Start position: x = " << robot.get_x() << ", y = " << robot.get_y() << std::endl;
    while (true)
    {
        auto user_direction = get_user_direction();
        robot.set_direction(user_direction);
        try
        {
            robot.move();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            continue;
        }
        std::cout << robot << std::endl;
    }

    return 0;
}