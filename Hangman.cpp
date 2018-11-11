#include"Hangman.h"

void myHangManGAme(int scores, int totalLives, int noOfWrongGuess, string secretWord, string name,int *fileNo)
{
	char conOpt;
	do
	{
		system("color 50");
		system("cls");
		//	THE MAIN layout of the game
		displayMenu();
		cout << "\n\t\t\tENTER YOUR NAME\t\t";
		getline(cin, name);
		secretWord = fileWork(fileNo);
		string guessWord(secretWord.length(), '-');		//show the lenght of the secret word to the user  //fill constructor
		caseWork(scores, totalLives, noOfWrongGuess, guessWord, secretWord, name,fileNo);
		cout << "\t\t\tDo you wand to play again: ";
		char n, y;
		cout << " Enter y for YES\n";
		cin >> conOpt;
		cin.ignore();
	} while (conOpt == 'y');

}

int findCorrectAlphabet(char guessLetter, string secretWord, string & guessWord)
{
	int noOfMatches = 0;
	int len = secretWord.length();
	for (int i = 0; i < len; i++)
	{

		if (guessLetter == guessWord[i])
		{
			cout << "\t\t\tsorry! plz try again this word is uased before...thank you\n";
		}
		else if (guessLetter == secretWord[i])
		{

			guessWord[i] = guessLetter;
			noOfMatches++;
		}
	}
	return noOfMatches;
}
void displayHangman(int noOfWrongGuess, int totalLives, int scores)
{

	if (noOfWrongGuess == 1)
	{
		system("color 44");
		system("cls");
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
		cout << "\t\tlifes   " << totalLives - noOfWrongGuess << "\n\t\tscore=" << scores;
		cout << "\n\n\n"
			<< "                  *----*  " << endl
			<< "                  |    |  " << endl
			<< "                  |      " << endl
			<< "                  |       " << endl
			<< "                  |       " << endl
			<< "                  |       " << endl
			<< "              ----------------" << endl << endl;;
	}

	else if (noOfWrongGuess == 2)
	{
		system("color 46");
		system("cls");
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
		cout << "\t\tlifes   " << totalLives - noOfWrongGuess << "\n\t\tscore=" << scores;

		cout << "\n\n\n"
			<< "                  *----*  " << endl
			<< "                  |    |  " << endl
			<< "                  |    O  " << endl
			<< "                  |       " << endl
			<< "                  |       " << endl
			<< "                  |       " << endl
			<< "              -------------" << endl << endl;
	}
	else if (noOfWrongGuess == 3)

	{
		system("color 48");
		system("cls");

		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
		cout << "\t\tlifes   " << totalLives - noOfWrongGuess << "\n\t\tscore=" << scores;
		cout << "\n\n\n"
			<< "                 +----+  " << endl
			<< "                 |    |" << endl
			<< "                 |    O  " << endl
			<< "                 |    |  " << endl
			<< "                 |       " << endl
			<< "                 |       " << endl
			<< "              ----------------" << endl << endl;
	}
	else if (noOfWrongGuess == 4)
	{
		system("color 57");
		system("cls");
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
		cout << "\t\tlifes   " << totalLives - noOfWrongGuess << "\n\t\tscore=" << scores;
		cout << "\n\n\n"
			<< "                  *----*  " << endl
			<< "                  |    |  " << endl
			<< "                  |    O  " << endl
			<< "                  |   /|  " << endl
			<< "                  |       " << endl
			<< "                  |       " << endl
			<< "                --------------" << endl << endl;
	}
	else if (noOfWrongGuess == 5)
	{
		system("color 80");
		system("cls");
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
		cout << "\t\tlifes   " << totalLives - noOfWrongGuess << "\n\t\tscore=" << scores;
		cout << "\n\n\n"
			<< "                      +----+  " << endl
			<< "                      |    |  " << endl
			<< "                      |    O  " << endl
			<< "                      |   /|\\ " << endl
			<< "                      |      " << endl
			<< "                      |       " << endl
			<< "                --------------" << endl << endl;
	}
	else if (noOfWrongGuess == 6)
	{
		system("color 82");
		system("cls");
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
		cout << "\t\tlifes   " << totalLives - noOfWrongGuess << "\n\t\tscore=" << scores;
		cout << "\n\n\n"
			<< "                  *----*   " << endl
			<< "                  |    |   " << endl
			<< "                  |    O   " << endl
			<< "                  |   /|\\  " << endl
			<< "                  |   /   " << endl
			<< "                  |        " << endl
			<< "                --------------" << endl << endl;
	}
	else if (noOfWrongGuess == 7)
	{
		system("color 83");
		system("cls");
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
		cout << "\t\tlifes   " << totalLives - noOfWrongGuess << "\n\t\tscore=" << scores;
		cout << "\n\n\n"
			<< "                     *----*     " << endl
			<< "                     |    |     " << endl
			<< "                     |    O     " << endl
			<< "                     |   /|\\    " << endl
			<< "                     |   / \\    " << endl
			<< "                     |You are hanged " << endl
			<< "                -------------" << endl << endl;
	}
}
string fileWork(int * fileNo)
{
	const int totalFiles = 5;
	string fileName[totalFiles] = { "Animal.txt", "General.txt","Fruits.txt","Country.txt","Sports.txt" };
	srand(time(NULL));
	*fileNo = rand() % totalFiles;
	ifstream ifs;					//reading from the file
	ifs.open(fileName[2]);
	string str;
	if (ifs.is_open())
	{

		ifs.seekg(0, ifs.end);
		int i = ifs.tellg();
		int r = rand() % i;
		ifs.seekg(r);
		
		ifs >> str;
		ifs >> str;
	}

	ifs.close();
	return str;
}
void displayFileName(int fileNo)
{
	if (fileNo == 0)
	{
		cout << "\t\t\tGuess Animal names: \n";
	}
	else if (fileNo == 1)
	{
		cout << "\t\t\tGuess Generally: \n";
	}
	else if (fileNo == 2)
	{
		cout << "\t\t\tGuess Fruits names: \n";
	}
	else if (fileNo == 3)
	{
		cout << "\t\t\tGuess Country names: \n";
	}
	else if (fileNo == 4)
	{
		cout << "\t\t\tGuess Sports names: \n";
	}
}
void displayMenu()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "!";
	}
	cout << endl;
	cout << "!"  << "\t\tHANGROMAN"<< "  \t\t!\n";
	cout << "!"  << "\t\tpress 1: To play game"<< "  \t\t!\n";
	cout << "!"  << "\t\tpress 2: For rules"<< "    \t\t!\n";
	cout << "!"  << "\t\tpress 3: To exit"<< "  \t\t!\n";
	for (int i = 0; i < 50; i++)
	{
		cout << "!";
	}
}
void caseWork(int scores, int totalLives, int noOfWrongGuess, string guessWord, string secretWord, string name,int * fileNo)
{
	int opt;
	cout << "\n\t\tenter option";
	cin >> opt;


	switch (opt)
	{

		case 1:
			//when user enter 1 to play game
		{
				  displayFileName(*fileNo);
				  system("color 27");
				  while (noOfWrongGuess < totalLives &&  guessWord != secretWord)
				  {
					  cout <<"\t\t\tGUESSWORD :  "<< guessWord;
					  char guessLetter;
					  cout << "\n\n\t\tEnter Letter: \n\t\t\t";
					  cin >> guessLetter;
					  if (findCorrectAlphabet(guessLetter, secretWord, guessWord) == 0)
					  {
						  cout << "\n\t\tletter is not in secret word\n\n";
						  noOfWrongGuess = noOfWrongGuess + 1;
						  displayHangman(noOfWrongGuess, totalLives, scores);
					  }
					  else
					  {
						  cout << "\n\t\tcongrats! you found the ri8 one\n";
						  cout << "\tnow word is::" << guessWord << endl;
						  scores += 10;
						  displayHangman(noOfWrongGuess, totalLives, scores);
					  }
					  if (secretWord == guessWord)
					  {
						  displayHangman(noOfWrongGuess, totalLives, scores);
						  system("color 12");
						  system("cls");
						  cout << "\n\t\t\t\tCongrats you won the game\n\n\n";
						  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						  cout << "!  Name :  " << name << "                                                !\n";
						  cout << "!  score   :" << scores << "                                             !\n";
						  cout << "!  word was " << secretWord << " \t	 lifes left : " << totalLives - noOfWrongGuess << "!\n";
						  cout << "!           " << "             Best of luck!                             !\n";
						  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
					  }
					  if (noOfWrongGuess == totalLives)
					  {
						  displayHangman(noOfWrongGuess, totalLives, scores);
						  system("color 37");
						  system("cls");
						  cout << "You loss the game\n\n\n";
						  //cout << "the secret word is :: " << secretWord << "  \n\ncongrats you won the game\n\n\n";
						  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						  cout << "!  Name :  "; cout << name << "                                          !\n";
						  cout << "!  score   :" << scores << "                                             !\n";
						  cout << "!  word was " << secretWord << "\t lifes left : " << totalLives - noOfWrongGuess << "!\n";
						  cout << "!           " << "             Best of luck!                             !\n";
						  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
					  }
				  }
				  break;
		}
		case 2:
		{
				  system("color 40");
				  system("cls");
				  cout << "rules";
				  cout << "\t\t\t1) There is a hidden word you required to guess the right option \n";
				  cout << "\t\t\t2) If you guess the right option you will get 10 marks on each guess\n";
				  cout << "\t\t\t3) If your guess ord is wrong the score decreases by 10\n";
				  cout << "\t\t\t4) You have total 7 lives when your wrong guesse are become equal to lives you may loss your game\n";

				  break;
		}
		case 3:
		{
				  system("color 42");
				  system("cls");
				  exit(0);
				  break;
		}
		default:
			break;
	}

}
