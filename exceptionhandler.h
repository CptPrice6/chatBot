// Made by Domantas Petkevicius, student of Vilniaus Universitetas, Matematikos ir Informatikos fakultetas (MIF), domasp902@gmail.com

#include <iostream>
#include <typeinfo>
#include <exception>
#include "customexceptions.h"

using namespace std;

class ExceptionHandler
{
public:
    void handleException(exception &err)
    {
        if (typeid(err) == typeid(EmptyInputException))
        {
            cout << err.what();
        }
        else if (typeid(err) == typeid(InvalidRangeException))
        {
            cout << err.what();
        }
        else if (typeid(err) == typeid(invalid_argument))
        {
            cout << "You must input a number! Why are you trying to cause a bug?\nNow input an answer(number please):";
        }
        else if (typeid(err) == typeid(out_of_range))
        {
            cout << "You entered a number out of range, please enter a valid number and do not try to cause overflows next time:";
        }
        else
        {
            cout << "Unknown exception occured: " << err.what();
        }
    }
};
