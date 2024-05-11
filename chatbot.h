// Made by Domantas Petkevicius, student of Vilniaus Universitetas, Matematikos ir Informatikos fakultetas (MIF), domasp902@gmail.com

#ifndef CHATBOT_H
#define CHATBOT_H

#include <iostream>
#include <time.h>
#include <vector>
#include <map>
#include <unistd.h>
#include <limits>

#include "inputvalidator.h"
#include "keywordchecker.h"
#include "messageprinter.h"
#include "customexceptions.h"
#include "exceptionhandler.h"
#include "messages.h"

using namespace std;

vector<string> introductionPhrases =
    {"Hey!", "Hello!", "Yo!",
     "What's up?", "Hey, how are you doing?",
     "Hi, hope you are doing well!"};

vector<string> farewellPhrases =
    {"Bye!", "Goodbye!", "Hope to see you soon!",
     "Was nice talking to you!", "Farewell!",
     "Bye bye!"};

// Implements functions that are responsible for creating a conversation depending on chosen scenarios.
// Tracks mood, saves user's name.
class ChatBot
{
    string name = "";
    int moodState = 10;
    bool isFirstConversation = 1;
    KeywordChecker keywordChecker = {};
    MessagePrinter messagePrinter = {};
    InputValidator inputValidator = {};
    ExceptionHandler exceptionHandler = {};

public:
    void start()
    {
        introduceAndGetName();
        decideTopic();
    }

    void introduceAndGetName()
    {
        srand((unsigned)time(NULL));
        string answer;
        int randomNum = rand() % introductionPhrases.size();
        cout << introductionPhrases[randomNum] + "\n";

        answer = getValidInput();

        cout << Msg::INTRODUCTION_MESSAGE;
        name = getValidInput();

        messagePrinter.printMsg(Msg::END_CONVERSATION_MESSAGE, 1, name);
        answer = getValidInput();

        if (keywordChecker.checkForBye(answer))
        {
            sayBye();
        }
    }

    // decides whether conversation will be about life or maths, depending on user's response
    void decideTopic()
    {
        string answer;
        messagePrinter.printMsg(Msg::ASK_MATH_OR_LIFE_MESSAGE, 1, name);
        answer = getValidInput();
        if (keywordChecker.checkForBye(answer))
        {
            sayBye();
        }
        if (keywordChecker.checkForLife(answer))
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
            int randomNum = rand() % 3;
            if (isFirstConversation)
            {
                messagePrinter.printMsg(Msg::INTRODUCE_LIFE_CHATBOT_MESSAGE, 1, name);
                sleep(4);
                isFirstConversation = 0;
            }
            if (randomNum == 0)
            {
                talkAboutStudies();
            }
            else if (randomNum == 1)
            {
                talkAboutJobSphere();
            }
            else if (randomNum == 2)
            {
                talkAboutArtSphere();
            }

            string answer;
            cout << Msg::CONTINUE_OR_MATH_MESSAGE;
            answer = getValidInput();
            if (keywordChecker.checkForMath(answer))
            {
                talkAboutMaths();
                break;
            }
            else if (keywordChecker.checkForNo(answer))
            {
                sayBye();
                break;
            }
        }
    }

    void talkAboutMaths()
    {
        if (isFirstConversation)
        {
            messagePrinter.printMsg(Msg::INTRODUCE_MATH_CHATBOT_MESSAGE, 1, name);
            sleep(4);
            isFirstConversation = 0;
        }

        int solveCounter = 0;
        while (1)
        {
            messagePrinter.printMathDifficultyMessages(solveCounter, name, moodState);
            int diff = decideDifficulty();
            if (diff == 4)
            {
                talkAboutLife();
                break;
            }

            map<string, int> chosenProblems;
            chosenProblems = messagePrinter.printDifficultyMessages(diff, moodState, name);
            int correctAnswers = 0;
            int problemCounter = 1;

            // gives user a math problem and checks user's answers until problem counter reaches 5.
            while (problemCounter <= 5)
            {
                messagePrinter.printProblemMessages(problemCounter, moodState);
                if (problemCounter == 1)
                {
                    printByeMessagesAndCheckForBye();
                }

                int isCorrect = outputProblem(chosenProblems);

                if (isCorrect)
                {
                    correctAnswers++;
                }

                problemCounter++;
            }
            solveCounter++;
            cout << "Your score : " << correctAnswers << " out of 5!\n";
            sleep(3);
        }
    }
    // outputs a math problem and checks if the answer is correct.
    int outputProblem(map<string, int> chosenProblems)
    {
        int randomNum = rand() % chosenProblems.size();
        int counter = 0;
        int problemAnswer;
        bool isCorrect = 1;
        for (auto &t : chosenProblems)
        {
            if (counter == randomNum)
            {
                problemAnswer = t.second;
                while (1)
                {
                    int intAnswer = checkProblemInput(t.first);
                    cout << intAnswer;
                    if (intAnswer == problemAnswer)
                    {
                        messagePrinter.printCorrectMessage(moodState, name);
                        break;
                    }
                    else
                    {
                        messagePrinter.printIncorrectMessage(moodState, name);
                        cout << problemAnswer << endl;
                        moodState--;
                        isCorrect = 0;
                        break;
                    }
                }
            }
            counter++;
        }
        return isCorrect;
    }

    void talkAboutStudies()
    {
        string answer;
        messagePrinter.printMsg(Msg::ASK_STUDENT_MESSAGE, 1, name);
        answer = getValidInput();
        if (keywordChecker.checkForYes(answer))
        {
            messagePrinter.printMsg(Msg::STUDENT_RESPONSE_MESSAGE, 1, name);
            answer = getValidInput();

            messagePrinter.printMsg(Msg::STUDY_PLACE_RESPONSE_MESSAGE, 1, name);
            answer = getValidInput();
            if (keywordChecker.checkForYes(answer))
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
            messagePrinter.printMsg(Msg::WHY_NOT_STUDENT_MESSAGE, 1, name);
            answer = getValidInput();
            messagePrinter.printMsg(Msg::STUDIES_IMPORTANT_MESAGE, 1, name);
        }
    }

    // prints scenarios if user answered that he likes studies.
    void talkAboutStudiesIfLikes()
    {
        string answer;
        messagePrinter.printMsg(Msg::STUDY_LIKE_MESSAGE, 1, name);
        answer = getValidInput();

        int subj = keywordChecker.checkForSubject(answer);
        messagePrinter.printMessagesAboutStudiesIfLikes(subj, name);

        messagePrinter.printMsg(Msg::STUDIES_FINISHED_MESSAGE, 0, name);
        answer = getValidInput();
        messagePrinter.printMsg(Msg::STUDIES_FINISH_MESSAGE, 1, name);
    }

    // prints scenarios if user answered that he dislikes studies.
    void talkAboutStudiesIfDislikes()
    {
        string answer;
        messagePrinter.printMsg(Msg::STUDY_DISLIKE_MESSAGE, 1, name);
        answer = getValidInput();
        int disl = keywordChecker.checkForDislikedThing(answer);

        messagePrinter.printMessagesAboutStudiesIfDislikes(disl, name);

        messagePrinter.printMsg(Msg::STUDIES_FINISHED_MESSAGE, 0, name);
        answer = getValidInput();
        messagePrinter.printMsg(Msg::STUDIES_FINISH_MESSAGE, 1, name);
    }
    void talkAboutJobSphere()
    {
        string answer;
        messagePrinter.printMsg(Msg::ASK_JOB_MESSAGE, 1, name);

        answer = getValidInput();
        if (keywordChecker.checkForYes(answer))
        {
            talkAboutJob();
        }
        else
        {
            talkAboutWantedJob();
        }
    }
    // talks about job sphere if user works somewhere
    void talkAboutJob()
    {
        messagePrinter.printMsg(Msg::JOB_TYPE_MESSAGE, 1, name);
        int intAnswer;
        while (1)
        {
            intAnswer = getValidNumber();
            try
            {
                inputValidator.validateRange(intAnswer, 1, 3);
            }
            catch (exception &err)
            {
                moodState--;
                exceptionHandler.handleException(err);
                sleep(1);
                messagePrinter.printMsg(Msg::INPUT_NUMBER_BETWEEN_1_3_MESSAGE, 1, name);
                continue;
            }
            break;
        }

        messagePrinter.printJobSphereMessages(intAnswer, name);
    }

    // talks about job sphere if user does not work
    void talkAboutWantedJob()
    {
        messagePrinter.printMsg(Msg::ASPIRE_JOB_TYPE_MESSAGE, 1, name);
        int intAnswer;
        while (1)
        {
            intAnswer = getValidNumber();
            try
            {
                inputValidator.validateRange(intAnswer, 1, 3);
            }
            catch (exception &err)
            {
                moodState--;
                exceptionHandler.handleException(err);
                sleep(1);
                messagePrinter.printMsg(Msg::INPUT_NUMBER_BETWEEN_1_3_MESSAGE, 1, name);
                continue;
            }
            break;
        }

        messagePrinter.printWantedJobSphereMessages(intAnswer, name);
    }

    void talkAboutArtSphere()
    {
        string answer;
        messagePrinter.printMsg(Msg::ASK_MUSIC_MESSAGE, 1, name);
        answer = getValidInput();
        if (keywordChecker.checkForYes(answer))
        {
            talkAboutMusic();
        }
        else
        {
            talkAboutMovies();
        }
    }

    void talkAboutMusic()
    {
        string answer;
        messagePrinter.printMsg(Msg::MUSIC_RESPONSE_MESSAGE, 1, name);
        answer = getValidInput();

        messagePrinter.printMsg(Msg::NICE_GROUP_MESSAGE, 1, name);

        messagePrinter.printMsg(Msg::FAVOURITE_MOVIE_MESSAGE, 0, name);
        answer = getValidInput();

        messagePrinter.printMsg(Msg::NICE_MOVIE_MESSAGE, 1, name);
    }

    void talkAboutMovies()
    {
        string answer;
        messagePrinter.printMsg(Msg::ASK_MOVIES_MESSAGE, 1, name);
        answer = getValidInput();
        if (keywordChecker.checkForYes(answer))
        {
            messagePrinter.printMsg(Msg::MOVIE_RESPONSE_MESSAGE, 1, name);
            answer = getValidInput();
            messagePrinter.printMsg(Msg::NICE_MOVIE_MESSAGE, 1, name);
        }
        else
        {
            messagePrinter.printMsg(Msg::DISLIKE_MOVIES_AND_MUSIC_MESSAGE, 1, name);
        }
    }

    void printByeMessagesAndCheckForBye()
    {
        messagePrinter.printByeMessages(moodState, name);
        string answer;
        answer = getValidInput();
        if (keywordChecker.checkForBye(answer))
        {
            sayBye();
        }
    }

    int checkProblemInput(string problem)
    {
        messagePrinter.printProblem(problem, moodState, name);

        int intAnswer = getValidNumber();

        return intAnswer;
    }

    // function that returns user's chosen difficulty for math problems after validation.
    int decideDifficulty()
    {
        string answer;
        int counter = 0;
        while (1)
        {
            answer = getValidInput();
            if (keywordChecker.checkForBye(answer))
            {
                sayBye();
            }
            if (keywordChecker.checkForLife(answer))
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
                    messagePrinter.printMsg(Msg::NAME_DIFFICULTY_MESSAGE, 1, name);
                    moodState--;
                    continue;
                }
                messagePrinter.printMsg(Msg::SPECIFY_DIFFICULTY_MESSAGE, 1, name);
                moodState--;
                counter++;
            }
        }
    }

    void sayBye()
    {
        int randomNum = rand() % farewellPhrases.size();
        cout << farewellPhrases[randomNum] + "\n";
        exit(0);
    }
    string getValidInput()
    {
        string answer;
        while (1)
        {
            try
            {
                answer = inputValidator.getAndValidateInputNotEmpty();
            }
            catch (exception &err)
            {
                exceptionHandler.handleException(err);
                continue;
            }
            break;
        }
        return answer;
    }

    int getValidNumber()
    {
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
                moodState--;
                exceptionHandler.handleException(err);
                continue;
            }

            break;
        }

        return intAnswer;
    }
};

#endif