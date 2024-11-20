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

// fixes compiler error(chatGPT for the save)
extern vector<vector<int>> questions;  // Declare the vector as extern
extern int totalCorrect;  // Declare totalCorrect as extern
extern int totalIncorrect;  // Declare totalIncorrect as extern

//Troubleshooting but it worked
extern int correct;
extern int incorrect;

void IntroArt();
void IntroPun();
string IntroGetName();
void AskQuestion(int& leftNum, int& rightNum, char& mathSymbol, int mathLevel, const string& userName, int currentRange);
void LevelUpOrDown(int &mathLevel, int &currentRange);
string AskContinue();
void PrintSummary();


#endif //MATH_TUTOR_H
