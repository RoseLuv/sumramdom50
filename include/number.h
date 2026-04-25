#include <vector>
#include "digit.h"


class Number {
private:
    int length;
    std::vector<Digit> digits;
    bool negative;

public:
    Number();
    Number(int);
    void genNumber();
    bool addNumber(Number);
};