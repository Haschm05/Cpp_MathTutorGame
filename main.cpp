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

    //vector
    vector<vector<int>> questions;

    //for troubleshooting
    string userYN = "y";

    //sets time to random
    srand(time(0)); // Generates a unique seed so its random.

    //Intro parts, can be removed for testing
    //void IntroArt();
    //void IntroPun();

    //Same but matters for some things, troublshoot later
    //string IntroGetName();

    do { //Beginning of central loop that repeats number generation and math problems
        //Generates a random question
        vector<int> row = GenerateQuestion(mathLevel);

        //asks user the question
        AskUser(row) ? totalCorrect++ : totalIncorrect++;

        // Modify the original questions vector by adding the row
        questions.push_back(row);  // Push the last vector<int> in row to questions

        //continues the while loop
        //string AskContinue();
    }while (userYN == "y" || userYN == "yes"); //Loop goes until userYN no longer equals "yes"

    //Prints summary of questions
    //PrintSummary(questions);

    return 0;
}