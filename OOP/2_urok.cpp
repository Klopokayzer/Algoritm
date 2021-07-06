#include <iostream>
#include <string>
#include <vector>

// Task 1
enum class Gender
{
    male = 0,
    famale
};
class Person
{
private:
    std::string name;
    int age = 0;
    Gender gender = Gender::famale;
    int weight = 0;

public:
    void set_name(std::string value)
    {
        name = value;
    }
    void set_age(int value)
    {
        age = value;
    }
    void set_gender(Gender value)
    {
        gender = value;
    }
    void set_weight(int value)
    {
        weight = value;
    }
    std::string get_name()
    {
        return name;
    }
    int get_age()
    {
        return age;
    }
    Gender get_gender()
    {
        return gender;
    }
    int get_weight()
    {
        return weight;
    }

    Person() = default;
    Person(std::string name1, int age1 = 0, Gender gender1 = Gender::male, int weight1 = 0):
      name{ name1 },
      age{ age1 },
      gender{ gender1 },
      weight{ weight1 } {

      };
};

class Student final: public Person
{
private:
    int year = 0;
    int num = 0;
    int get_count()
    {
        static int count = 0;
        return ++count;
    }

public:
    int get_year()
    {
        return year;
    }
    void set_year(int value)
    {
        year = value;
    }
    int get_num()
    {
        return num;
    }

    Student(): Person()
    {
        num = get_count();
    }
    Student(std::string name, int age, Gender gender, int weight, int year1):
      Person(name, age, gender, weight), year{ year1 }
    {
        num = get_count();
    }
};
// Task 2
class Fruit
{
private:
    std::string name = "Banana";
    std::string color = "Yellow";

public:
    void set_color(std::string value)
    {
        color = value;
    }
    void set_name(std::string value)
    {
        name = value;
    }
    std::string get_name()
    {
        return name;
    }
    std::string get_color()
    {
        return color;
    }
    Fruit() = default;
    Fruit(std::string color, std::string name): color{ color }, name{ name } {}
};

class Apple: public Fruit
{
public:
    Apple() = default;
    Apple(std::string color = "black", std::string name = "apple"): Fruit(color, name) {}
};

class Banana: public Fruit
{
public:
    Banana(std::string color = "yellow", std::string name = "banana"): Fruit(color, name) {}
};

class GrannySmith: public Apple
{
public:
    GrannySmith(std::string color = "green", std::string name = "Granny Smith apple"): Apple(color, name) {}
};

int main()
{
    // Task 1
    std::vector<Student> stud = { { "Ivanov", 24, Gender::male, 65, 2000 },
                                  { "Serov", 34, Gender::male, 80, 2000 },
                                  { "Povidlova", 27, Gender::famale, 120, 2000 } };
    std::cout << "Enter name: ";
    std::string user_name;
    std::cin >> user_name;
    bool match = false;
    for (Student &item : stud)
    {
        if (user_name == item.get_name())
        {
            match = true;
            std::cout << "name: " << item.get_name() << " "
                      << "age: " << item.get_age() << " "
                      << "gender: " << static_cast<int>(item.get_gender()) << " "
                      << "weight: " << item.get_weight() << " "
                      << "year: " << item.get_year() << " " << std::endl;
        }
    }
    if (match == false)
    {
        std::cout << "No matches found! \n";
    }
    // Task 2
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.get_name() << " is " << a.get_color() << ".\n";
    std::cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
    std::cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";

    return 0;
}