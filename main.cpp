/*
Program: Math Tutor Version 3
Programmers: Hayden Schmidt
Date: 11/19/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV5
Description: A simple math tutor for elementary students. Converts code to functions for easier testing and modification.
*/

#include <iostream> // required for couts & cins
#include <cstdlib> // allows for randomizer
#include <ctime> // enables use of time function
#include <string> // allows for strings to be used
#include <limits> // required for numeric limits
#include <cctype>
#include <iomanip>
#include <vector>

#include "math_tutor.h" // includes header file

using namespace std; // sets standard namespace

// Define the global variables
vector<vector<int>> questions; // Define the vector
int totalCorrect = 0;  // Define totalCorrect
int totalIncorrect = 0;  // Define totalIncorrect
int correct = 0;  // Define correct
int incorrect = 0;  // Define incorrect

// Constants
const int MAX_ATTEMPTS = 3; // Sets how many attempts per question
const int LEVEL_RANGE_CHANGE = 10; // Sets how much the range changes per level

// Struct to store question data (ChatGPT helped with this one, was having trouble with name spaces)
struct Question {
    int mathLevel;
    int leftNum;
    char mathSymbol;
    int rightNum;
    int correctAnswer;
    int attemptCount;
};

int main() {
    // Declares and initializes variables
    int leftNum = 0;
    int rightNum = 0;
    int mathLevel = 1; // Starts user on level 1
    int currentRange = LEVEL_RANGE_CHANGE; // Sets starting range at 10

    string userYN = "?";
    string userName = "unknown";

    char mathSymbol = '?';

    srand(time(0)); // Generates a unique seed so its random.

    //Troubleshooting but it worked
    correct = 0;
    incorrect = 0;

    // Starting the main code
    IntroArt(); // outputs ASCII art
    IntroPun(); // outputs pun
    userName = IntroGetName(); // gets username

    do {
        // Ask the question
        AskQuestion(leftNum, rightNum, mathSymbol, mathLevel, userName, currentRange);

        //Level up or down after the question
        LevelUpOrDown(mathLevel, currentRange);

        // Ask if the user wants to continue
        userYN = AskContinue();

    } while (userYN == "y" || userYN == "yes"); // Loop goes until userYN no longer equals "yes"

    // Print the summary at the end
    PrintSummary();

    return 0;
}
