#include <iostream>
#include <ostream>
#include "Mystring.h"

int main() {

    Mystring empty{};

    Mystring john{"John"};

    Mystring john_copy{john};
    
    empty.set_str("Hello, World!");
    std::cout << empty.get_str() << std::endl;
    std::cout << john_copy.get_str() << std::endl;

    // copy assignment operator
    Mystring marge{"Marge"};
    Mystring table{"table"};
    table = marge;
    std::cout << table.get_str() << std::endl; // Marge

    // move assignment operatorddd
    Mystring glass{"glass"};
    glass = Mystring("Lenin");
    std::cout << glass.get_str() << std::endl; // Lenin

    // unary - operator
    Mystring scream{"EEEEEEEEEEEEEEEEE"};
    Mystring quiet_scream = -scream;
    std::cout << quiet_scream.get_str() << std::endl;

    std::cout << (john * 10).get_str() << std::endl;

    empty *= 5;

    // std::cout << empty << std::endl;
    // std::cin >> empty;
    // std::cout << empty << std::endl;


    return 0;
}

