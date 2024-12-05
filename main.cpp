/*
Program: Math Tutor Version 6
Programmers: Hayden Schmidt
Date: 12/3/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV6
Description: A simple math tutor for elementary students. Allows user to save and load game.
Code has been broken into several functions for easier testing. Displays a summary of questions when done.
Levels the difficulty of questions based on how many questions the user gets right or wrong.
Generates random problems. Has a user interface.
*/

//Possible future Ideas: mutiple saves for different people based on userName
//more problem variation, sqrt etc.


#include <iostream> // required for couts & cins
#include <cstdlib> // allows for randomizer
#include <ctime> // enables use of time function
#include <string> // allows for strings to be used
#include <cctype>
#include <iomanip>
#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>

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
    string question = "y";
    string userName = "unknown";

    //vector
    vector<vector<int>> questions;

    //sets time to random
    srand(time(0)); // Generates a unique seed so its random.

    //Intro parts, can be removed for testing
    //IntroArt();
    //IntroPun();

    //gets username
    userName = IntroGetName();

    //Load game if user has a previous save
    //try catch for load
    try {
        mathLevel = LoadGame(userName, questions);
    }
    catch (runtime_error &e) {
        //prints error message
        cout << e.what() << endl;
        cout << "Unable to save game." << endl;
    }

    userYN = "y";

    while (userYN == "y" || userYN == "yes") {
        //Loop goes until userYN no longer equals "yes")
        //Beginning of central loop that repeats number generation and math problems

        // clears input(fixes issue with interaction between leveling and continue)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

        // clears input(fixes issue with interaction between continue and continue)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //continues the while loop
        cout << userName + " Do you want to continue? (y = yes | n = no): ";
        userYN = YNQuestion();
    }

    //Prints summary of questions
    PrintSummary(questions, userName);

    //Asks user is they want to save game and saves if yes and possible or exits if not
    //try catch for save
    try {
        SaveGame(userName,  questions);
    }
    catch (runtime_error &e) {
        //prints error message
        cout << e.what() << endl;
        cout << "Unable to save game." << endl;
    }

    return 0;
}
