/*
Program: Math Tutor Version 5
Programmers: Hayden Schmidt
Date: 11/19/24 *Last updated version
GitHub URL: https://github.com/Haschm05/MathTutorV5
Description: A simple math tutor for elementary students. Converts code to functions for easier testing and modification.
*/

#ifndef MATH_TUTOR_H
#define MATH_TUTOR_H

#include <string>
#include <vector>

using namespace std;

//functions
void IntroArt();
void IntroPun();
string IntroGetName();
void LevelUpOrDown(int &attempt, int &mathLevel);
vector<int> GenerateQuestion(int mathLevel);
bool AskUser(vector<int> &row, string userName);
string AskContinue();
void PrintSummary(const vector<vector<int>> &questions, string userName);


#endif //MATH_TUTOR_H
