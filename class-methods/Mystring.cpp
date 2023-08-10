#include <cctype>
#include <cstddef>
#include <iostream>
#include <cstring>
#include "Mystring.h"
#include <iostream>
#include <istream>
#include <ostream>

// no-arg constructor
Mystring::Mystring() 
: str{new char[1]} {
    this->str[0] = '\0';
}

// init str for member initialization for one-arg constructor
char* init_str(const char *str) {
    if (str == nullptr) {
        char *temp{new char[1]};
        temp[0] = '\0';
        return temp;
    }
    else {
        char *temp{new char[std::strlen(str) + 1]};
        std::strcpy(temp, str);
        return temp;
    }
}

// one-arg constructor
Mystring::Mystring(const char *s) : str{init_str(s)} {}

// copy constructor
Mystring::Mystring(const Mystring &source) 
: str{new char[std::strlen(source.str) + 1]} {
    std::strcpy(this->str, source.str);
}

// move constructor
Mystring::Mystring(Mystring &&source)
    : str{source.str} {
    source.str = nullptr;
}

// destructor
Mystring::~Mystring() {
    delete [] this->str;
}

// copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    // Prevents self-assignment
    if (this == &rhs) 
        return *this;
    
    this->str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// move assignment operator
Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs)
        return *this;
    
    this->str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// unary minus
Mystring Mystring::operator-() const{
    size_t len{std::strlen(this->str)};
    char *temp{new char[len + 1]};
    for (size_t i{0}; i < len; ++i)
        temp[i] = std::tolower(this->str[i]);
    temp[len] = '\0';
    Mystring lowercase{temp};
    delete [] temp;
    return lowercase;
}

// == operator
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) == 0);
}

// != operator
bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) != 0);
}

// < operator
bool Mystring::operator<(const Mystring &rhs) const {
    return this->str[0] < rhs.str[0];
}

// > operator
bool Mystring::operator>(const Mystring &rhs) const {
    return this->str[0] > rhs.str[0];
}

// + operator
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buffer{new char[std::strlen(this->str) + std::strlen(rhs.str) + 1]};
    std::strcpy(buffer, this->str);
    std::strcat(buffer, rhs.str);
    Mystring concat{buffer};
    delete [] buffer;
    return concat;
}

// += operator
Mystring& Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

// * operator
Mystring Mystring::operator*(const int &num) const {
    char *buffer{new char[std::strlen(this->str) * num + 1]};
    std::strcpy(buffer, this->str);
    for (size_t i{0}; i < num-1; ++i) 
        std::strcat(buffer, this->str);
    Mystring mult{buffer};
    delete [] buffer;
    return mult;
}

Mystring &Mystring::operator*=(const int &num) {
    *this = *this * num;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

std::istream& operator>>(std::istream &is, Mystring &rhs) {
    char *buffer{new char[1000]};
    is >> buffer;
    delete [] rhs.str;
    rhs.str = buffer;
    return is;
}

// getter
const char* Mystring::get_str() const {
    return this->str;
}

// setter
void Mystring::set_str(const char *str) {
    delete [] this->str;
    if (str == nullptr) {
        this->str = new char[1];
        this->str[0] = '\0';
    }
    else {
        this->str = new char[std::strlen(str) + 1];
        std::strcpy(this->str, str);
    }
}


