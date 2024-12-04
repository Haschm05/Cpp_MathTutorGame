/*
Program: Math Tutor Version 6
Programmers: Hayden Schmidt
Date: 12/3/24 *Last updated version
Github URL: https://github.com/Haschm05/MathTutorV6
Description: A simple math tutor for elementary students. Allows user to save and load game.
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
//void SaveGame(const string &filename, const vector<int> &gameState, const vector<vector<int>> &questions);
//bool LoadGame(const string &filename, vector<int> &gameState, vector<vector<int>> &questions);


#endif //MATH_TUTOR_H
