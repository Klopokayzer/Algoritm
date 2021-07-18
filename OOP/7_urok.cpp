#include <iostream>
#include <memory>
#include <iomanip>

// Task 1
class Date
{
private:
    int day = 0;
    int month = 0;
    int year = 0;

public:
    void set_day(int value)
    {
        day = value;
    }
    void set_month(int value)
    {
        month = value;
    }
    void set_year(int value)
    {
        year = value;
    }
    int get_day() const
    {
        return day;
    }
    int get_month() const
    {
        return month;
    }
    int get_year() const
    {
        return year;
    }

public:
    friend std::ostream &operator<<(std::ostream &os, const Date &value)
    {
        return os << value.get_year() << "." << std::setw(2) << std::setfill('0') << value.get_month() << "."
                  << value.get_day();
    }
};
std::ostream &operator<<(std::ostream &os, const std::unique_ptr<Date> &value)
{
    return os << *value.get();
}
// Task 2
inline bool operator<=(const Date &value1, const Date &value2)
{
    int date1 = value1.get_day() + value1.get_month() + value1.get_year();
    int date2 = value2.get_day() + value2.get_month() + value2.get_year();
    return date1 <= date2;
}
inline bool operator<=(const std::unique_ptr<Date> &value1, const std::unique_ptr<Date> &value2)
{
    if (!value1 || !value2)
    {
        return false;
    }
    return *value1.get() <= *value2.get();
}
inline Date comparison(const Date &value1, const Date &value2)
{
    return value1 <= value2 ? value2 : value1;
}
inline void swap(std::unique_ptr<Date> &value1, std::unique_ptr<Date> &value2)
{
    value1.swap(value2);
}

int main()
{
    // Task 1
    auto today = std::make_unique<Date>();
    auto date = std::make_unique<Date>();
    today->set_day(18);
    today->set_month(7);
    today->set_year(2021);
    date.reset(today.release());
    if (today)
    {
        std::cout << "Today: " << today << std::endl;
    }
    else
    {
        std::cout << "Today is null!" << std::endl;
    }
    if (date)
    {
        std::cout << "Date: " << date << std::endl;
    }
    else
    {
        std::cout << "Date is null!" << std::endl;
    }
    // Task 2
    auto date1 = std::make_unique<Date>();
    auto date2 = std::make_unique<Date>();
    date1.reset(date.release());
    date2->set_year(2021);
    date2->set_month(11);
    date2->set_day(24);
    std::cout << "Date1: " << date1 << std::endl;
    std::cout << "Date2: " << date2 << std::endl;
    std::cout << "Last date: " << comparison(*date1.get(), *date2.get()) << std::endl;
    swap(date1, date2);
    std::cout << "Date1: " << date1 << std::endl;
    std::cout << "Date2: " << date2 << std::endl;
    return 0;
}
