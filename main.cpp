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

//this is my hail mary
vector<Question> questions;  // Define the vector to hold all questions
GameState state;             // Define the global game state

int main() {

    // Generate a math question
    Question question;  // Create a new Question object

    //for testing
    //string userName = "unknown";

    // issue with leveling... again
    //some logic to set the level properly, hopefully
    question.mathLevel = 1;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Display the intro art and ask about math puns
    IntroArt();
    IntroPun();

    // Get the user's name
    string userName = IntroGetName();

    // Start the game loop
    bool continueGame = true;
    while (continueGame) {

        //generates the question to be asked
        GenerateQuestion(question, state);  // Pass the question and state to the function

        // Adjust the difficulty based on user performance
        LevelUpOrDown(state);

        // Ask the user the math question and save the results
        AskUser(question, state, userName, questions);  // Pass the question, state, userName, and question vector

        // Ask if the user wants to continue
        string userYN = AskContinue();
        if (userYN == "n" || userYN == "no") {
            continueGame = false;  // End the game if the user doesn't want to continue
        }
    }

    // Print the summary of the game
    PrintSummary();

    return 0;
}