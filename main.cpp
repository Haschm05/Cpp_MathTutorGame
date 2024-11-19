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

using namespace std; // sets standard namespace

//Vectors and vector variables
vector<vector<int>> questions;
int totalCorrect = 0; //Counter for correct answers
int totalIncorrect = 0; //Counter for incorrect answers

//Constants
const int MAX_ATTEMPTS = 3; //Sets how many attempts per question
const int LEVEL_RANGE_CHANGE = 10; //Sets how much the range changes per level

//Used for leveling(not vector)
int correct = 0;
int incorrect = 0;

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

// Struct to store question data (ChatGPT helped with this one, was having trouble with name spaces)
struct Question {
    int mathLevel;
    int leftNum;
    char mathSymbol;
    int rightNum;
    int correctAnswer;
    int attemptCount;
};

// Asks a math question
void AskQuestion(int& leftNum, int& rightNum, char& mathSymbol, int mathLevel, const string& userName, int currentRange) {
    int userAnswer = 0;
    int attemptCount = 0;
    int correctAnswer = 0;
    int tempVal;

    // Randomize left and right numbers (using currentRange)
    leftNum = (rand() % currentRange) + 1;
    rightNum = (rand() % currentRange) + 1;

    // Randomly choose a math operation
    tempVal = (rand() % 4) + 1;  // Generates a number between 1 and 4

    // Select math operation
    switch (tempVal) {
        case 1:
            mathSymbol = '+';  // Addition
            correctAnswer = leftNum + rightNum;
            break;

        case 2:
            mathSymbol = '-';  // Subtraction
            // Ensure leftNum is greater than rightNum to avoid negative results
            if (leftNum < rightNum) {
                swap(leftNum, rightNum);
            }
            correctAnswer = leftNum - rightNum;
            break;

        case 3:
            mathSymbol = '*';  // Multiplication
            correctAnswer = leftNum * rightNum;
            break;

        case 4:
            mathSymbol = '/';  // Division
            correctAnswer = leftNum / rightNum;
            break;

        default:
            cout << "Invalid question type encountered." << endl;
            return; // Exit the function on invalid type
    }

    // Ask the user the math question
    for (int i = 1; i <= MAX_ATTEMPTS; i++) {
        cout << endl;
        cout << "[Level #" << mathLevel << "] " << userName << ", what is "
             << leftNum << " " << mathSymbol << " " << rightNum << " = ";

        // Loop until the user enters a valid numeric input
        while (!(cin >> userAnswer)) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "\tInvalid input! Please enter a number: ";
        }

        // Check if the answer is correct
        if (userAnswer == correctAnswer) {
            attemptCount = i;  // Store the attempt count when the user answers correctly
            totalCorrect++;     // Increment total correct answers
            correct++;
            cout << "Correct!" << endl;
            break;
        }
        else if (i == MAX_ATTEMPTS) {
            cout << "Oops! You'll get 'em next time!" << endl;
            cout << "The correct answer was " << correctAnswer << "." << endl;
            totalIncorrect++;  // Increment total incorrect answers
            incorrect++;
            break;  // Exit the loop after max attempts
        }
        else {
            cout << "That was incorrect. You have " << MAX_ATTEMPTS - i << " attempts left." << endl;
        }
    }

    // Save the question to the list
    questions.push_back({mathLevel, leftNum, mathSymbol, rightNum, correctAnswer, attemptCount});
}

//Level the difficulty
void LevelUpOrDown(int &mathLevel, int &currentRange) {

    if (correct == 3) { //Levels up if correct answers = 3
        mathLevel++;
        correct = 0; //Resets correct and incorrect
        incorrect = 0;
        currentRange += LEVEL_RANGE_CHANGE; //Adds 10 to current range
        cout << "You are now on Level " << mathLevel << "!" << endl;
        cout << "New range is 1 to " << currentRange << endl;
        cout << endl;
    }
    else if (totalIncorrect >= 3 && mathLevel > 1) { //Levels down after 3 wrong attempts. Will not level down on first level
        mathLevel--;
        correct = 0;
        incorrect = 0;
        currentRange -= LEVEL_RANGE_CHANGE; //Subtracts 10 from current range
        cout << "You are now on Level " << mathLevel << "!" << endl;
        cout << "New range is 1 to " << currentRange << endl;
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
    int correctAnswer = 0;

    //Strings
    string userYN = "?";
    string userName = "unknown";

    //Chars
    char mathSymbol = '?';

    srand(time(0)); // Generates a unique seed so its random.

    // Starting the main code
    IntroArt(); //outputs AscII aart
    IntroPun(); // outputs pun
    userName = IntroGetName(); // gets username

    do {
        AskQuestion(leftNum, rightNum, mathSymbol, mathLevel, userName, currentRange); // generates and asks question
        LevelUpOrDown(mathLevel, currentRange);  // Call the leveling function
        userYN = AskContinue();
    } while (userYN == "y" || userYN == "yes"); //Loop goes until userYN no longer equals "yes"

    PrintSummary();

    return 0;
}
