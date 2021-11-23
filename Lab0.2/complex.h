#include <cmath>
#include <string>
#include <iostream>
class complex{
    public:
    complex(double a1, double b1);
    complex(const complex &c);
    complex();
    complex operator+(const complex &c1);
    complex operator-(const complex &c1);
    complex operator*(complex cc);
    complex operator/(complex cc);
    bool operator==(complex c);
    bool equm(complex c); //сравнение по модулю
    complex conj(); //сопряжённое

    complex& operator= (const complex &c);
    friend std::ostream& operator<<(std::ostream &out, const complex &c);
    friend std::istream& operator>> (std::istream &in, complex &c);
    void print(){
        std::cout <<"(" << a <<", " << b << "i)";
    };


    private:
        double a;
        double b;
};
    std::string operator "" _getimpart(const char* str, size_t size);
    std::string operator "" _getrealpart(const char* str, size_t size);

