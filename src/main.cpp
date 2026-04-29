#include "controller.h"
#include "digit.h"
#include "number.h"
#include <random>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


int main() {
    srand(time(NULL));
    Number toAddNumber = Number(1);
    Number resultNumber = Number(51);
    Controller controller(resultNumber, toAddNumber);
    controller.run();
}