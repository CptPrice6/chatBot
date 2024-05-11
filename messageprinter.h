// Made by Domantas Petkevicius, student of Vilniaus Universitetas, Matematikos ir Informatikos fakultetas (MIF), domasp902@gmail.com

#ifndef MESSAGE_PRINTER_H
#define MESSAGE_PRINTER_H

#include <iostream>
#include <map>

#include "messages.h"
using namespace std;

// use system("cls") for Windows, system("clear") for Unix like OS
#ifdef _WIN32
const string CLEAR_COMMAND = "cls";
#else
const string CLEAR_COMMAND = "clear";
#endif

map<string, int> easyMathProblems = {
    {"2+2=", 4},
    {"9+3=", 12},
    {"6+8=", 14},
    {"7+10=", 17},
    {"5+30=", 35},
    {"5-2=", 3},
    {"10-6=", 4},
    {"5+8-2", 11},
    {"23-10+1=", 14},
    {"35-19=", 16},
};

map<string, int> normalMathProblems = {
    {"3*5+2=", 17},
    {"10*10+4=", 104},
    {"100+68-20=", 148},
    {"45-30*2=", -15},
    {"10/2*5=", 25},
    {"6*3-10=", 8},
    {"(68-32)/6=", 6},
    {"6*5+3*(-4)=", 18},
    {"65-15*3=", 20},
    {"44/2*3", 66},
};

map<string, int> hardMathProblems = {
    {"100/20*5+(30*2-50/2)=", 60},
    {"68*13=", 884},
    {"35*37=", 1295},
    {"19*13+10=", 257},
    {"15*51-20=", 745},
    {"50/2*5+(300*2-78/2)=", 686},
    {"13^2-10^2=", 69},
    {"56-32*17=", -488},
    {"45^2+3=", 2028},
    {"13*14*15=", 2730},
};

// Implements functions that format and print a specific message.
class MessagePrinter
{

public:
    // prints message, clears screen if needed and appends user's name to output's beginning.
    void printMsg(string message, bool isClearScreenNeeded = 0, string name = "")
    {
        if (isClearScreenNeeded)
        {
            clearScreen();
        }

        cout << name << ", " << message;
    }

    void clearScreen()
    {
        system(CLEAR_COMMAND.c_str());
    }

    map<string, int> printDifficultyMessages(int diff, int moodState, string name)
    {
        if (diff == 1) // easy difficulty was chosen
        {
            printEasyDifficultyMessages(moodState, name);
            return easyMathProblems;
        }
        else if (diff == 2) // normal difficulty was chosen
        {
            printNormalDifficultyMessages(moodState, name);
            return normalMathProblems;
        }
        else if (diff == 3) // hard difficulty was chosen
        {
            printHardDifficultyMessages(moodState, name);
            return hardMathProblems;
        }
    }

    void printEasyDifficultyMessages(int moodState, string name)
    {
        if (moodState < 5)
        {
            printMsg(Msg::EASY_DIFFICULTY_BAD_MOOD_MESSAGE, 1, name);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            printMsg(Msg::EASY_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1, name);
        }
        else
        {
            printMsg(Msg::EASY_DIFFICULTY_GOOD_MOOD_MESSAGE, 1, name);
        }
    }

    void printNormalDifficultyMessages(int moodState, string name)
    {
        if (moodState < 5)
        {
            printMsg(Msg::NORMAL_DIFFICULTY_BAD_MOOD_MESSAGE, 1, name);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            printMsg(Msg::NORMAL_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1, name);
        }
        else
        {
            printMsg(Msg::NORMAL_DIFFICULTY_GOOD_MOOD_MESSAGE, 1, name);
        }
    }
    void printHardDifficultyMessages(int moodState, string name)
    {
        if (moodState < 5)
        {
            printMsg(Msg::HARD_DIFFICULTY_BAD_MOOD_MESSAGE, 1, name);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            printMsg(Msg::HARD_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1, name);
        }
        else
        {
            printMsg(Msg::HARD_DIFFICULTY_GOOD_MOOD_MESSAGE, 1, name);
        }
    }

    void printFirstProblemMessages(int moodState)
    {
        if (moodState < 5)
        {
            cout << Msg::FIRST_PROBLEM_BAD_MOOD_MESSAGE;
        }
        else if (moodState >= 5 && moodState < 15)
        {
            cout << Msg::FIRST_PROBLEM_NORMAL_MOOD_MESSAGE;
        }
        else
        {
            cout << Msg::FIRST_PROBLEM_GOOD_MOOD_MESSAGE;
        }
    }
    void printLastProblemMessages(int moodState)
    {
        if (moodState < 5)
        {
            cout << Msg::LAST_PROBLEM_BAD_MOOD_MESSAGE;
            sleep(3);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            cout << Msg::LAST_PROBLEM_NORMAL_MOOD_MESSAGE;
            sleep(3);
        }
        else
        {
            cout << Msg::LAST_PROBLEM_GOOD_MOOD_MESSAGE;
            sleep(3);
        }
    }
    void printContinueProblemMessages(int problemCounter, int moodState)
    {
        if (moodState < 5)
        {
            cout << Msg::CONTINUE_PROBLEM_BAD_MOOD_MESSAGE;
            cout << problemCounter << ".\n";
            sleep(3);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            cout << Msg::CONTINUE_PROBLEM_NORMAL_MOOD_MESSAGE;
            cout << problemCounter << ".\n";
            sleep(3);
        }
        else
        {
            cout << Msg::CONTINUE_PROBLEM_GOOD_MOOD_MESSAGE;
            cout << problemCounter << ".\n";
            sleep(3);
        }
    }

    void printProblem(string problem, int moodState, string name)
    {

        if (moodState < 5)
        {
            printMsg(Msg::MATH_PROBLEM_BAD_MOOD_MESSAGE, 0, name);
            cout << problem << "\n";
        }
        else if (moodState >= 5 && moodState < 15)
        {
            printMsg(Msg::MATH_PROBLEM_NORMAL_MOOD_MESSAGE, 0, name);
            cout << problem << "\n";
        }
        else
        {
            printMsg(Msg::MATH_PROBLEM_GOOD_MOOD_MESSAGE, 0, name);
            cout << problem << "\n";
        }
    }

    void printCorrectMessage(int moodState, string name)
    {
        if (moodState < 5)
        {
            printMsg(Msg::CORRECT_BAD_MOOD_MESSAGE, 1, name);
            sleep(3);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            printMsg(Msg::CORRECT_NORMAL_MOOD_MESSAGE, 1, name);
            sleep(3);
        }
        else
        {
            printMsg(Msg::CORRECT_GOOD_MOOD_MESSAGE, 1, name);
            sleep(3);
        }
        moodState++;
    }

    void printIncorrectMessage(int moodState, string name)
    {
        if (moodState < 5)
        {
            cout << endl;
            printMsg(Msg::INCORRECT_BAD_MOOD_MESSAGE, 1, name);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            cout << endl;
            printMsg(Msg::INCORRECT_NORMAL_MOOD_MESSAGE, 1, name);
        }
        else
        {
            cout << endl;
            printMsg(Msg::INCORRECT_GOOD_MOOD_MESSAGE, 1, name);
        }
    }

    void printMessagesAboutStudiesIfLikes(int subj, string name)
    {
        if (subj == 0)
        {
            printMsg(Msg::UNKNOWN_SUBJECT_MESSAGE, 1, name);
        }
        else if (subj == 1)
        {
            printMsg(Msg::MATH_SUBJECT_MESSAGE, 1, name);
        }
        else if (subj == 2)
        {
            printMsg(Msg::IT_SUBJECT_MESSAGE, 1, name);
        }
        else if (subj == 3)
        {
            printMsg(Msg::BIOLOGY_SUBJECT_MESSAGE, 1, name);
        }
        else if (subj == 4)
        {
            printMsg(Msg::ECONOMICS_SUBJECT_MESSAGE, 1, name);
        }
        else if (subj == 5)
        {
            printMsg(Msg::OPERATING_SYSTEMS_SUBJECT_MESSAGE, 1, name);
        }
        else if (subj == 6)
        {
            printMsg(Msg::DATA_STRUCTURES_SUBJECT_MESSAGE, 1, name);
        }
    }

    void printMessagesAboutStudiesIfDislikes(int disl, string name)
    {
        if (disl == 0)
        {
            printMsg(Msg::DEFAULT_DISLIKE_MESSAGE, 1, name);
        }
        else if (disl == 1)
        {
            printMsg(Msg::LECTURERS_DISLIKE_MESSAGE, 1, name);
        }
        else if (disl == 2)
        {
            printMsg(Msg::TIMETABLES_DISLIKE_MESSAGE, 1, name);
        }
        else if (disl == 3)
        {
            printMsg(Msg::HARD_DISLIKE_MESSAGE, 1, name);
        }
        else if (disl == 4)
        {
            printMsg(Msg::GRADING_DISLIKE_MESSAGE, 1, name);
        }
    }

    void printJobSphereMessages(int intAnswer, string name)
    {
        if (intAnswer == 1)
        {
            printMsg(Msg::WORK_IT_SPHERE_MESSAGE, 1, name);
        }
        else if (intAnswer == 2)
        {
            printMsg(Msg::WORK_SERVICE_SPHERE_MESSAGE, 1, name);
        }
        else if (intAnswer == 3)
        {
            printMsg(Msg::WORK_MANUAL_SPHERE_MESSAGE, 1, name);
        }
    }

    void printWantedJobSphereMessages(int intAnswer, string name)
    {

        if (intAnswer == 1)
        {
            printMsg(Msg::ASPIRE_IT_SPHERE_MESSAGE, 1, name);
        }
        else if (intAnswer == 2)
        {
            printMsg(Msg::ASPIRE_SERVICE_SPHERE_MESSAGE, 1, name);
        }
        else if (intAnswer == 3)
        {
            printMsg(Msg::ASPIRE_MANUAL_SPHERE_MESSAGE, 1, name);
        }
    }

    void askDifficulty(int moodState, string name)
    {
        if (moodState < 5)
        {
            printMsg(Msg::ASK_MATH_DIFFICULTY_BAD_MOOD_MESSAGE, 1, name);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            printMsg(Msg::ASK_MATH_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1, name);
        }
        else
        {
            printMsg(Msg::ASK_MATH_DIFFICULTY_GOOD_MOOD_MESSAGE, 1, name);
        }
    }
    void printByeMessages(int moodState, string name)
    {
        if (moodState < 5)
        {
            printMsg(Msg::INPUT_BYE_BAD_MOOD_MESSAGE, 0, name);
        }
        else if (moodState >= 5 && moodState < 15)
        {
            printMsg(Msg::INPUT_BYE_NORMAL_MOOD_MESSAGE, 0, name);
        }
        else
        {
            printMsg(Msg::INPUT_BYE_GOOD_MOOD_MESSAGE, 0, name);
        }
    }
    void printProblemMessages(int problemCounter, int moodState)
    {
        if (problemCounter == 1)
        {
            printFirstProblemMessages(moodState);
        }
        else
        {
            if (problemCounter == 5)
            {
                printLastProblemMessages(moodState);
            }
            else
            {
                printContinueProblemMessages(problemCounter, moodState);
            }
        }
    }
    void printMathDifficultyMessages(int solveCounter, string name, int moodState)
    {
        if (solveCounter == 0)
        {
            printMsg(Msg::ASK_MATH_DIFFICULTY_FIRST_MESSAGE, 1, name);
        }
        else if (solveCounter > 10)
        {
            printMsg(Msg::ASK_MATH_DIFFICULTY_REST_MESSAGE, 1, name);
        }
        else
        {
            askDifficulty(moodState, name);
        }
    }
};
#endif