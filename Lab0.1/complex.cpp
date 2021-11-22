#include "complex.h"
    complex::complex(double a1, double b1){
        a = a1;
        b = b1;
    }
    complex::complex(const complex &c){
        a = c.a;
        b = c.b;
    }
    void complex::add(complex c){
        a = a + c.a;
        b = b + c.b;
    }
    void complex::sub(complex c){
        a = a - c.a;
        b = b - c.b;
    }
    void complex::mul(complex cc){
        double c = cc.a;
        double d = cc.b;
        double a1 = a*c - b*d;
        b =  a*d + b*c; 
        a = a1;
    }
    void complex::div(complex cc){
        double c = cc.a;
        double d = cc.b;
        double a1 = (a*c + b*d) / (c*c + d*d);
        b =  (b*c - a*d) / (c*c + d*d); 
        a = a1;
    }
    bool complex::equ(complex c){
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