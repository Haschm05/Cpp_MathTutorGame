/*
Program: Math Tutor Version 3
Programmers: Hayden Schmidt
Date: 11/19/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV5
Description: A simple math tutor for elementary students. Converts code to functions for easier testing and modification.
*/

#ifndef MATH_TUTOR_H
#define MATH_TUTOR_H

#include <string>
#include <vector>

using namespace std;

// Constants
const int MAX_ATTEMPTS = 3;
const int LEVEL_RANGE_CHANGE = 10;

// Structs for storing global state and question data
struct GameState {
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int correct = 0;
    int incorrect = 0;
    int mathLevel = 1;
    int currentRange = 10;
};

struct Question {
    int mathLevel;
    int leftNum;
    char mathSymbol;
    int rightNum;
    int correctAnswer;
    int attemptCount;
};

//Vectors
extern vector<Question> questions;  // Vector holding all the questions asked
extern GameState state;  // Global state for tracking total correct, incorrect, etc.

//functions
void IntroArt();
void IntroPun();
string IntroGetName();
void GenerateQuestion(Question &question, GameState &state);
void AskUser(Question &question, GameState &state, const string &userName, vector<Question> &questions);
void LevelUpOrDown(GameState &state);
string AskContinue();
void PrintSummary();


#endif //MATH_TUTOR_H
