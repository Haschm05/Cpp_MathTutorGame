/*
Program: Math Tutor Version 5
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
    else { //if the user does not answer yes
        cout << "That's too bad." << endl;
    }
    cout << endl;
}

//Intro Get Name
string IntroGetName() {
    string userName = "unknown";

    // Beginning the interactive portion of the program
    cout << "Please enter your name to begin: ";
    getline(cin, userName); // Clears out leftover carriage return
    getline(cin, userName); // Get user input for name
    cout << endl;

    // Puts the user's name into the welcome message
    cout << "Welcome " << userName << ", to the Silly Math Tutor!" << endl;
    cout << endl;
    cout << "*******************************************" << endl;
}

// Function to generate a math question
void GenerateQuestion(vector<vector<int> > questions) {
    int leftNum = 0;
    int rightNum = 0;
    int currentRange = 0;
    char mathSymbol = '?';
    int correctAnswer = 0;
    int temp = 0;
    int mathLevel = 0;
    string userName;

    //Portion of code dedicated to random number generation
    leftNum = (rand() % currentRange) + 1; //randomizes first number
    rightNum = (rand() % currentRange) + 1; //randomizes second number

    //enum to replace the mathType integer
    enum mthType { MT_ADD, MT_SUB, MT_MUL, MT_DIV };
    mthType questionType;

    questionType = static_cast<mthType>(rand() % 4); //Randomizes question type

    switch (questionType) {
        // assigns math symbol
        case MT_ADD:
            mathSymbol = '+'; //assigns an addition problem
            correctAnswer = leftNum + rightNum; // adds the numbers and stores correct answer
            break;

        case MT_SUB:
            mathSymbol = '-'; //assigns a subtraction problem
        // This is used to make sure the left number is larger than the right, preventing negative numbers.
            if (leftNum < rightNum) {
                temp = leftNum;
                leftNum = rightNum;
                rightNum = temp;
            }
            correctAnswer = leftNum - rightNum;
            break;

        case MT_MUL:
            mathSymbol = '*'; //assigns a multiplication problem
            correctAnswer = leftNum * rightNum;
            break;

        case MT_DIV:
            mathSymbol = '/'; //assigns a division problem
        // Following code makes sure division problem doesn't generate a fraction
            correctAnswer = leftNum;
            leftNum *= rightNum;
            break;

        default: // This is here to catch any errors
            cout << "Invalid question type: " << mathSymbol << endl;
            cout << "Contact RivJams or Haschm05 about the error" << endl;
            cout << "Program ended with a -1 error" << endl;
    }

    vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAnswer};
}

// Function to ask a question and return the question's details
void AskUser(vector<vector<int>> questions) {

    tracking++;

    int mathLevel = 0;
    int leftNum = 0;
    int rightNum = 0;
    int correctAnswer = 0;
    int attemptCount = 0;
    int userAnswer = 0;
    char mathSymbol = '?';
    string userName;

    vector<vector<int>> row;

    mathLevel = questions.at(tracking).at(0);
    leftNum = questions.at(tracking).at(1);
    mathSymbol = static_cast<char>(questions.at(tracking).at(2)); // Change to MathType
    rightNum = questions.at(tracking).at(3);
    correctAnswer = questions.at(tracking).at(4);

    for (int i = 1; i <= MAX_ATTEMPTS; i++) { //Loops until user gets answer correct or until 3 wrong attempts
        cout << endl;
        cout << "[Level #" << mathLevel << "] " << userName << ", what does "
        << leftNum << " " << mathSymbol << " " << rightNum << " = ";


        // Loop until the user enters numeric data "From the assignment document"
        while (!(cin >> userAnswer)) {
            cin.clear(); // clear the cin error flag
            cin.ignore(numeric_limits<streamsize>::max() ,'\n'); // ignore the max input, up to 'n'
            cout << "\tInvalid input!" << endl;
            cout << "\tPlease enter a number: ";
        } // end of get userAnswer while loop

        cout << endl; // extra space in between the answer and the confirmation message

        // Tests to see if user answer is correct
        if (userAnswer == correctAnswer) { //Displays when correct
            row.push_back(vector<vector<int> >::value_type(i));
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
             row.push_back({0});
        }
        else { //Else runs until user is out of attempts or until user gets the question correct
            cout << "That was incorrect. You have " << MAX_ATTEMPTS - i << " attempts left." << endl;
        }
    }

    // Modify the original questions vector by adding the row
    questions.push_back(row.back());  // Push the last vector<int> in row to questions
}

void LevelUpOrDown() {
    cout << endl;

    string userYN = "n";

    getline(cin, userYN);

    //Asking user if they want to continue
    while (true) {
        cout << "Do you want to continue? (y = yes | n = no): ";
        getline(cin, userYN);

        //to lower case the users input
        for (int i = 0; i < userYN.size(); i++) {
            userYN.at(i) = tolower(userYN.at(i));
        }
        if (userYN == "y" || userYN == "yes" || userYN == "no" || userYN == "n") {
            break;
        }else {
            cout << "Invalid input, please try again..." << endl;
            cout << endl;
        } //end of if (y, yes, n, no)
    }// end of inner while loop to validate yes, no
}

string AskContinue(string userYN) {

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

    int mathLevel = 0;
    int leftNum = 0;
    int rightNum = 0;
    int correctAnswer = 0;
    int attemptCount = 0;
    int userAnswer = 0;
    int averageCorrect = 0;
    int totalQuestions = 0;
    char mathSymbol = '?';
    string userName;



     //Outputs Vector for summary report
    cout << "**************************************" << endl;
    cout << "*           Summary Report           *" << endl;
    cout << "**************************************" << endl;
    cout << "Level:    Question:         Attempts: " << endl;
    cout << "______    _________         _________ " << endl;

    totalCorrect = 0; //Resets these values to 0
    totalIncorrect = 0;

    for (int i = 0; i < questions.size(); i++) {
        mathLevel = questions.at(i).at(0);
        leftNum = questions.at(i).at(1);
        mathSymbol = static_cast<char>(questions.at(i).at(2)); // Change to MathType
        rightNum = questions.at(i).at(3);
        correctAnswer = questions.at(i).at(4);
        attemptCount = questions.at(i).at(5); //? questions.at(i).at(5) : 0; // Safely access attempts

        cout << setw(2) << right << mathLevel // Outputting the math problem stored in the vector
             << setw(9) << right << leftNum
             << " " << mathSymbol << " "
             << setw(2) << left << rightNum
             << setw(2) << right << " = "
             << setw(2) << left << correctAnswer << " ";

        if (attemptCount != 0) {
            cout << setw(10) << right << attemptCount << endl; // Align attempts
            totalCorrect++;
        } else {
            cout << setw(10) << right << "     Incorrect" << endl; // Align "Incorrect"
            totalIncorrect++;
        }
        totalQuestions++;
    }

    //Display the totals for number of questions, correct, and incorrect answers
    cout << endl;
    averageCorrect = (static_cast<double>(totalCorrect) / totalQuestions) * 100.0;
    cout << "Total questions: " << setw(10) << right << totalQuestions << endl;
    cout << "Total correct  : " << setw(10) << right << totalCorrect << endl;
    cout << "Total incorrect: " << setw(10) << right << totalIncorrect << endl;
    cout << "Average correct: " << setw(10) << right << averageCorrect << "%" << endl; // Displays the average correct

    // End of program. Leave message to user. Couts break up the end message to display better in console.
    cout << endl;
    cout << "Thank you, " << userName << ", for playing Silly Math Tutor!" << endl;
    cout << endl;
    cout << "Be sure to come back in the near future" << endl;
    cout << "for more updates, and most importantly," << endl; // promises future improvements, the next being Version 3
    cout << "MORE FUN!" << endl;
}