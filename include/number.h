#include <vector>

class Number {
private:
    int length;
    std::vector<int> digits;
    bool negative;
    
public:
    Number();
    Number(int);
    void genNumber();
};