#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <string>
#include <unistd.h>

#include "messages.h"

using namespace std;

// use system("cls") for Windows, system("clear") for Unix like OS
#ifdef _WIN32
const std::string CLEAR_COMMAND = "cls";
#else
const std::string CLEAR_COMMAND = "clear";
#endif

// functions that check input for some specific words
int checkForBye(string answer);
int checkForLife(string answer);
int checkForYes(string answer);
int checkForDislikedThing(string answer);
int checkForSubject(string answer);
int checkForNo(string answer);
int checkForMath(string answer);
int checkForDifficulty();

// two main functions
void talkAboutLife();
void talkAboutMaths();

// function that formats a message and prints it
void printMsg(string message, bool isClearScreenNeeded);

// function that clears screen
void clearScreen();

// functions to print out messages when talking about life
void talkAboutStudiesIfLikes();
void talkAboutStudiesIfDislikes();
void talkAboutJob();
void talkAboutWantedJob();
void talkAboutMovies();
void talkAboutMusic();

// functions to print out messages when talking about maths
void askDifficulty();
void printEasyDifficultyMessages();
void printNormalDifficultyMessages();
void printHardDifficultyMessages();
void printFirstProblemMessages();
void printLastProblemMessages();
void printContinueProblemMessages(int problemCounter);
void printByeMessagesAndCheckForBye();
void printProblem(string problem);
int checkProblemInput();
void printCorrectMessage();
void printIncorrectMessage();

vector<string> introductionPhrases =
    {"Hey!", "Hello!", "Yo!",
     "What's up?", "Hey, how are you doing?",
     "Hi, hope you are doing well!"};

vector<string> farewellPhrases =
    {"Bye!", "Goodbye!", "Hope to see you soon!",
     "Was nice talking to you!", "Farewell!",
     "Bye bye!"};

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

string name = "";
int moodState = 10;
bool isFirstConversation = 1;

int main()
// My main objective was to make a fun math problem-solving chatbot, that reacts to the user's answers and changes program answers(mood) depending on them
// Also I added a functionality to have a short conversation about other topics

// V2 Changes:
// Done some refactoring, improved layout, naming, UI, added functions, improved modularity, separated data from the logic
// All messages are held as constants in messages.h
// Made the program foolproof, all errors are handled
// Started using git for version control
{
    srand((unsigned)time(NULL));
    string answer;
    int randomNum = rand() % introductionPhrases.size();
    cout << introductionPhrases[randomNum] + "\n";
    getline(cin, answer);

    cout << Msg::INTRODUCTION_MESSAGE;
    getline(cin, name);

    printMsg(Msg::END_CONVERSATION_MESSAGE, 1);
    getline(cin, answer);

    if (checkForBye(answer))
    {
        int randomNum = rand() % farewellPhrases.size();
        cout << farewellPhrases[randomNum] + "\n";
        return 0;
    }

    printMsg(Msg::ASK_MATH_OR_LIFE_MESSAGE, 1);
    getline(cin, answer);
    if (checkForBye(answer))
    {
        int randomNum = rand() % farewellPhrases.size();
        cout << farewellPhrases[randomNum] + "\n";
        return 0;
    }
    if (checkForLife(answer))
    {
        talkAboutLife();
    }
    else
    {
        talkAboutMaths();
    }
}

void talkAboutLife()
{
    while (1)
    {
        string answer;
        int randomNum = rand() % 3;
        if (isFirstConversation)
        {
            printMsg(Msg::INTRODUCE_LIFE_CHATBOT_MESSAGE, 1);
            sleep(2);
            isFirstConversation = 0;
        }
        if (randomNum == 0)
        {
            printMsg(Msg::ASK_STUDENT_MESSAGE, 1);
            getline(cin, answer);
            if (checkForYes(answer))
            {
                printMsg(Msg::STUDENT_RESPONSE_MESSAGE, 1);
                getline(cin, answer);

                printMsg(Msg::STUDY_PLACE_RESPONSE_MESSAGE, 1);
                getline(cin, answer);
                if (checkForYes(answer))
                {
                    talkAboutStudiesIfLikes();
                }
                else
                {
                    talkAboutStudiesIfDislikes();
                }
            }
            else
            {
                printMsg(Msg::WHY_NOT_STUDENT_MESSAGE, 1);
                getline(cin, answer);
                printMsg(Msg::STUDIES_IMPORTANT_MESAGE, 1);
            }
        }
        else if (randomNum == 1)
        {
            printMsg(Msg::ASK_JOB_MESSAGE, 1);

            getline(cin, answer);
            if (checkForYes(answer))
            {
                talkAboutJob();
            }
            else
            {
                talkAboutWantedJob();
            }
        }
        else if (randomNum == 2)
        {
            printMsg(Msg::ASK_MUSIC_MESSAGE, 1);
            getline(cin, answer);
            if (checkForYes(answer))
            {
                talkAboutMusic();
            }
            else
            {
                talkAboutMovies();
            }
        }

        cout << Msg::CONTINUE_OR_MATH_MESSAGE;
        getline(cin, answer);
        if (checkForMath(answer))
        {
            talkAboutMaths();
            break;
        }
    }
}

void talkAboutMaths()
{
    if (isFirstConversation)
    {
        printMsg(Msg::INTRODUCE_MATH_CHATBOT_MESSAGE, 1);
        sleep(2);
        isFirstConversation = 0;
    }

    int solveCounter = 0;
    while (1)
    {
        string answer;
        if (solveCounter == 0)
        {
            printMsg(Msg::ASK_MATH_DIFFICULTY_FIRST_MESSAGE, 1);
        }
        else if (solveCounter > 10)
        {
            printMsg(Msg::ASK_MATH_DIFFICULTY_REST_MESSAGE, 1);
        }
        else
        {
            askDifficulty();
        }
        int diff = checkForDifficulty();
        map<string, int> chosenProblems;

        if (diff == 4)
        {
            talkAboutLife();
            break;
        }

        if (diff == 1) // easy difficulty was chosen
        {
            printEasyDifficultyMessages();
            chosenProblems = easyMathProblems;
        }
        else if (diff == 2) // normal difficulty was chosen
        {
            printNormalDifficultyMessages();
            chosenProblems = normalMathProblems;
        }
        else if (diff == 3) // hard difficulty was chosen
        {
            printHardDifficultyMessages();
            chosenProblems = hardMathProblems;
        }

        int problemCounter = 1;
        while (problemCounter <= 5)
        {
            if (problemCounter == 1)
            {
                printFirstProblemMessages();
            }
            else
            {
                if (problemCounter == 5)
                {
                    solveCounter++;
                    printLastProblemMessages();
                }
                else
                {
                    printContinueProblemMessages(problemCounter);
                }
            }

            if (problemCounter == 1)
            {
                printByeMessagesAndCheckForBye();
            }
            int randomNum = rand() % chosenProblems.size();
            int counter = 0;
            int problemAnswer;
            for (auto &t : chosenProblems)
            {
                if (counter == randomNum)
                {
                    problemAnswer = t.second;
                    printProblem(t.first);
                }
                counter++;
            }
            while (1)
            {
                int intAnswer = checkProblemInput();
                cout << intAnswer;
                if (intAnswer == problemAnswer)
                {
                    printCorrectMessage();
                    problemCounter++;
                    break;
                }
                else
                {
                    printIncorrectMessage();
                    moodState--;
                    continue;
                }
            }
        }
    }
}

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
    if (answer.find("ye") != string::npos)
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

int checkForDifficulty()
{
    string answer;
    int counter = 0;
    while (1)
    {
        getline(cin, answer);
        if (checkForBye(answer))
        {
            int randomNum = rand() % farewellPhrases.size();
            cout << farewellPhrases[randomNum] + "\n";
            exit(0);
        }
        if (checkForLife(answer))
        {
            return 4;
        }

        for (auto &x : answer)
        {
            x = tolower(x);
        }
        if (answer.find("easy") != string::npos)
        {
            return 1;
        }
        else if (answer.find("normal") != string::npos)
        {
            return 2;
        }
        else if (answer.find("hard") != string::npos)
        {
            return 3;
        }
        else
        {
            if (counter > 3)
            {
                printMsg(Msg::NAME_DIFFICULTY_MESSAGE, 1);
                moodState--;
                continue;
            }
            printMsg(Msg::SPECIFY_DIFFICULTY_MESSAGE, 1);
            moodState--;
            counter++;
        }
    }
}

void printMsg(string message, bool isClearScreenNeeded = 0)
{
    if (isClearScreenNeeded)
    {
        clearScreen();
    }

    cout << name << ", " << message;
}

void talkAboutStudiesIfLikes()
{
    string answer;
    printMsg(Msg::STUDY_LIKE_MESSAGE, 1);
    getline(cin, answer);

    int subj = checkForSubject(answer);
    if (subj == 0)
    {
        printMsg(Msg::UNKNOWN_SUBJECT_MESSAGE, 1);
    }
    else if (subj == 1)
    {
        printMsg(Msg::MATH_SUBJECT_MESSAGE, 1);
    }
    else if (subj == 2)
    {
        printMsg(Msg::IT_SUBJECT_MESSAGE, 1);
    }
    else if (subj == 3)
    {
        printMsg(Msg::BIOLOGY_SUBJECT_MESSAGE, 1);
    }
    else if (subj == 4)
    {
        printMsg(Msg::ECONOMICS_SUBJECT_MESSAGE, 1);
    }
    else if (subj == 5)
    {
        printMsg(Msg::OPERATING_SYSTEMS_SUBJECT_MESSAGE, 1);
    }
    else if (subj == 6)
    {
        printMsg(Msg::DATA_STRUCTURES_SUBJECT_MESSAGE, 1);
    }

    printMsg(Msg::STUDIES_FINISHED_MESSAGE, 0);
    getline(cin, answer);
    printMsg(Msg::STUDIES_FINISH_MESSAGE, 1);
}

void talkAboutStudiesIfDislikes()
{
    string answer;
    printMsg(Msg::STUDY_DISLIKE_MESSAGE, 1);
    getline(cin, answer);
    int disl = checkForDislikedThing(answer);

    if (disl == 0)
    {
        printMsg(Msg::DEFAULT_DISLIKE_MESSAGE, 1);
    }
    else if (disl == 1)
    {
        printMsg(Msg::LECTURERS_DISLIKE_MESSAGE, 1);
    }
    else if (disl == 2)
    {
        printMsg(Msg::TIMETABLES_DISLIKE_MESSAGE, 1);
    }
    else if (disl == 3)
    {
        printMsg(Msg::HARD_DISLIKE_MESSAGE, 1);
    }
    else if (disl == 4)
    {
        printMsg(Msg::GRADING_DISLIKE_MESSAGE, 1);
    }

    printMsg(Msg::STUDIES_FINISHED_MESSAGE, 0);
    getline(cin, answer);
    printMsg(Msg::STUDIES_FINISH_MESSAGE, 1);
}

void talkAboutJob()
{
    string answer;
    printMsg(Msg::JOB_TYPE_MESSAGE, 1);
    string input;
    int intAnswer;
    while (1)
    {
        getline(cin, input);

        try
        {
            intAnswer = stoi(input);
        }
        catch (exception &err)
        {
            printMsg(Msg::INPUT_NUMBER_BETWEEN_1_3_MESSAGE, 1);
            moodState--;
            continue;
        }

        if (intAnswer > 3 || intAnswer < 1)
        {
            printMsg(Msg::INPUT_NUMBER_BETWEEN_1_3_MESSAGE, 1);
            continue;
        }

        break;
    }
    if (intAnswer == 1)
    {
        printMsg(Msg::WORK_IT_SPHERE_MESSAGE, 1);
    }
    else if (intAnswer == 2)
    {
        printMsg(Msg::WORK_SERVICE_SPHERE_MESSAGE, 1);
    }
    else if (intAnswer == 3)
    {
        printMsg(Msg::WORK_MANUAL_SPHERE_MESSAGE, 1);
    }
}

void talkAboutWantedJob()
{
    string answer;
    printMsg(Msg::ASPIRE_JOB_TYPE_MESSAGE, 1);
    string input;
    int intAnswer;
    while (1)
    {
        getline(cin, input);
        try
        {
            intAnswer = stoi(input);
        }
        catch (exception &err)
        {
            printMsg(Msg::INPUT_NUMBER_BETWEEN_1_3_MESSAGE, 1);
            moodState--;
            continue;
        }

        if (intAnswer > 3 || intAnswer < 1)
        {
            printMsg(Msg::INPUT_NUMBER_BETWEEN_1_3_MESSAGE, 1);
            continue;
        }
        break;
    }
    if (intAnswer == 1)
    {
        printMsg(Msg::ASPIRE_IT_SPHERE_MESSAGE, 1);
    }
    else if (intAnswer == 2)
    {
        printMsg(Msg::ASPIRE_SERVICE_SPHERE_MESSAGE, 1);
    }
    else if (intAnswer == 3)
    {
        printMsg(Msg::ASPIRE_MANUAL_SPHERE_MESSAGE, 1);
    }
}

void talkAboutMusic()
{
    string answer;
    printMsg(Msg::MUSIC_RESPONSE_MESSAGE, 1);
    getline(cin, answer);

    printMsg(Msg::NICE_GROUP_MESSAGE, 1);

    printMsg(Msg::FAVOURITE_MOVIE_MESSAGE, 0);
    getline(cin, answer);

    printMsg(Msg::NICE_MOVIE_MESSAGE, 1);
}

void talkAboutMovies()
{
    string answer;
    printMsg(Msg::ASK_MOVIES_MESSAGE, 1);
    getline(cin, answer);
    if (checkForYes(answer))
    {
        printMsg(Msg::MOVIE_RESPONSE_MESSAGE, 1);
        getline(cin, answer);

        printMsg(Msg::NICE_MOVIE_MESSAGE, 1);
    }
    else
    {
        printMsg(Msg::DISLIKE_MOVIES_AND_MUSIC_MESSAGE, 1);
    }
}

void askDifficulty()
{
    if (moodState < 5)
    {
        printMsg(Msg::ASK_MATH_DIFFICULTY_BAD_MOOD_MESSAGE, 1);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        printMsg(Msg::ASK_MATH_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1);
    }
    else
    {
        printMsg(Msg::ASK_MATH_DIFFICULTY_GOOD_MOOD_MESSAGE, 1);
    }
}

void printEasyDifficultyMessages()
{
    if (moodState < 5)
    {
        printMsg(Msg::EASY_DIFFICULTY_BAD_MOOD_MESSAGE, 1);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        printMsg(Msg::EASY_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1);
    }
    else
    {
        printMsg(Msg::EASY_DIFFICULTY_GOOD_MOOD_MESSAGE, 1);
    }
}

void printNormalDifficultyMessages()
{
    if (moodState < 5)
    {
        printMsg(Msg::NORMAL_DIFFICULTY_BAD_MOOD_MESSAGE, 1);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        printMsg(Msg::NORMAL_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1);
    }
    else
    {
        printMsg(Msg::NORMAL_DIFFICULTY_GOOD_MOOD_MESSAGE, 1);
    }
}
void printHardDifficultyMessages()
{
    if (moodState < 5)
    {
        printMsg(Msg::HARD_DIFFICULTY_BAD_MOOD_MESSAGE, 1);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        printMsg(Msg::HARD_DIFFICULTY_NORMAL_MOOD_MESSAGE, 1);
    }
    else
    {
        printMsg(Msg::HARD_DIFFICULTY_GOOD_MOOD_MESSAGE, 1);
    }
}

void printFirstProblemMessages()
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
void printLastProblemMessages()
{
    if (moodState < 5)
    {
        cout << Msg::LAST_PROBLEM_BAD_MOOD_MESSAGE;
        sleep(2);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        cout << Msg::LAST_PROBLEM_NORMAL_MOOD_MESSAGE;
        sleep(2);
    }
    else
    {
        cout << Msg::LAST_PROBLEM_GOOD_MOOD_MESSAGE;
        sleep(2);
    }
}
void printContinueProblemMessages(int problemCounter)
{
    if (moodState < 5)
    {
        cout << Msg::CONTINUE_PROBLEM_BAD_MOOD_MESSAGE;
        cout << problemCounter << ".\n";
        sleep(2);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        cout << Msg::CONTINUE_PROBLEM_NORMAL_MOOD_MESSAGE;
        cout << problemCounter << ".\n";
        sleep(2);
    }
    else
    {
        cout << Msg::CONTINUE_PROBLEM_GOOD_MOOD_MESSAGE;
        cout << problemCounter << ".\n";
        sleep(2);
    }
}

void printByeMessagesAndCheckForBye()
{
    if (moodState < 5)
    {
        printMsg(Msg::INPUT_BYE_BAD_MOOD_MESSAGE, 0);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        printMsg(Msg::INPUT_BYE_NORMAL_MOOD_MESSAGE, 0);
    }
    else
    {
        printMsg(Msg::INPUT_BYE_GOOD_MOOD_MESSAGE, 0);
    }
    string stringAnswer;
    getline(cin, stringAnswer);
    if (checkForBye(stringAnswer))
    {
        int randomNum = rand() % farewellPhrases.size();
        cout << farewellPhrases[randomNum] + "\n";
        exit(0);
    }
}

void printProblem(string problem)
{

    if (moodState < 5)
    {
        printMsg(Msg::MATH_PROBLEM_BAD_MOOD_MESSAGE, 1);
        cout << problem << "\n";
    }
    else if (moodState >= 5 && moodState < 15)
    {
        printMsg(Msg::MATH_PROBLEM_NORMAL_MOOD_MESSAGE, 1);
        cout << problem << "\n";
    }
    else
    {
        printMsg(Msg::MATH_PROBLEM_GOOD_MOOD_MESSAGE, 1);
        cout << problem << "\n";
    }
}

int checkProblemInput()
{
    string input;
    int intAnswer;
    while (1)
    {
        int intAnswer;
        getline(cin, input);

        if (checkForBye(input))
        {
            int randomNum = rand() % farewellPhrases.size();
            cout << farewellPhrases[randomNum] + "\n";
            exit(0);
        }
        try
        {
            intAnswer = stoi(input);
        }
        catch (exception &err)
        {
            printMsg(Msg::BUG_MESSAGE);
            moodState--;
            continue;
        }
        break;
    }
    return stoi(input);
}

void printCorrectMessage()
{
    if (moodState < 5)
    {
        printMsg(Msg::CORRECT_BAD_MOOD_MESSAGE, 1);
        sleep(2);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        printMsg(Msg::CORRECT_NORMAL_MOOD_MESSAGE, 1);
        sleep(2);
    }
    else
    {
        printMsg(Msg::CORRECT_GOOD_MOOD_MESSAGE, 1);
        sleep(2);
    }
    moodState++;
}

void printIncorrectMessage()
{
    if (moodState < 5)
    {
        cout << endl;
        printMsg(Msg::INCORRECT_BAD_MOOD_MESSAGE, 0);
    }
    else if (moodState >= 5 && moodState < 15)
    {
        cout << endl;
        printMsg(Msg::INCORRECT_NORMAL_MOOD_MESSAGE, 0);
    }
    else
    {
        cout << endl;
        printMsg(Msg::INCORRECT_GOOD_MOOD_MESSAGE, 0);
    }
}

void clearScreen()
{
    system(CLEAR_COMMAND.c_str());
}