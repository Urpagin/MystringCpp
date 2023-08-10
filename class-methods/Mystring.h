# ifndef _MYSTRING_H_
# define _MYSTRING_H_
#include <iostream>
#include <istream>
#include <ostream>

class Mystring {
    friend std::ostream& operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream& operator>>(std::istream &is, Mystring &rhs);
private:
    char *str;
public:
    Mystring(); // no-arg constructor
    Mystring(const char *str); // one-arg constructor
    Mystring(const Mystring &source); // copy constructor
    Mystring(Mystring &&source); // move constructor
    ~Mystring(); // destructor

    Mystring& operator=(const Mystring &rhs); // copy assignment operator
    Mystring& operator=(Mystring &&rhs); // move assignment operator
    Mystring operator-() const; // unary minus, no args but itself
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs)const;
    bool operator<(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    Mystring operator+(const Mystring &rhs)const ; // concatenation
    Mystring& operator+=(const Mystring &rhs); // concat++
    Mystring operator*(const int &num) const; // multiplication
    Mystring& operator*=(const int &num); // multiplication++

    const char* get_str() const; // getter
    void set_str(const char *str); // setter
};

#endif