#ifndef HANGMAN_H
#define HANGMAN_H

#include<iostream>
#include<fstream>
#include<ctime>
#include<Windows.h>
#include<iomanip>
#include<string>
#include <stdio.h>				//for system("cls")
#include <stdlib.h>
using namespace std;




void displayMenu();				//game starting
string fileWork(int *);				//getting secret word in file 
void displayFileName(int);
int findCorrectAlphabet(char guessLetter, string secretWord, string & guessWord);		//searching of guessletter in secret word
void displayHangman(int, int, int);
void caseWork(int scores, int totalLives, int noOfWrongGuess, string guessWord, string secretWord, string name,int * fileNo);//logic of game,rules and exit wd switch statement

void myHangManGAme(int scores, int totalLives, int noOfWrongGuess, string secretWord, string name,int * fileNo);

#endif();