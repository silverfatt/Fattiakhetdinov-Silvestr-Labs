#include "complex.h"
    complex::complex(double a1, double b1){
        a = a1;
        b = b1;
    }
    complex::complex(const complex &c){
        a = c.a;
        b = c.b;
    }
    complex::complex(){
        a = 0;
        b = 0;
    };
    complex complex::operator+(const complex &c1){
        complex ans(a+c1.a, b+c1.b);
        return ans;
    };
    complex complex::operator-(const complex &c1){
        complex ans(a-c1.a, b-c1.b);
        return ans;
    };
    complex complex::operator*(complex cc){
        double c = cc.a;
        double d = cc.b;
        double a1 = a*c - b*d;     
        double b1 =  a*d + b*c; 
        complex ans(a1, b1);
        return ans;
    }
    complex complex::operator/(complex cc){
        double c = cc.a;
        double d = cc.b;
        double a1 = (a*c + b*d) / (c*c + d*d);
        double b1 =  (b*c - a*d) / (c*c + d*d); 
        complex ans(a1, b1);
        return ans;
    }
    bool complex::operator==(complex c){
        if (a == c.a && b == c.b) return true;
        return false;
    }
    bool complex::equm(complex c){
        if (abs(a) == abs(c.a) && abs(b) == abs(c.b)) return true;
        return false;
    }
    complex complex::conj(){
        complex ans(a, -b);
        return ans;
    }

    complex& complex::operator= (const complex &c){
        a = c.a;
        b = c.b;
        return *this;
    }
    std::ostream& operator<< (std::ostream &out, const complex &c){
        out << "(" << c.a << ", " << c.b << ") ";
        return out;
    };
    std::istream& operator>> (std::istream &in, complex &c)
    {
    in >> c.a;
    in >> c.b;
    return in;
    }

    std::string operator "" _getimpart(const char* str, size_t size) { 
    int k = 0;
    std:: string im_part;
    while (str[k] != 'i') {
        im_part.push_back(str[k]);
        ++k;
    }
    return im_part;
}

std::string operator "" _getrealpart(const char* str, size_t size) {
    int k = 0;
    std:: string real_part;
    while (str[k] != 'i') {
        ++k;
    }
    ++k;
    while (str[k] != '\0') {
        real_part.push_back(str[k]);
        ++k;
    }
    return real_part;
}
