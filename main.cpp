/*
Program: Math Tutor Version 3
Programmers: Hayden Schmidt
Date: 11/19/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV6.git
Description: A simple math tutor for elementary students. Adds the final summary.
*/

#include <iostream> // required for couts & cins
#include <cstdlib> // allows for randomizer
#include <ctime> // enables use of time function
#include <string> // allows for strings to be used
#include <limits> // required for numeric limits
#include <cctype>
#include <iomanip>
#include <vector>
using namespace std; // sets standard namespace

//Vectors
vector<vector<int>> questions;
//Constants
const int MAX_ATTEMPTS = 3; //Sets how many attempts per question
const int LEVEL_RANGE_CHANGE = 10; //Sets how much the range changes per level
int totalCorrect = 0; //Counter for correct answers
int totalIncorrect = 0; //Counter for incorrect answers

//Intro
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
    }
    else {
        cout << "That's too bad." << endl;
        cout << "You're gonna hear them anyway!" << endl;
    }
    cout << endl;
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
    return;
}

string IntroGetName() {
    string userName = "0";
    // Beginning the interactive portion of the program
    cout << "Please enter your name to begin: ";
    getline(cin, userName); // Get user input for name
    cout << endl;
    // Puts the user's name into the welcome message
    cout << "Welcome " << userName << ", to the Silly Math Tutor!" << endl;
    cout << endl;
    cout << "*******************************************" << endl;
    return userName;
}
void GenerateRandomNumbers(int &leftNum, int &rightNum, int currentRange) {
    leftNum = (rand() % currentRange) + 1;
    rightNum = (rand() % currentRange) + 1;
}

void AskQuestion(int leftNum, int rightNum, char mathSymbol, int mathLevel, string userName) {

    int userAnswer = 0;
    int attemptCount = 0;
    int correctAnswer = 0; // Declare correctAnswer

    for (int i = 1; i <= MAX_ATTEMPTS; i++) { //Loops until user gets answer correct or until 3 wrong attempts

        cout << endl;
        cout << "[Level #" << mathLevel << "] " << userName << ", what does "
                << leftNum << " " << mathSymbol << " " << rightNum << " = ";

        // Loop until the user enters numeric data "From the assignment document"
        while (!(cin >> userAnswer)) {
            cin.clear(); // clear the cin error flag
            cin.ignore(numeric_limits<streamsize>::max() ,
                       '\n'); // ignore the max input, up to 'n'
            cout << "\tInvalid input!" << endl;
            cout << "\tPlease enter a number: ";
        } // end of get userAnswer while loop
        cout << endl; // extra space in between the answer and the confirmation message

        // Tests to see if user answer is correct
        if (userAnswer == correctAnswer) { //Displays when correct
            attemptCount = i;
            totalCorrect++;
            cout << "Correct!" << endl;
            cout << "You're a real Math Whizz!" << endl;
            cout << endl;
            break;
        }
        else if (i == MAX_ATTEMPTS) { //Displays when incorrect
            cout << "Oops!" << endl;
            cout << "You'll get 'em next time!" << endl;
            cout << "The correct answer was " << correctAnswer << "." << endl; //gives the user the right answer
            totalIncorrect++;
            cout << endl;
            attemptCount = 0;
        }
        else { //Else runs until user is out of attempts or until user gets the question correct
            cout << "That was incorrect. You have " << MAX_ATTEMPTS - i << " attempts left." << endl;
        }
    }
    questions.push_back({mathLevel, leftNum, mathSymbol, rightNum, correctAnswer, attemptCount});
}
void LevelUpOrDown(int &mathLevel, int &currentRange) {
    if (totalCorrect == 3) { //Levels up if correct answers = 3
        mathLevel++;
        totalCorrect = 0; //Resets totalCorrect and totalIncorrect
        totalIncorrect = 0;
        currentRange += LEVEL_RANGE_CHANGE; //Adds 10 to current range
        cout << "You are now on Level " << mathLevel << "!" << endl;
        cout << "New range is 1 to " << currentRange << endl;
        cout << endl;
    }
    else if (totalIncorrect >= 3 && mathLevel > 1) { //Levels down after 3 wrong attempts. Will not level down on first level
        mathLevel--;
        totalCorrect = 0;
        totalIncorrect = 0;
        currentRange -= LEVEL_RANGE_CHANGE; //Subtracts 10 from current range
        cout << "You are now on Level " << mathLevel << "!" << endl;
        cout << "New range is 1 to " << currentRange << endl;
        cout << endl;
    }
}

void PrintSummary() {
    cout << "**************************************" << endl;
    cout << "*           Summary Report           *" << endl;
    cout << "**************************************" << endl;
    cout << "Level:    Question:         Attempts: " << endl;
    cout << "______    _________         _________ " << endl;
    int totalQuestions = 0;
    double averageCorrect = 0;
    for (int i = 0; i < questions.size(); i++) {
        int mathLevel = questions[i][0];
        int leftNum = questions[i][1];
        char mathSymbol = static_cast<char>(questions[i][2]);
        int rightNum = questions[i][3];
        int correctAnswer = questions[i][4];
        int attemptCount = questions[i][5];
        cout << setw(2) << right << mathLevel << "     " << setw(3) << right << leftNum << " "
                << mathSymbol << " " << rightNum << " = " << correctAnswer << " ";
        if (attemptCount != 0) {
            cout << "     " << attemptCount << " Attempt(s)" << endl;
        } else {
            cout << "      Incorrect" << endl;
        }
        totalQuestions++;
    }
    averageCorrect = (static_cast<double>(totalCorrect) / totalQuestions) * 100;
    cout << "\nTotal questions: " << totalQuestions << endl;
    cout << "Total correct: " << totalCorrect << endl;
    cout << "Total incorrect: " << totalIncorrect << endl;
    cout << "Average correct: " << averageCorrect << "%" << endl;
    cout << "\nThank you for playing Silly Math Tutor!" << endl;
    cout << "Be sure to come back in the near future for more fun!" << endl;
}

int main() {
    // Declares and initializes variables
    //Integers
    int leftNum = 0;
    int rightNum = 0;
    int mathType = 0;
    int userAnswer = 0;
    int temp = 0;
    int averageCorrect = 0;
    int totalQuestions = 0;
    int mathLevel = 1; //Starts user on level 1
    int currentRange = LEVEL_RANGE_CHANGE; //Sets starting range at 10
    int attemptCount = 0;

    //Strings
    string userYN = "?";

    //Chars
    char mathSymbol = '?';

    srand(time(0)); // Generates a unique seed so its random.

    // Starting the main function
    IntroArt();
    //IntroPun();
    //string userName = IntroGetName();
    //GenerateRandomNumbers();
    //AskQuestion();
    //LevelUpOrDown();
    //PrintSummary();

    return 0;
}
