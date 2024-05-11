// Made by Domantas Petkevicius, student of Vilniaus Universitetas, Matematikos ir Informatikos fakultetas (MIF), domasp902@gmail.com

#ifndef KEYWORD_CHECKER_H
#define KEYWORD_CHECKER_H

#include <iostream>

using namespace std;

// Implements functions that check input for certain keywords
class KeywordChecker
{

public:
    int checkForLife(string answer)
    {
        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("life") != string::npos)
        {
            return 1;
        }
        return 0;
    }

    int checkForMath(string answer)
    {
        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("math") != string::npos)
        {
            return 1;
        }
        return 0;
    }

    int checkForYes(string answer)
    {
        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("ye") != string::npos ||
            answer.find("ya") != string::npos ||
            answer.find("sure") != string::npos ||
            answer.find("ofc") != string::npos)
        {
            return 1;
        }
        return 0;
    }

    int checkForNo(string answer)
    {
        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("no") != string::npos ||
            answer.find("nah") != string::npos)
        {
            return 1;
        }
        return 0;
    }

    int checkForBye(string answer)
    {
        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("bye") != string::npos)
        {
            return 1;
        }
        return 0;
    }

    int checkForSubject(string answer)
    {
        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("math") != string::npos)
        {
            return 1;
        }
        else if (answer.find("it") != string::npos)
        {
            return 2;
        }
        else if (answer.find("bio") != string::npos)
        {
            return 3;
        }
        else if (answer.find("econ") != string::npos)
        {
            return 4;
        }
        else if (answer.find("operat") != string::npos)
        {
            return 5;
        }
        else if (answer.find("data") != string::npos)
        {
            return 6;
        }
        return 0;
    }

    int checkForDislikedThing(string answer)
    {
        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("lecturer") != string::npos)
        {
            return 1;
        }
        else if (answer.find("timetable") != string::npos ||
                 answer.find("time table") != string::npos)
        {
            return 2;
        }
        else if (answer.find("hard") != string::npos)
        {
            return 3;
        }
        else if (answer.find("grading") != string::npos)
        {
            return 4;
        }
        return 0;
    }
};

#endif