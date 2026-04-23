#include "number.h"
class Controller {
public:
    Controller(Number& num) : num(num) {};
    void run();
private:    
    Number& num;
};