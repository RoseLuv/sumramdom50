# sumramdom50

TODO:
    Refactor calcResult();
    Update prev tests and add to tests all other methods

    Line: if(calculatingNumber.getLength() > resultNumber.getLengthWithoutLeading()) {
                resultNumber = calculatingNumber.doOperation(resultNumber, false);
            } else {
                resultNumber = resultNumber.doOperation(calculatingNumber, false); 
            }
    in controller.cpp possibly not needed due to changes in doOperation