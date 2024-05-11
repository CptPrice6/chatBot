// Made by Domantas Petkevicius, student of Vilniaus Universitetas, Matematikos ir Informatikos fakultetas (MIF), domasp902@gmail.com

#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <iostream>

#include "customexceptions.h"

using namespace std;

// Implements functions that validate the input.
class InputValidator
{
public:
    // Validates input, if the input is empty throws EmptyInputException
    string getAndValidateInputNotEmpty()
    {
        string answer = "";

        getline(cin, answer);

        if (answer == "" || answer == "")
        {
            throw EmptyInputException();
        }

        return answer;
    }
    // validates if the answer is in range, if not throws InvalidRangeException
    bool validateRange(int answer, int rangeBegin, int rangeEnd)
    {

        if (answer > rangeEnd || answer < rangeBegin)
        {
            throw InvalidRangeException();
        }

        return 1;
    }
};

#endif