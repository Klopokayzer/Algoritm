#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

// Task 1
const double PI = 3.14159265;
class Figure
{
public:
    virtual int area() = 0;
    Figure() = default;
};

class Parallelogram: public Figure
{
protected:
    int width = 0;
    int height = 0;

public:
    virtual void set_parall(int a1, int b1)
    {
        std::cout << "Parallelogram::set_parall" << std::endl;
        width = a1;
        height = b1;
    }

    int area() override
    {
        return width * height;
    }
    Parallelogram(int width1, int height1): Figure(), width{ width1 }, height{ height1 } {}
};

class Circle final: public Figure
{
    double radius = 0;

public:
    void set_circle(double a1)
    {
        radius = a1;
    }
    int area() override
    {
        return PI * std::pow(radius, 2);
    }
    Circle(double radius1): Figure(), radius{ radius1 } {}
};

class Rentangle final: public Parallelogram
{
public:
    void set_parall(int a1, int b1)
    {
        Parallelogram::width = a1;
        Parallelogram::height = b1;
    }
    Rentangle(int width, int height): Parallelogram(width, height) {}
};
class Square final: public Parallelogram
{
public:
    void set_parall(int a1, int b1) override
    {
        std::cout << "Square::set_parall" << std::endl;
        assert(a1 == b1 && "Square::set_square");
        width = a1;
        height = b1;
    }
    void set_square(int a1)
    {
        width = a1;
        height = a1;
    }
    Square(int width): Parallelogram(width, width) {}
};
class Rhombus final: public Parallelogram
{
public:
    void set_rhombus(int a1, int b1)
    {
        width = a1;
        height = b1;
    }
    Rhombus(int width, int height): Parallelogram(width, height) {}
};

// Task 2
class Car
{
    std::string company;
    std::string model;

public:
    Car(std::string company1, std::string model1): company{ company1 }, model{ model1 }
    {
        std::cout << "Car::con-or: " << company << " - " << model << std::endl;
    }
};
class PassengerCar: public Car
{
public:
    PassengerCar(std::string company1, std::string model1): Car(company1, model1)
    {
        std::cout << "PassengerCar::con-or: " << company1 << " - " << model1 << std::endl;
    }
};
class Bus: public Car
{
public:
    Bus(std::string company1, std::string model1): Car(company1, model1)
    {
        std::cout << "Bus::con-or: " << company1 << " - " << model1 << std::endl;
    }
};
class Minivan final: public Bus, public PassengerCar
{
public:
    Minivan(std::string company1, std::string model1): PassengerCar(company1, model1), Bus(company1, model1)
    {
        std::cout << "Minivan::con-or: " << company1 << " - " << model1 << std::endl;
    }
};
// Task 3
class Faction
{
    int numerator = 0;
    int denominator = 0;

public:
    void set_faction(int a, int b)
    {
        assert(b != 0 && "denominator!=0");
        if (b == 0)
        {
            b = 1;
        }
        numerator = a;
        denominator = b;
    }
    friend std::ostream &operator<<(std::ostream &os, const Faction &value)
    {
        return os << value.numerator << "/" << value.denominator;
    }

    // Faction operator+(Faction value)
    // {
    //     Faction res;
    //     if (denominator == value.denominator)
    //     {
    //         res.set_faction(numerator + value.numerator, denominator);
    //         return res;
    //     }
    //     return res;
    // }
    friend Faction operator+(Faction a, Faction b)
    {
        Faction res;
        if (a.denominator == b.denominator)
        {
            res.set_faction(a.numerator + b.numerator, a.denominator);
            return res;
        }
        int numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        int denominator = a.denominator * b.denominator;
        res.set_faction(numerator, denominator);
        return res;
    }
    friend Faction operator-(Faction a, Faction b)
    {
        Faction res;
        if (a.denominator == b.denominator)
        {
            res.set_faction(a.numerator - b.numerator, a.denominator);
            return res;
        }
        int numerator = a.numerator * b.denominator - b.numerator * a.denominator;
        int denominator = a.denominator * b.denominator;
        res.set_faction(numerator, denominator);
        return res;
    }
    friend Faction operator*(Faction a, Faction b)
    {
        Faction res;
        int numerator = a.numerator * b.numerator;
        int denominator = a.denominator * b.denominator;
        res.set_faction(numerator, denominator);
        return res;
    }
    friend Faction operator/(Faction a, Faction b)
    {
        Faction res;
        int numerator = a.numerator * b.denominator;
        int denominator = b.numerator * a.denominator;
        res.set_faction(numerator, denominator);
        return res;
    }
    Faction operator-()
    {
        Faction res;
        if (numerator < 0 || denominator < 0)
        {
            res.set_faction(std::abs(numerator), std::abs(denominator));
            return res;
        }
        if (numerator > 0 && denominator > 0)
        {
            res.set_faction(std::abs(numerator) * -1, std::abs(denominator));
        }
        return res;
    }
    friend bool operator==(Faction a, Faction b)
    {
        if (a.denominator == b.denominator)
        {
            return a.numerator == b.numerator;
        }
        return a.numerator * b.denominator == b.numerator * a.denominator;
    }
    friend bool operator!=(Faction a, Faction b)
    {
        return !(a == b);
    }
    friend bool operator<(Faction a, Faction b)
    {
        return a.numerator * b.denominator < b.numerator * a.denominator;
    }
    friend bool operator>=(Faction a, Faction b)
    {
        return !(a < b);
    }
    friend bool operator>(Faction a, Faction b)
    {
        return a.numerator * b.denominator > b.numerator * a.denominator;
    }
    friend bool operator<=(Faction a, Faction b)
    {
        return !(a > b);
    }
    int get_numerator()
    {
        return numerator;
    }
    int get_denominator()
    {
        return denominator;
    }
};

int main()
{
    // Task 1
    Parallelogram parall(5, 5);
    std::cout << parall.area() << std::endl;
    Square squar(3);
    std::cout << squar.area() << std::endl;
    Circle circl(4);
    std::cout << circl.area() << std::endl;
    // Task 2
    Car mashina("kia", "3");
    PassengerCar yutong("Yutong", "long");
    Bus mercedes("Mercedes", "Big");
    Minivan mini("Minivan", "plus");
    // Task 3
    Faction f1, f2;
    f1.set_faction(1, 8);
    f2.set_faction(2, 5);
    Faction f3;
    f3 = f1 + f2;
    std::cout << -f1 << std::endl;
    return 0;
}