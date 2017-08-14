#include "FBullCowGame.h"

using int32 = int;

FbullCowGame::FbullCowGame() { Reset(); }

int32 FbullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FbullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FbullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FbullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const Fstring HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FbullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FbullCowGame::CheckGuessValidity(Fstring Guess) const
{
	if (false)   //if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)  //if the guess isn't all lower case
	{
		return EGuessStatus::Not_Lowercase;
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
FBullCowCount FbullCowGame::SubmitGuess(Fstring Guess)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;

	//Loop through all the letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 MHWchar = 0; MHWchar < HiddenWordLength; MHWchar++)
	{
		//compare letters against the hidden word
		for (int32 Gchar = 0; Gchar < HiddenWordLength; Gchar++)
		{
			//If they match then
			if (Guess[MHWchar] == MyHiddenWord[MHWchar])
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
	return BullCowCount;
}
