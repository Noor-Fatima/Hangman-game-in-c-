#include"Hangman.h"
using namespace std;

//global variables

string secretWord;				//declare variables
char guessLetter;
int totalLives = 7;
int scores = 0;					//add 10 when rigthGuess 
int noOfWrongGuess = 0;
string name;
int fileNo=0;


int GetFontSize(HANDLE windowHandle, COORD *size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	*size = font.dwFontSize;

	return 1;
}

int SetFontSize(HANDLE windowHandle, COORD size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	font.dwFontSize = size;

	if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
	{
		return 0;
	}

	return 1;
}

int main(void)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size;

	if (GetFontSize(h, &size))
	{
		/* Grow by 50% */
		size.X += (SHORT)(size.X * 1);
		size.Y += (SHORT)(size.Y * 1);
		SetFontSize(h, size);
	}
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);          //you don't have to call this function every time

	CONSOLE_FONT_INFOEX font;                                 //CONSOLE_FONT_INFOEX is defined in some windows header
	GetCurrentConsoleFontEx(outcon, false, &font);            //PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	font.dwFontSize.X = 12;
	font.dwFontSize.Y = 12;
	SetCurrentConsoleFontEx(outcon, false, &font);

	SetConsoleTextAttribute(outcon, 0x0C);
	cout << "Hello  -----------------------Welcome To My First Game \n\n\n\n";
	cout << "HANGMAN";
	cout << "\n\n\ncredits: "
		<< "NOOR FATIMA (BSEF15M055)\n";
	cout << "press any key to continue\n";
	cin.get();
	system("cls");
	myHangManGAme(scores, totalLives, noOfWrongGuess, secretWord, name, &fileNo);

	return EXIT_SUCCESS;
}



