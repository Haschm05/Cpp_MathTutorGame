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
#include <cctype>
#include <iomanip>
#include <vector>

#include "math_tutor.h" // includes header file

using namespace std; // sets standard namespace

int main() {

    //sets totals to 0
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int attempt = 0;
    int tempVal1 = 0;
    int tempVal2 = 0;
    string userYN = "y";

    //vector
    vector<vector<int>> questions;

    //sets time to random
    srand(time(0)); // Generates a unique seed so its random.

    //Intro parts, can be removed for testing
    //IntroArt();
    //IntroPun();

    //Same but matters for some things, troublshoot later
    string userName = IntroGetName();

    while (userYN == "y" || userYN == "yes") {
        //Loop goes until userYN no longer equals "yes")
        //Beginning of central loop that repeats number generation and math problems

        //levels up or down based on answers
        LevelUpOrDown(attempt, mathLevel);

        //Generates a random question
        vector<int> row = GenerateQuestion(mathLevel);

        //for leveling
        tempVal1 = totalCorrect;
        tempVal2 = totalIncorrect;

        //asks user the question
        AskUser(row, userName) ? totalCorrect++ : totalIncorrect++;

        //also for leveling
        if (totalCorrect > tempVal1) {
            attempt++;
        } else if (totalIncorrect > tempVal2) {
            attempt--;
        }

        // Modify the original questions vector by adding the row
        questions.push_back(row); // Push the last vector<int> in row to questions

        //continues the while loop
        userYN = AskContinue();
    }
    cin.clear();
    //Prints summary of questions
    PrintSummary(questions, userName);

    return 0;
}