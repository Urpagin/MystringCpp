#include <iostream>
#include <cstring>
#include "Mystring.h"

// no-arg constructor
Mystring::Mystring() {
    this->str = new char[1];
    this->str[0] = '\0';
}

// one-arg constructor
Mystring::Mystring(const char *str) {
    if (str == nullptr) {
        this->str = new char[1];
        this->str[0] = '\0'; // null terminator
    }
    else {
        this->str = new char[std::strlen(str) + 1];
        std::strcpy(this->str, str);
    }
}

// copy constructor
Mystring::Mystring(const Mystring &source) {
    this->str = new char[std::strlen(source.str) + 1];
    std::strcpy(this->str, source.str);
}

// destructor
Mystring::~Mystring() {
    delete [] this->str;
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


