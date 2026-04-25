#include "controller.h"
#include "digit.h"
#include "number.h"
#include <random>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>



int main() {
    srand(time(NULL));
    Number toAddNumber = Number(1);
    Number resultNumber = Number();
    resultNumber.emptyNumber();

    for(int i = 0; i < 5; i++) {
        toAddNumber.genNumber();
        toAddNumber.printNumber();
        resultNumber.printNumber();
        resultNumber.addNumber(toAddNumber);
        
        toAddNumber.incLength();
        toAddNumber.genNumber();
    }

    resultNumber.printNumber();
}