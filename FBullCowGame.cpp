#include "FBullCowGame.h"
#include "map"
#define Tmap std::map

using int32 = int;

FbullCowGame::FbullCowGame() { Reset(); }

int32 FbullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FbullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FbullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FbullCowGame::IsGameWon() const { return bGameIsWon; }

void FbullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const Fstring HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FbullCowGame::CheckGuessValidity(Fstring Guess) const
{
	if (!IsIsogram(Guess))   //if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)  //if the guess isn't all lower case
	{
		return EGuessStatus::Not_Lowercase;//TODO write function 
	}
	else if (Guess.length() != GetHiddenWordLength()) // If the Guess Length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		EGuessStatus::OK;
	}
}

//receives a VALID guess, increments turn and returns count
FBullCowCount FbullCowGame::SubmitValidGuess(Fstring Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming same length as guess
	//Loop through all the letters in the hidden word


	for (int32 MHWchar = 0; MHWchar < WordLength; MHWchar++)
	{
		//compare letters against the guess
		for (int32 Gchar = 0; Gchar < WordLength; Gchar++)
		{
			//If they match then
			if (Guess[Gchar] == MyHiddenWord[MHWchar])
			{
				if (MHWchar == Gchar) //if they are in the same place
				{
					BullCowCount.Bulls++; //Increment bulls
				}
				else
				{
					BullCowCount.Cows++; //Must be a cow
				}

			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FbullCowGame::IsIsogram(Fstring Word) const
{
	//Treat 0 and 1 letter words as Isograms
	if (Word.length() <= 1) { return true; }
	Tmap<char, bool> LetterSeen; //Setup our map
	for (auto Letter : Word)   //For all letters of the Word
	{
		Letter = tolower(Letter); //Handle mixed case
		//Loop through all the letters of the word
		//If the letter is in the map	
		//We dont have an Isogram
		//Otherwise 
		//Add the letter to the map as seen
	}
	return true; //For example in cases where /0 is entered
}
