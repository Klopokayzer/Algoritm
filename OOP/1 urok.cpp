#include <iostream>
#include <math.h>
#include <cstdint>
#include <array>

// Task 1
class Power
{
private:
    int m_num1;
    int m_num2;

public:
    void setnum(int num1, int num2)
    {
        m_num1 = num1;
        m_num2 = num2;
    }
    int calculate()
    {
        return pow(m_num1, m_num2);
    }
};
// Task 2
class RGBA
{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;

public:
    RGBA()
    {
    }

    RGBA(int red, int green, int blue, int alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }
    void print()
    {
        std::cout << (int)m_red << ", " << (int)m_green << ", " << (int)m_blue << ", " << (int)m_alpha << std::endl;
    }
};
// Task 3
class Stack
{
    private:
        std::array<int, 10> data;
        int size = 0;
    public:
        void reset(){
            for(int &item:data){
                item = 0;
            }
            size = 0;
        }
        bool push(int a){
            if(size < data.size()){
                data[size] = a;
                size++;
                return true;
            } else {
                return false;
            }
        }
        void print(){
            std::cout<<"( ";
            for(int i=0;i<size;i++){
                if(data[i]!=0){
                std::cout<<data[i]<<" ";
                }
            }
            std::cout<<")"<<std::endl;
        }
        int pop(){
            if(size >= 0){
                int a = data[size];
                data[size]=0;
                size--;
                return a;
            }else{
                std::cout<<"Stack is empty!"<<std::endl;
            }
            return 0;
        }
};
int main()
{
    //Task 1
    Power power;
    power.setnum(5, 2);
    std::cout << power.calculate() << std::endl;

    //Task 2
    RGBA RGBA1;
    RGBA1.print();
    int red;
    std::cin >> red;
    int green;
    std::cin >> green;
    int blue;
    std::cin >> blue;
    int alpha;
    std::cin >> alpha;
    RGBA RGBA2(red, green, blue, alpha);
    RGBA2.print();

    // Task 3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}