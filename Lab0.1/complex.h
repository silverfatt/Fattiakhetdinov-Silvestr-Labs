#include <cmath>
#include <iostream>
class complex{
    public:
    complex(double a1, double b1);
    complex(const complex &c);
    
    void add(complex c); //сложение
    void sub(complex c); //вычитание
    void mul(complex c); //умножение
    void div(complex c); //деление
    bool equ(complex c); //сравнение
    bool equm(complex c); //сравнение по модулю
    complex conj(); //сопряжённое

    complex& operator= (const complex &c);
    void print(){
        std::cout <<"(" << a <<", " << b << "i)";
    };
    private:
        double a;
        double b;
};