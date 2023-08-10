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

    return 0;
}

