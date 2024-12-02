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

//Vectors
extern vector<vector<int>> questions;

//Trying something
int tracking = 0;
int totalCorrect = 0;
int totalIncorrect = 0;

//functions
void IntroArt();
void IntroPun();
string IntroGetName();
void GenerateQuestion(vector<vector<int>> questions);
void AskUser(vector<vector<int>> questions);
void LevelUpOrDown();
string AskContinue(string userYN);
void PrintSummary();


#endif //MATH_TUTOR_H
