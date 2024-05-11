// Made by Domantas Petkevicius, student of Vilniaus Universitetas, Matematikos ir Informatikos fakultetas (MIF), domasp902@gmail.com
// This program implements a fun math problem-solving chatbot, that reacts to the user's answers and changes program answers depending on them.
// Also there is an option to have a short conversation about other topics.

// V2 Changes (2024-03-03):
// Done some refactoring, improved layout, naming, UI, added functions, improved modularity, separated data from the logic.
// All messages are held as constants in messages.h
// Made the program foolproof, all errors are handled.
// Started using git for version control.

// V3 Changes (2024-03-23):
// Reworked all project to follow OOP principles and paradigm, added classes for specific functionality.
// Designed classes as modules and split them into .h and .cpp files.
// Some classes are specific to the project and have private state and some are designed for reuse.
// Added input validation so empty strings and new lines are not accepted.
// Reworked math bot logic, so if you answer incorrectly it does not ask you for the answer again.
// Now the bot tracks correct answers.
// Refactored many functions, made them shorter, so they follow SRP principle.
// Added documentation and comments.
// There are not many comments, because almost all function/variable names are self-explanatory.
// Added exception handling and created custom exception classes.

// Tested on Windows 11, 64 bits, C++ 14

#include <iostream>

#include "chatbot.h"

using namespace std;

int main()
{
    ChatBot chatbot = {};
    try
    {
        chatbot.start();
    }
    catch (exception &err)
    {
        cout << "Unknown exception encountered : " << err.what();
        return 1;
    }
    return 0;
}
