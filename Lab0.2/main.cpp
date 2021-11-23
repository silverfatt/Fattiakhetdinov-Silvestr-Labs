#include <iostream>
#include "complex.h"

int main(){
    complex a,b;
    char option = 'y';
    while(option == 'y'){
    std::cout << "Enter 2 complex numbers: \n";
    std::cin >> a >> b;
    std::cout << a << " + " << b << " = " << a+b << "\n";
    std::cout << a << " - " << b << " = "  << a-b << "\n";
    std::cout << a << " * " << b << " = "  << a*b << "\n";
    std::cout << a << " / " << b << " = "  << a/b << "\n";
    if (a == b) std::cout << a << " = " << b << "\n";
    else std::cout << a << " != " << b << "\n";
    std::cout << "Continue?\ny/n: \n";
    std::cin >> option;
    while(option != 'y' && option != 'n'){
       std::cout << "Continue?\ny/n: \n";
    std::cin >> option; 
    }
    }
    std::cout << "Literals test: \n";
    std::cout << "Your complex number is: " << "2i+3"_getimpart << "*i" << "2i+3"_getrealpart << std:: endl;
    std::cout << "Your complex number is: " << "100i+10"_getimpart << "*i" << "100i+10"_getrealpart << std:: endl;
    std::cout << "Your complex number is: " << "50i+13"_getimpart << "*i" << "50i+13"_getrealpart << std:: endl;
    std::cout << "Shutting down...\n";
    return 0;
}