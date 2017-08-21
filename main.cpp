/*
This is a console executable, that makes use of the bullcow class
This acts as the view in MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowgame class.
*/



#include <iostream>
#include <string>
#include "FBullCowGame.h"


using Ftext = std::string;
using int32 = int;

void printintro();
void playgame();
Ftext getvalidguess();
bool asktoplayagain();

FbullCowGame BCgame;// Instantiate a new game

//The entry point for our application
int main()
{
	std::cout << BCgame.GetCurrentTry();
	bool bplayagain = false;

	do
	{
		printintro();
		playgame();
		bplayagain = asktoplayagain();
	} while (bplayagain);

	return 0;//Exit the application
}


void printintro()
{
	// Introduce the Game

	std::cout << "Welcome to Bulls and Cows,a fun word game\n";
	std::cout << "Can you Guess the " << BCgame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void playgame()
{
	BCgame.Reset();
	int32 MaxTries = BCgame.GetMaxTries();

	//Loop for the number of turns asking for guess
	for (int32 count = 1; count <= MaxTries; count++)    //TODO change from FOR to WHILE
	{
		Ftext Guess = getvalidguess(); //TODO make loop checking valid


		//Submit valid guess to the game adn receive counts
		FBullCowCount BullCowCount = BCgame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "  Cows = " << BullCowCount.Cows << "\n\n";
	}

	//TODO summarise game
}


// Loop continually untill the user gives a valid guess
Ftext getvalidguess()
{
	EGuessStatus status = EGuessStatus::Invalid_Status;
	do {
		// Get a Guess from the player
		int32 CurrentTry = BCgame.GetCurrentTry();
		Ftext Guess = "";
		std::cout << "Try " << CurrentTry << ".Guess any word:";
		std::getline(std::cin, Guess);

		status = BCgame.CheckGuessValidity(Guess);

		switch (status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "please enter a " << BCgame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "please enter all lower case letters.\n";
			break;
		default:
			return Guess;
			break;
		}std::cout << std::endl;
	} while (status != EGuessStatus::OK);
}


bool asktoplayagain()
{
	std::cout << "Do you want to play again? (y/n)";
	Ftext response = "";
	std::getline(std::cin, response);
	return (response[0] == 'y') || (response[0] == 'Y');
}
