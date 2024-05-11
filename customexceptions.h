// Made by Domantas Petkevicius, student of Vilniaus Universitetas, Matematikos ir Informatikos fakultetas (MIF), domasp902@gmail.com

#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

using namespace std;

class InvalidRangeException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Number is not in the range specified.";
    }
};

class EmptyInputException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Empty input is not allowed.";
    }
};

#endif