/*
Program: Math Tutor Version 6
Programmers: Hayden Schmidt
Date: 12/3/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV6
Description: A simple math tutor for elementary students. Allows user to save and load game.
Code has been broken into several functions for easier testing. Displays a summary of questions when done.
Levels the difficulty of questions based on how many questions the user gets right or wrong.
Generates random problems. Has a user interface.
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
void PrintSummary(const vector<vector<int>> &questions, string userName);
string YNQuestion();
void SaveGame(string userName, vector<vector<int>> &questions);
int LoadGame(string userName, vector<vector<int>> &questions);


#endif //MATH_TUTOR_H
