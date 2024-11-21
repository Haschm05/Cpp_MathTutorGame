/*
Program: Math Tutor Version 3
Programmers: Hayden Schmidt
Date: 11/19/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV5
Description: A simple math tutor for elementary students. Converts code to functions for easier testing and modification.
*/

#include <iostream> // required for couts & cins
#include <cstdlib> // allows for randomizer
#include <string> // allows for strings to be used
#include <limits> // required for numeric limits
#include <cctype>
#include <iomanip>
#include <vector>

#include "math_tutor.h" // includes header file

using namespace std;

//Intro Art
void IntroArt() {
    //*********************************************************************
    // Set of cout statements to display the Silly Math ASCII art and welcome banner
    cout << "*******************************************" << endl;
    cout << " _____ _ _ _      ___  ___      _   _    " << endl;
    cout << "/  ___(_| | |     |  /// |     | | | |   " << endl;
    cout << "| `--. _| | |_   _| .  . | __ _| |_| |__ " << endl;
    cout << " `--. | | | | | | | |//| |/ _` | __| '_ | " << endl;
    cout << " ___/ | | | | |_| | |  | | (_| | |_| | | |" << endl;
    cout << "/____/|_|_|_|__, /|_|  |_/,__,_|,__|_| |_|" << endl;
    cout << "            __/ /                       " << endl;
    cout << "           |___/                       " << endl;
    cout << "*******************************************" << endl;
    cout << "*    Welcome to Silly Math Tutor V5 by    *" << endl;
    cout << "*                  Hayden                 *" << endl;
    cout << "*******************************************" << endl;
    cout << endl;
    return;
}

//Intro Pun
void IntroPun() {
    string userYN;
    // Asks prompt whether to display the jokes or not
    cout << "Do you wanna hear some math puns? (y/n): ";
    cin >> userYN;
    if (userYN == "y") {
        //response to 'y' as input
        cout << "Great! Here they are:" << endl;

        // Couts to display jokes. After user input, jokes appear. Maybe add functionality later to reveal answers to jokes after pressing enter.
        cout << "*******************************************" << endl;
        cout << endl;
        cout << "Question: Do you think monsters are good at math?" << endl;
        cout << "Answer: No, unless you Count Dracula." << endl;
        cout << endl;
        cout << "Question: Which knight created the round table?" << endl;
        cout << "Answer: Sir Cumference." << endl;
        cout << endl;
        cout << "Question: What do you call a number who can't stay in place?" << endl;
        cout << "Answer: A roamin' numeral." << endl;
        cout << endl;
        cout << "*******************************************" << endl;
        cout << endl;
    }
    else {
        cout << "That's too bad." << endl;
    }
    cout << endl;
    return;
}

//Intro Get Name
string IntroGetName() {
    string userName = "unknown";

    // Beginning the interactive portion of the program
    cout << "Please enter your name to begin: ";
    cin >> userName;
    cout << endl;

    // Puts the user's name into the welcome message
    cout << "Welcome " << userName << ", to the Silly Math Tutor!" << endl;
    cout << endl;
    cout << "*******************************************" << endl;
    return userName;
}

// Function to generate a math question
void GenerateQuestion(Question &question, GameState &state) {
    int tempVal = (rand() % 4) + 1;  // Generates a number between 1 and 4
    // Randomize left and right numbers (using currentRange)
    question.leftNum = (rand() % state.currentRange) + 1;
    question.rightNum = (rand() % state.currentRange) + 1;

    // Select math operation
    switch (tempVal) {
        case 1:
            question.mathSymbol = '+';  // Addition
            question.correctAnswer = question.leftNum + question.rightNum;
            break;

        case 2:
            question.mathSymbol = '-';  // Subtraction
            // Ensure leftNum is greater than rightNum to avoid negative results
            if (question.leftNum < question.rightNum) {
                swap(question.leftNum, question.rightNum);
            }
            question.correctAnswer = question.leftNum - question.rightNum;
            break;

        case 3:
            question.mathSymbol = '*';  // Multiplication
            question.correctAnswer = question.leftNum * question.rightNum;
            break;

        case 4:
            question.mathSymbol = '/';  // Division
            // Following code makes sure division problem doesn't generate a fraction
            if (question.rightNum == 0) {
                question.rightNum = 1; // If the denominator is 0, set it to 1
            }
            // Ensure the left number is divisible by the right number
            while (question.leftNum % question.rightNum != 0) { // While the remainder is not 0
                question.leftNum = (rand() % state.currentRange) + 1; // Generate a new left number
            }
            question.correctAnswer = question.leftNum / question.rightNum;
            break;

        default:
            cout << "Invalid question type encountered." << endl;
            exit(-1); // Exit the function on invalid type
    }
}

// Function to ask a question and return the question's details
void AskUser(Question &question, GameState &state, const string &userName, vector<Question> &questions) {
    int userAnswer = 0;
    int attemptCount = 0;

    // Ask the user the math question
    for (int i = 1; i <= MAX_ATTEMPTS; i++) {
        cout << endl;
        cout << "[Level #" << question.mathLevel << "] " << userName << ", what is "
             << question.leftNum << " " << question.mathSymbol << " " << question.rightNum << " = ";

        // Loop until the user enters a valid numeric input
        while (!(cin >> userAnswer)) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "\tInvalid input! Please enter a number: ";
        }

        // Check if the answer is correct
        if (userAnswer == question.correctAnswer) {
            attemptCount = i;  // Store the attempt count when the user answers correctly
            state.totalCorrect++;     // Increment total correct answers
            state.correct++;
            cout << "Correct!" << endl;
            break;
        }
        else if (i == MAX_ATTEMPTS) {
            cout << "Oops! You'll get 'em next time!" << endl;
            cout << "The correct answer was " << question.correctAnswer << "." << endl;
            state.totalIncorrect++;  // Increment total incorrect answers
            state.incorrect++;
            break;  // Exit the loop after max attempts
        }
        else {
            cout << "That was incorrect. You have " << MAX_ATTEMPTS - i << " attempts left." << endl;
        }
    }

    // Save the question to the list
    question.attemptCount = attemptCount;
    questions.push_back(question);
}

// Level the difficulty based on user performance
void LevelUpOrDown(GameState &state) {
    cout << endl;

    //For troubleshooting
    //cout << state.mathLevel;

    if (state.correct >= 3) { // Levels up after 3 correct answers in a row
        state.mathLevel++;
        state.correct = 0; // Reset the streak counter
        state.incorrect = 0;
        state.currentRange += LEVEL_RANGE_CHANGE; // Adds 10 to current range
        cout << "You are now on Level " << state.mathLevel << "!" << endl;
        cout << "New range is 1 to " << state.currentRange << endl;
        cout << endl;
    }
    else if (state.incorrect >= 3 && state.mathLevel > 1) { // Levels down after 3 wrong answers
        state.mathLevel--;
        state.correct = 0;
        state.incorrect = 0;
        state.currentRange -= LEVEL_RANGE_CHANGE; // Subtracts 10 from current range
        cout << "You got too many wrong, leveling you down." << endl;
        cout << "You are now on Level " << state.mathLevel << "!" << endl;
        cout << "New range is 1 to " << state.currentRange << endl;
        cout << endl;
    }
}

string AskContinue() {
    string userYN;

    // clears input(fixes issue with interaction between leveling and continue)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Do you want to continue? (y = yes | n = no): ";
    getline(cin, userYN);  // Use getline to avoid issues with leftover newline characters.

    // Convert the user's input to lowercase
    for (int i = 0; i < userYN.size(); i++) {
        userYN.at(i) = tolower(userYN.at(i));
    }

    // Check for valid inputs
    while (userYN != "y" && userYN != "yes" && userYN != "n" && userYN != "no") {
        cout << "Invalid input, please try again: ";
        getline(cin, userYN);  // Use getline again for consistent input handling.
    }

    return userYN;
}

// Function to print summary report
void PrintSummary() {
    cout << "**************************************" << endl;
    cout << "*           Summary Report           *" << endl;
    cout << "**************************************" << endl;
    cout << "Level:    Question:         Attempts: " << endl;
    cout << "______    _________         _________ " << endl;

    int totalQuestions = 0;
    double averageCorrect = 0;

    // Loop through each question to print details
    for (const auto &question : questions) {
        cout << setw(2) << right << question.mathLevel << "\t"
             << setw(3) << right << question.leftNum << " "
             << question.mathSymbol << " " << question.rightNum << " = "
             << question.correctAnswer << " ";

        if (question.attemptCount != 0) {
            cout << "\t\t" << question.attemptCount << endl;
        } else {
            cout << "\t\tIncorrect" << endl;
        }
        totalQuestions++;
    }

    // Calculate the average correct percentage
    averageCorrect = (static_cast<double>(state.totalCorrect) / totalQuestions) * 100;

    cout << "\nTotal questions: " << totalQuestions << endl;
    cout << "Total correct: " << state.totalCorrect << endl;
    cout << "Total incorrect: " << state.totalIncorrect << endl;
    cout << "Average correct: " << fixed << setprecision(2) << averageCorrect << "%" << endl;

    cout << "\nThank you for playing Silly Math Tutor!" << endl;
    cout << "Be sure to come back in the near future for more fun!" << endl;
}