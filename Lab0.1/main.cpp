#include "complex.h"
void printop(complex a, complex b, complex res, char c){
    a.print();
    std::cout << " " << c << " ";
    b.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";
};

int main(){
    double real, img, real2, img2;
    char option = 'y';
    while(option != 'n'){
    std::cout << "Enter first number: ";
    std::cin >> real >> img;
    std::cout << "Enter second number: ";
    std::cin >> real2 >> img2;
    complex c(real, img);
    complex c2(real2, img2);
    complex c1(c);

    c1.add(c2);
    printop(c, c2, c1, '+');

    c1 = c;
    c1.sub(c2);
    printop(c, c2, c1, '-');

    c1 = c;
    c1.mul(c2);
    printop(c, c2, c1, '*');

    c1 = c;
    c1.div(c2);
    printop(c, c2, c1, '/');

    c1 = c;
    if(c1.equ(c2)){
         c1.print();
         std::cout  << " = " ;
         c2.print();
         std::cout << "\n";
    }
    else{
         c1.print();
         std::cout  << " != " ;
         c2.print();
         std::cout << "\n";
    }

    c1 = c;
    if(c1.equm(c2)){
         c1.print();
         std::cout  << " = " ;
         c2.print();
         std::cout << " (absolutely)\n";
    }
    else{
         c1.print();
         std::cout  << " != " ;
         c2.print();
         std::cout << " (absolutely)\n";
    }
    std::cout << "Conj for ";
    c.print(); 
    std::cout <<  " is: ";
    complex cconj = c.conj();
    cconj.print();
    std::cout << "\n";
    std::cout << "Continue?\ny/n: ";
    std::cin >> option;
    while(option != 'y' && option != 'n'){
    std::cout << "Continue?\ny/n: ";
    std::cin >> option;
    };
    std::cout << "Shutting down...\n";
    }
}