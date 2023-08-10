class Mystring {
private:
    char *str;
public:
    Mystring(); // no-arg constructor
    Mystring(const char *str); // one-arg constructor
    Mystring(const Mystring &source); // copy constructor
    ~Mystring(); // destructor

    const char* get_str() const; // getter
    void set_str(const char *str); // setter
};