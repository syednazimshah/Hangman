#include<iostream> // Syed Nazim Shah 2019504
#include<time.h> // for time
#include <stdlib.h> // for rand, srand
using namespace std; 

void hangman(); // function prototype
int charcount(const char* x); // function prototype
void game(const char* y); // function prototype

int charcount(const char* x) // counting characters in a country's name
{
	int count = 0;
	while (*x != '\0')
	{
		x++;
		count++;
	}
	return count;
}
void game(const char* y) // This is the main game and print function where everything happens
{
	int size = charcount(y); // getting number of characters in a country's name
	char temparr[10];// creating a temporary character array of size 10
	int loopcount = 0; // loopcheck is used to check if the word that user entered matches any letter of the country name and counts it
	int wrngcount = 0; // it counts when the word user entered does not match any character

	for (int i = 0; i < size; i++) // fills the tempstr with dashes and prints it separately
	{
		temparr[i] = '_';
		cout << "_ ";
	}
	for (int loop = 0; loop < 8;)// this loop runs if user makes 8 mistakes during game
	{
		int wrngcheck = 0; // this is a check variable to check for right and wrong answers
		char guess; // this is an input character variable that user will enter 

		cout << "\nGuess any Letter of the Country's Name: ";
		cin >> guess; // taking input from user 
		for (int i = 0; i < size; i++)// this is the loop that compares the input letter with the characters of the country name
		{
			if (guess == y[i] && temparr[i] == '_') // if statment to check variable and vheck tempstr if any value is already in there
			{
				temparr[i] = guess;       // writing the tempstr character string
				loopcount++; // the loopcount counts the time this loop has run
				wrngcheck = 1;// if any letter matches the check is turned true(value set to 1) 
			}
			else;
		} // letter check loop ends here

		if (wrngcheck == 0) // 
		{
			wrngcount++; //if letter doesnt match, it increses the wrong count
			loop++;// and it also increases the loop
		}
		else;
		system("CLS"); // clearing screen
		for (int i = 0; i < size; i++)
		{
			cout << temparr[i] << " "; // printing the temporary character string with the modified values in it
		}
        if (wrngcount == 8) // hangman displaying code from here below. it shows the character based on the value of wrong choices counter 
		{
           cout << endl << endl<< endl
				<< "     ('')   " << endl
				<< "     _||_/  " << endl
				<< "    / ||    " << endl
				<< "    _/  L_  " << endl
				<< "==============" << endl << endl
				<< "NO MORE CHANCES! YOU ARE DEAD!" << endl;
		}
		else if (wrngcount == 7)
		{
			cout << endl << endl<< endl
				<< "     ('') " << endl
				<< "     _||_/" << endl
				<< "    / ||  " << endl
				<< "    _/    " << endl<< endl<< "==============" << endl << endl;
			cout << "\n\nWrong!! 1 Chance Left! Try Again\n";
		}
		else if (wrngcount == 6)
		{
			cout << endl << endl<< endl
				<< "     ('') " << endl
				<< "     _||_/" << endl
				<< "    / ||  " << endl<< endl<< endl<< "==============" << endl << endl;
			cout << "\n\nWrong!! 2 Chance Left! Try Again\n";
		}
		else if (wrngcount == 5)
		{
			cout << endl << endl<< endl
				<< "     ('') " << endl
				<< "     _||_/" << endl
				<< "    /     " << endl<< endl<< endl<< "==============" << endl << endl;
			cout << "\n\nWrong!! 3 Chance Left! Try Again\n";
		}
		else if (wrngcount == 4)
		{
			cout << endl << endl<< endl
				<< "     ('')     " << endl
				<< "     _||      " << endl
				<< "    /         " << endl<< endl<< endl<< "==============" << endl << endl;
			cout << "\n\nWrong!! 4 Chance Left! Try Again\n";
		}
		else if (wrngcount == 3)
		{
			cout << endl << endl<< endl
		        << "     ('') " << endl
				<< "      ||  " << endl<< endl<< endl<< endl<< "==============" << endl << endl;
			cout << "\n\nWrong!! 5 Chance Left! Try Again\n";
		}
		else if (wrngcount == 2)
		{
			cout << endl << endl<< endl<< "     ('') " << endl<< endl<< endl<< endl<< endl<< "==============" << endl << endl;
			cout << "\n\nWrong!! 6 Chance Left! Try Again\n";
		}
		else if (wrngcount == 1)
		{
			cout << endl << endl<< endl<< "     ('   " << endl<< endl<< endl<< endl<< endl<< "==============" << endl << endl;
			cout << "\n\nWrong! 7 Chance Left! Try Again\n";
		}
		else
		{
			cout << "\n\n8 Chances Left!";
		} // hangman cartoon printing stops here
		if (loopcount == size || loop == 8) // if game correct choices reach country name's character limit or game wrong choices reach limit 8. loop will teerminate 
		{
			if (loopcount == size)// checking if user entered all correct characters before limit reached and print win messege
				cout << "\n\nYOU WIN";
			else // otherwise it will print the lost messege and shows the correct answer
			{
				cout << "\n\nYOU LOSE";
				cout << "\n\nCorrect Answer is " << y;
			}
			cout << "\n\n***GAMEOVER***"; // printing game over and breaking loop if either of the above condition is satisfied
			break;
		}
	}
	int select = 0; // declaring another variable for user choice and using it to call the game again if user wants to play again otherwise it exits the game
	cout << "\n\nDo You want to play again!(0 for no): ";
	cin >> select;
	if (select == 0)
		cout << "\n\nEXITING GAME\n\n";
	else {
		system("CLS"); // clears the screen before game restarts
		hangman();
	}
}

void hangman()
{
	const char* china = "china"; // declaring five countries as shown below
	const char* pak = "pakistan";
	const char* turk = "turkey";
	const char* india = "india";
	const char* japan = "japan";
	srand((unsigned int) time(0)); // calling random funtion to choose any number between 1 and 5
	int n = rand() % 5 + 1;

	if (n == 1) // assigning numbers to countries calling the game function by passing country names pointer to the game function
		game(pak);
	else if (n == 2)
		game(japan);
	else if (n == 3)
		game(turk);
	else if (n == 4)
		game(china);
	else if (n == 5)
		game(india);
	else;
	cout << "\n";
}

int main()
{
	cout << "***WELCOME TO HANG THE MAN GAME***\n\n"; // displaying main screen and rules
	cout << "Rules\n\n1.Use lower case letters only\n2.You have only 8 wrong choice limit\n3.One letter once used cannot be used later as you will end up using your Wrong choices\n\n";
	hangman(); // calling the main function
} 
