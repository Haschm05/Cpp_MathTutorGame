/*
Program: Math Tutor Version 6
Programmers: Hayden Schmidt
Date: 12/3/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV6
Description: A simple math tutor for elementary students. Allows user to save and load game.
*/

#include <iostream> // required for couts & cins
#include <cstdlib> // allows for randomizer
#include <ctime> // enables use of time function
#include <string> // allows for strings to be used
#include <cctype>
#include <iomanip>
#include <vector>
#include <fstream>
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

    //Same but matters for some things, troublshoot later
    userName = IntroGetName();

    //bool LoadGame(const string &filename, vector<int> &gameState, vector<vector<int>> &questions);


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
        cout << userName + " Do you want to continue? (y = yes | n = no): ";
        userYN = YNQuestion();
    }
    cin.clear();

    //Prints summary of questions
    PrintSummary(questions, userName);

    //try catch
    try {
        //GAME_SAVE(userName, questions);
    }
    catch (runtime_error &e) {
        //prints error message
        cout << e.what() << endl;
        cout << "Unable to save game." << endl;
    }

    //void SaveGame(const string &filename, const vector<int> &gameState, const vector<vector<int>> &questions);

    return 0;
}
