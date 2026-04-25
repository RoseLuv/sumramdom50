#include <cstddef>

class Digit{
public:
    Digit();
    Digit(unsigned char, bool);
    void genDigit(bool);
    bool addDigit(Digit);

private:
    unsigned char digit;
};