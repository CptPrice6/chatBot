#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>

namespace Messages
{

    extern const std::string INTRODUCTION_MESSAGE = "This is a chatbot for a short conversation or to solve some math problems! May I know your name? :)\n";
    extern const std::string END_CONVERSATION_MESSAGE = "if you want to end the conversation anytime just say bye :)\n";
    extern const std::string ASK_MATH_OR_LIFE_MESSAGE = "do you want to solve some math problems?\nIf not, just say that you want to talk about life and we can talk about other things :)\n";
    extern const std::string BYE_MESSAGE = "it was nice talking to you! Shall we continue our conversation? If you do not want to, just say that you want to solve some math problems to take on a challenge!\n";

    extern const std::string INTRODUCE_MATH_CHATBOT_MESSAGE = "firstly, I will present myself. I am Math chatBot v2! Nice to meet you.\n";
    extern const std::string INTRODUCE_LIFE_CHATBOT_MESSAGE = "firstly, I will present myself. I am Life chatBot v2! Nice to meet you.\n";
    extern const std::string ASK_STUDENT_MESSAGE = "may I know are you a student?\n";
    extern const std::string STUDENT_RESPONSE_MESSAGE = "wow that is so nice! Where do you study?\n";
    extern const std::string STUDY_PLACE_RESPONSE_MESSAGE = "okay, that is a nice place to study in for sure. Do you like your studies so far?\n";
    extern const std::string STUDY_LIKE_MESSAGE = "I am happy to hear that! What subject did you like the most so far?\n";
    extern const std::string UNKNOWN_SUBJECT_MESSAGE = "I have not heard of this subject, but I hope that next semester will be better!\n";
    extern const std::string STUDY_DISLIKE_MESSAGE = "hmm, I am not happy to hear that. What do you dislike the most?\n";
    extern const std::string STUDIES_FINISHED_MESSAGE = "how many years till your studies are finished?\n";
    extern const std::string STUDIES_FINISH_MESSAGE = "that may seem like a long way to go, but time flies fast, so use it productively!\n";
    extern const std::string STUDY_FINISH_YEARS_REPLY_MESSAGE = "okay, that is a nice place to study in for sure. Do you like your studies so far?\n";
    extern const std::string ASK_JOB_MESSAGE = "may I know do you have a job?\n";
    extern const std::string JOB_TYPE_MESSAGE = "perfect. If it is not a secret may I know what do you do for work? ( Input a number 1-3) \n1.IT sphere\n2.Service sphere\n3.Manual labour\n";
    extern const std::string ASPIRE_JOB_TYPE_MESSAGE = "okay, I understand you. What job would you like to have in the future then? ( Input a number 1-3) \n1.IT sphere\n2.Service sphere\n3.Manual labour\n";
    extern const std::string ASK_MUSIC_MESSAGE = "do you like music?\n";
    extern const std::string MUSIC_RESPONSE_MESSAGE = "I love music as well! My favourite group is The Beatles, what's yours?\n";
    extern const std::string ASK_MOVIES_MESSAGE = "wow you do not like music? Interesting... Do you like movies then?\n";
    extern const std::string MOVIE_RESPONSE_MESSAGE = "okay, at least you like movies! What is your favourite movie?\n";
    extern const std::string FAVOURITE_MOVIE_MESSAGE = "and what is your favourite movie?\n";
    extern const std::string CONTINUE_OR_MATH_MESSAGE = "It was nice talking to you! Shall we continue our conversation? If you do not want to, just say that you want to solve some math problems to take on a challenge!\n";

    extern const std::string MATH_SUBJECT_MESSAGE = "I love maths too! Glad you liked it!\n";
    extern const std::string IT_SUBJECT_MESSAGE = "I guess IT was an introductory subject for you, glad you liked it!\n";
    extern const std::string BIOLOGY_SUBJECT_MESSAGE = "Biology is fun, but it takes much time to learn everything! Glad you liked it!\n";
    extern const std::string ECONOMICS_SUBJECT_MESSAGE = "I love economics too! Glad you liked it!\n";
    extern const std::string OPERATING_SYSTEMS_SUBJECT_MESSAGE = "Wow, operating systems is an advanced subject. Glad you liked it!\n";
    extern const std::string DATA_STRUCTURES_SUBJECT_MESSAGE = "Data structures are awesome!\n";

    extern const std::string DEFAULT_DISLIKE_MESSAGE = "I am sad to hear it, let's hope the next semester will be better :)\n";
    extern const std::string LECTURERS_DISLIKE_MESSAGE = "I understand that the lecturers might be strict, but that is they way you learn sometimes! Be strong:)\n";
    extern const std::string TIMETABLES_DISLIKE_MESSAGE = "Timetables can be really bad, but I suggest organizing your time more efficiently!\n";
    extern const std::string HARD_DISLIKE_MESSAGE = "Nothing is easy in this life, you need to go through hard times to become stronger!\n";
    extern const std::string GRADING_DISLIKE_MESSAGE = "Grading systems are different depending on the lecturer,so I understand that it is sometimes hard to understand them correctly..\n";

    extern const std::string WHY_NOT_STUDENT_MESSAGE = "Oh, why have you chose not to study?\n";
    extern const std::string STUDIES_IMPORTANT_MESAGE = "in my opinion studies are really important! Do not forget that you can become a student anyways!\n";

    extern const std::string WORK_IT_SPHERE_MESSAGE = "It is nice to hear that you work in an IT sphere already!\n";
    extern const std::string WORK_SERVICE_SPHERE_MESSAGE = "Service sphere is a good way to start your career!\n";
    extern const std::string WORK_MANUAL_SPHERE_MESSAGE = "Wow, you do not shy from dirty work, I respect that!\n";

    extern const std::string ASPIRE_IT_SPHERE_MESSAGE = "It is nice to hear that you aspire to work in IT sphere!\n";
    extern const std::string ASPIRE_SERVICE_SPHERE_MESSAGE = "Service sphere is a good way to start your career! Good luck!\n";
    extern const std::string ASPIRE_MANUAL_SPHERE_MESSAGE = "Wow, you do not shy from dirty work, I respect that!\n";

    extern const std::string NICE_GROUP_MESSAGE = "it is a really nice group, I will surely listen to some of their songs after!\n";
    extern const std::string NICE_MOVIE_MESSAGE = "it is a really nice movie, I have watched it multiple times!\n";

    extern const std::string DISLIKE_MOVIES_AND_MUSIC_MESSAGE = "you must be lying, how can one dislike music and movies.. Strange.\n";

    extern const std::string INPUT_NUMBER_BETWEEN_1_3_MESSAGE = "Please input a number between 1 and 3.\n1.IT sphere\n2.Service sphere\n3.Manual labour\n";

    extern const std::string ASK_MATH_DIFFICULTY_FIRST_MESSAGE = "okay, perfect. Now tell me do you want to solve easy, normal or hard math problems or say that you want to talk about life to switch the topic :)\n";
    extern const std::string ASK_MATH_DIFFICULTY_REST_MESSAGE = "aren't you getting tired already? You have done so many. You know, I need some rest as well:( But yeah you know the drill, just input a difficulty if you'd like to proceed...\nIf not just say that you want to talk about life and we can talk about other things.\n";
    extern const std::string ASK_MATH_DIFFICULTY_BAD_MOOD_MESSAGE = "yeah yeah, good job. Wanna solve some more? If yes, just tell me the difficulty or just say bye\nIf not just say that you want to talk about life and we can talk about other things.\n";
    extern const std::string ASK_MATH_DIFFICULTY_NORMAL_MOOD_MESSAGE = "great job. You ready to do some more? If yes, tell me do you want to solve easy, normal or hard math problems?\nIf not just say that you want to talk about life and we can talk about other things.\n";
    extern const std::string ASK_MATH_DIFFICULTY_GOOD_MOOD_MESSAGE = "wow you have done it!!! Do you want to solve more problems? If yes, tell me do you want to solve easy, normal or hard math problems?\nIf not just say that you want to talk about life and we can talk about other things.\n";

    extern const std::string EASY_DIFFICULTY_BAD_MOOD_MESSAGE = "easy difficulty? It might be too hard for you,\n";
    extern const std::string EASY_DIFFICULTY_NORMAL_MOOD_MESSAGE = "so you chose easy difficulty. Let's practice!\n";
    extern const std::string EASY_DIFFICULTY_GOOD_MOOD_MESSAGE = "nice! Easy difficulty is perfect. Let's goo!\n";

    extern const std::string NORMAL_DIFFICULTY_BAD_MOOD_MESSAGE = "trust me, better choose easy difficulty\n";
    extern const std::string NORMAL_DIFFICULTY_NORMAL_MOOD_MESSAGE = "so you chose normal difficulty. Fair enough.\n";
    extern const std::string NORMAL_DIFFICULTY_GOOD_MOOD_MESSAGE = "normal? Perfect, let's start asap.\n";

    extern const std::string HARD_DIFFICULTY_BAD_MOOD_MESSAGE = "no way you are solving these,...\n";
    extern const std::string HARD_DIFFICULTY_NORMAL_MOOD_MESSAGE = "so you chose hard difficulty. Wow !\n";
    extern const std::string HARD_DIFFICULTY_GOOD_MOOD_MESSAGE = "this won't be easy, but I believe in you!\n";

    extern const std::string FIRST_PROBLEM_BAD_MOOD_MESSAGE = "First problem, you will need some luck if you want to solve it.\n";
    extern const std::string FIRST_PROBLEM_NORMAL_MOOD_MESSAGE = "Let's start with a problem number 1.\n";
    extern const std::string FIRST_PROBLEM_GOOD_MOOD_MESSAGE = "Starting with problem number 1, good luck!!!\n";

    extern const std::string INPUT_BYE_BAD_MOOD_MESSAGE = "a tip : Enter the word bye and see what happens\n";
    extern const std::string INPUT_BYE_NORMAL_MOOD_MESSAGE = "if you do not want to solve anymore just say bye.\n";
    extern const std::string INPUT_BYE_GOOD_MOOD_MESSAGE = "I believe in you, but if you are tired just say bye to exit :))\n";

    extern const std::string MATH_PROBLEM_BAD_MOOD_MESSAGE = "a hard one for you. What is ";
    extern const std::string MATH_PROBLEM_NORMAL_MOOD_MESSAGE = "what is ";
    extern const std::string MATH_PROBLEM_GOOD_MOOD_MESSAGE = "easy one just for you:) What is ";

    extern const std::string BUG_MESSAGE = "you must input a number! Why are you trying to cause a bug?\nNow input an answer(number please):";

    extern const std::string CORRECT_BAD_MOOD_MESSAGE = "not correct, but I will count it as correct so we can finish this faster. ( Actually correct )\n";
    extern const std::string CORRECT_NORMAL_MOOD_MESSAGE = "you are correct!\n";
    extern const std::string CORRECT_GOOD_MOOD_MESSAGE = "you are correct! As always\n";
    extern const std::string INCORRECT_BAD_MOOD_MESSAGE = "haha! Nope.\n";
    extern const std::string INCORRECT_NORMAL_MOOD_MESSAGE = "wrong! Try again please.\n";
    extern const std::string INCORRECT_GOOD_MOOD_MESSAGE = "almost! Another attempt and you will get it!\n";

    extern const std::string LAST_PROBLEM_BAD_MOOD_MESSAGE = "Can't even fathom how you have gone this far, but yeah, good job I guess? Last problem.\n";
    extern const std::string LAST_PROBLEM_NORMAL_MOOD_MESSAGE = "Last problem and you will be done with this difficulty!\n";
    extern const std::string LAST_PROBLEM_GOOD_MOOD_MESSAGE = "Wow, you are so smart!!! I have always believed in you. Last problem and you will be done with this difficulty!\n";

    extern const std::string CONTINUE_PROBLEM_BAD_MOOD_MESSAGE = "You are not really doing good but anyways. Let's continue with problem number ";
    extern const std::string CONTINUE_PROBLEM_NORMAL_MOOD_MESSAGE = "Let's continue with problem number ";
    extern const std::string CONTINUE_PROBLEM_GOOD_MOOD_MESSAGE = "You are doing great!!! Let's move on to problem number ";

    extern const std::string NAME_DIFFICULTY_MESSAGE = "Can you stop playing with me? Just name a difficulty please :/\n";
    extern const std::string SPECIFY_DIFFICULTY_MESSAGE = "Please specify a difficulty...\n";

}

#endif // MESSAGES_H