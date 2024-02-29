#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <string>
using namespace std;

int checkForBye(string answer);
int checkForLife(string answer);
int checkForYes(string answer);
int checkForDislikedThing(string answer);
int checkForSubject(string answer);
int checkForNo(string answer);
int checkForMath(string answer);
void talkAboutLife();
void talkAboutMaths();
int checkForDifficulty();

int moodState = 10;
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
bool isFirstConversation = 1;

int main()
// My main objective was to make a fun math problem-solving chatbot, that reacts to the user's answers and changes program answers(mood) depending on them
// Also I added a functionality to have a short conversation about other topics
{
    srand((unsigned)time(NULL));

    string answer;
    int randomNum = rand() % introductionPhrases.size();
    cout << introductionPhrases[randomNum] + "\n";
    getline(cin, answer);

    cout << "This is a chatbot for a short conversation or to"
         << " solve some math problems! May I know your name? :)\n";
    getline(cin, name);

    cout << "Okay, " + name + ", if you want to end the "
         << "conversation anytime just say bye :)\n";
    getline(cin, answer);

    if (checkForBye(answer))
    {
        int randomNum = rand() % farewellPhrases.size();
        cout << farewellPhrases[randomNum] + "\n";
        return 0;
    }

    cout << "Do you want to solve some math problems?\n"
         << "If not, just say that you want to talk about life"
            " and we can talk about other things :)\n";
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
            cout << "Firstly, I will present myself."
                 << "I am chatBot v1! Nice to meet you, " << name << "\n";
        }
        isFirstConversation = 0;
        if (randomNum == 0)
        {
            cout << "May I know are you a student?\n";
            getline(cin, answer);
            if (checkForYes(answer))
            {
                cout << "Wow that is so nice! Where do you study?\n";
                getline(cin, answer);

                cout << "Okay, that is a nice place to study in for sure."
                     << " Do you like your studies so far?\n";
                getline(cin, answer);
                if (checkForYes(answer))
                {
                    cout << "I am happy to hear that! "
                         << "What subject did you like the most so far?\n";
                    getline(cin, answer);

                    int subj = checkForSubject(answer);
                    if (subj == 0)
                    {
                        cout << "I have not heard of this subject,"
                             << " but I hope that next semester will be better!\n";
                    }
                    else if (subj == 1)
                    {
                        cout << "I love maths too! Glad you liked it!\n";
                    }
                    else if (subj == 2)
                    {
                        cout << "I guess IT was an introductory subject for you,"
                             << " glad you liked it!\n";
                    }
                    else if (subj == 3)
                    {
                        cout << "Biology is fun, but it takes much time to learn everything!"
                             << " Glad you liked it!\n";
                    }
                    else if (subj == 4)
                    {
                        cout << "I love economics too! Glad you liked it!\n";
                    }
                    else if (subj == 5)
                    {
                        cout << "Wow, operating systems is an advanced subject."
                             << " Glad you liked it!\n";
                    }
                    else if (subj == 6)
                    {
                        cout << "Data structures are awesome!\n";
                    }
                }
                else
                {
                    cout << "Hmm, I am not happy to hear that. "
                         << "What do you dislike the most?\n";
                    getline(cin, answer);
                    int disl = checkForDislikedThing(answer);

                    if (disl == 0)
                    {
                        cout << "I am sad to hear it, "
                             << " let's hope the next semester will be better :)\n";
                    }
                    else if (disl == 1)
                    {
                        cout << "I understand that the lecturers might be strict,"
                             << " but that is they way you learn sometimes! Be strong:)\n";
                    }
                    else if (disl == 2)
                    {
                        cout << "Timetables can be really bad,"
                             << " but I suggest organizing your time more efficiently!\n";
                    }
                    else if (disl == 3)
                    {
                        cout << "Nothing is easy in this life,"
                             << " you need to go through hard times to become stronger!\n";
                    }
                    else if (disl == 4)
                    {
                        cout << "Grading systems are different depending on the lecturer,"
                             << " so I understand that it is sometimes hard to understand them correctly..\n";
                    }
                }

                cout << "Okay, anyways, how many years "
                     << "till your studies are finished, " << name << " ?\n";
                getline(cin, answer);
                cout << "That may seem like a long way to go,"
                     << " but time flies fast, so use it productively!\n";
            }
            else
            {
                cout << "Oh, why have you chose not to study?\n";
                getline(cin, answer);
                cout << "In my opinion studies are really important!"
                     << " Do not forget that you can become a student anyways!\n";
            }
        }
        else if (randomNum == 1)
        {
            cout << "May I know do you have a job?\n";

            getline(cin, answer);
            if (checkForYes(answer))
            {
                cout << "Perfect. If it is not a secret may I"
                     << " know what do you do for work? ( Input a number 1-3 )"
                     << "  \n1.IT sphere\n2.Service sphere\n3.Manual labour\n";
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
                        cout << "Please input a number between 1 and 3.";
                        moodState--;
                        continue;
                    }

                    if (intAnswer > 3 || intAnswer < 1)
                    {
                        cout << "Please input a number between 1 and 3.";
                        continue;
                    }

                    break;
                }
                if (intAnswer == 1)
                {
                    cout << "It is nice to hear that you work in an IT sphere already!\n";
                }
                else if (intAnswer == 2)
                {
                    cout << "Service sphere is a good way to start your career!\n";
                }
                else if (intAnswer == 3)
                {
                    cout << "Wow, you do not shy from dirty work, I respect that!\n";
                }
            }
            else
            {
                cout << "Okay, I understand you. What job would you"
                     << "like to have in the future then? ( Input a number 1-3 )"
                     << " \n1.IT sphere\n2.Service sphere\n3.Manual labour\n";
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
                        cout << "Please input a number.";
                        moodState--;
                        continue;
                    }

                    if (intAnswer > 3 || intAnswer < 1)
                    {
                        cout << "Please input a number between 1 and 3.";
                        continue;
                    }
                    break;
                }
                if (intAnswer == 1)
                {
                    cout << "It is nice to hear that you aspire to work in IT sphere!\n";
                }
                else if (intAnswer == 2)
                {
                    cout << "Service sphere is a good way to start your career! Good luck!\n";
                }
                else if (intAnswer == 3)
                {
                    cout << "Wow, you do not shy from dirty work, I respect that!\n";
                }
            }
        }
        else if (randomNum == 2)
        {
            cout << "Do you like music?\n";
            getline(cin, answer);
            if (checkForYes(answer))
            {
                cout << "I love music as well!"
                     << " My favourite group is The Beatles, what's yours?\n";
                getline(cin, answer);

                cout << answer << " is a really nice group,"
                     << " I will surely listen to some of their songs after!\n";

                cout << "And what is your favourite movie?\n";
                getline(cin, answer);

                cout << answer << " is a really nice movie,"
                     << " I have watched it multiple times!\n";
            }
            else
            {
                cout << "Wow you do not like music?"
                     << "Interesting... Do you like movies then ?\n";
                getline(cin, answer);
                if (checkForYes(answer))
                {
                    cout << "Okay, at least you like movies!\n"
                         << " What is your favourite movie?\n";
                    getline(cin, answer);

                    cout << answer << " is a really nice movie,"
                         << " I have watched it multiple times!\n";
                }
                else
                {
                    cout << "You must be lying, "
                         << "how can one dislike music and movies.. Strange.\n";
                }
            }
        }

        cout << "It was nice talking to you, " << name << "!\nShall we continue our conversation?"
             << " If you do not want to, just say that "
             << "you want to solve some math problems to take on a challenge!\n";
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
    int solveCounter = 0;
    while (1)
    {
        string answer;
        if (solveCounter == 0)
        {
            cout << "Okay, perfect. "
                 << "Now tell me do you want to solve easy,"
                 << " normal or hard math problems or say"
                 << " that you want to talk about life to switch the topic :)\n";
        }
        else if (solveCounter > 10)
        {
            cout << "Aren't you getting tired already?"
                 << " You have done so many. You know,"
                 << " I need some rest as well:( But yeah"
                 << " you know the drill, just input a"
                 << " difficulty if you'd like to proceed...\n";
            cout << "If not just say that you want to talk about"
                 << " life and we can talk about other things.\n";
        }

        else
        {
            if (moodState < 5)
            {
                cout << "Yeah yeah, good job."
                     << " Wanna solve some more? If yes, just tell"
                     << " me the difficulty or just say bye\n";
                cout << "If not just say  that you"
                     << " want to talk about life and we can talk"
                     << " about other things.\n";
            }
            else if (moodState >= 5 && moodState < 15)
            {
                cout << "Great job. You ready to do some more?"
                     << " If yes, tell me do you want to solve easy, "
                     << " normal or hard math problems?\n";
                cout << "If not just say that you"
                     << " want to talk about life and we can"
                     << " talk about other things.\n";
            }
            else
            {
                cout << "Wow you have done it, " << name << "!!!"
                     << " Do you want to solve more problems?"
                     << " If yes, tell me do you want to solve"
                     << "easy, normal or hard math problems?\n";
                cout << "If not just say"
                     << " that you want to talk about life and"
                     << " we can talk about other things.\n";
            }
        }
        int diff = checkForDifficulty();
        map<string, int> chosenProblems;

        if (diff == 4)
        {
            talkAboutLife();
            break;
        }

        if (diff == 1)
        {
            chosenProblems = easyMathProblems;
            if (moodState < 5)
            {
                cout << "Easy difficulty? "
                     << "It might be too hard for you, " << name << "\n";
            }
            else if (moodState >= 5 && moodState < 15)
            {
                cout << "So you chose easy difficulty, " << name
                     << ", Let's practice!\n";
            }
            else
            {
                cout << "Nice! Easy difficulty is perfect " << name
                     << ", Let's goo!\n";
            }
        }
        else if (diff == 2)
        {
            if (moodState < 5)
            {
                cout << "Trust me, better choose easy difficulty"
                     << "\n";
            }
            else if (moodState >= 5 && moodState < 15)
            {
                cout << "So you chose normal difficulty, " << name
                     << ". Fair enough.\n";
            }
            else
            {
                cout << "Normal? Perfect " << name
                     << ", let's start asap.\n";
            }
            chosenProblems = normalMathProblems;
        }
        else if (diff == 3)
        {
            if (moodState < 5)
            {
                cout << "No way you are solving these," << name
                     << "...\n";
            }
            else if (moodState >= 5 && moodState < 15)
            {
                cout << "So you chose hard difficulty," << name
                     << ", Wow !\n";
            }
            else
            {
                cout << "This won't be easy, but I believe in you,"
                     << name << ", !\n";
            }
            chosenProblems = hardMathProblems;
        }

        int problemCounter = 1;
        while (problemCounter <= 5)
        {
            if (problemCounter == 1)
            {
                if (moodState < 5)
                {
                    cout << "First problem, you will need"
                         << " some luck if you want to solve it " << problemCounter << "\n";
                }
                else if (moodState >= 5 && moodState < 15)
                {
                    cout << "Let's start with a problem number 1 "
                         << "\n";
                }
                else
                {
                    cout << "Starting with problem number 1, good luck!!!"
                         << "\n";
                }
            }
            else
            {
                if (problemCounter == 5)
                {
                    solveCounter++;
                    if (moodState < 5)
                    {
                        cout << "Can't even fathom how"
                             << " you have gone this far, but yeah, good job I guess? Last problem.\n";
                    }
                    else if (moodState >= 5 && moodState < 15)
                    {
                        cout << "Last problem and you will"
                             << " be done with this difficulty!\n";
                    }
                    else
                    {
                        cout << "Wow, you are so smart!!!"
                             << "I have always believed in you, " << name
                             << ", last problem and you will"
                             << " be done with this difficulty!\n";
                    }
                }
                else
                {
                    if (moodState < 5)
                    {
                        cout << "You are not really doing good,"
                             << " but anyways. Let's continue with problem"
                             << " number " << problemCounter << "\n";
                    }
                    else if (moodState >= 5 && moodState < 15)
                    {
                        cout << "Okay, " << name << ", let's"
                             << " continue with problem number " << problemCounter << ".\n";
                    }
                    else
                    {
                        cout << "You are doing great!!!"
                             << " Let's move on to problem number " << problemCounter << "\n";
                    }
                }
            }

            if (problemCounter == 1)
            {
                if (moodState < 5)
                {
                    cout << "A tip : Enter the word bye"
                         << " and see what happens\n";
                }
                else if (moodState >= 5 && moodState < 15)
                {
                    cout << "If you do not want"
                         << " to solve anymore just say bye.\n";
                }
                else
                {
                    cout << "I believe in you, but "
                         << "if you are tired just say bye to exit :))\n";
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
            int randomNum = rand() % chosenProblems.size();
            int counter = 0;
            string input;
            int problemAnswer;
            for (auto &t : chosenProblems)
            {
                if (counter == randomNum)
                {
                    problemAnswer = t.second;
                    if (moodState < 5)
                    {
                        cout << "A hard one for you. What is "
                             << t.first << "\n";
                    }
                    else if (moodState >= 5 && moodState < 15)
                    {
                        cout << "What is " << t.first
                             << " input a number \n";
                    }
                    else
                    {
                        cout << "Easy one just for you:) What is "
                             << t.first << "\n";
                    }
                }
                counter++;
            }
            while (1)
            {
                int intAnswer;
                while (1)
                {
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
                        cout << "You must input a number!"
                             << " Why are you trying to cause a bug?\n"
                             << "Now input an answer(number please):";
                        moodState--;
                        continue;
                    }
                    break;
                }

                if (intAnswer == problemAnswer)
                {
                    if (moodState < 5)
                    {
                        cout << "Not correct,"
                             << " but I will count it as correct"
                             << " so we can finish this faster. ( Actually correct )\n";
                    }
                    else if (moodState >= 5 && moodState < 15)
                    {
                        cout << "You are correct, " << name << ".\n";
                    }
                    else
                    {
                        cout << "You are correct! As always\n";
                    }
                    moodState++;
                    problemCounter++;
                    break;
                }
                else
                {
                    if (moodState < 5)
                    {
                        cout << "Haha! Nope.\n";
                    }
                    else if (moodState >= 5 && moodState < 15)
                    {
                        cout << "Wrong! Try again please.\n";
                    }
                    else
                    {
                        cout << "Almost! Another"
                             << " attempt and you will get it!\n";
                    }
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
    if (answer.find("yes") != string::npos ||
        answer.find("yeah") != string::npos ||
        answer.find("yep") != string::npos)
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
    else if (answer.find("econom") != string::npos)
    {
        return 4;
    }
    else if (answer.find("operating sys") != string::npos)
    {
        return 5;
    }
    else if (answer.find("data struc") != string::npos)
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
                cout << "Can you stop playing with me?"
                     << " Just name a difficulty please :/\n";
                moodState--;
                continue;
            }
            cout << "Please specify a difficulty...\n";
            moodState--;
            counter++;
        }
    }
}