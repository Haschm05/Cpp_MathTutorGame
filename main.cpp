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
#include <limits>
#include <vector>

#include "math_tutor.h" // includes header file

using namespace std; // sets standard namespace

int main() {

    string userYN = "y";

    srand(time(0)); // Generates a unique seed so its random.

    //void IntroArt();
    //void IntroPun();
    //string IntroGetName();


    do { //Beginning of central loop that repeats number generation and math problems
        void GenerateQuestion(vector<vector<int>> questions);
        void AskUser(vector<vector<int>> questions);
        //void LevelUpOrDown();
        //string AskContinue();
    }

    while (userYN == "y" || userYN == "yes"); //Loop goes until userYN no longer equals "yes"

    //void PrintSummary();


    return 0;

}