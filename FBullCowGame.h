#pragma once
#include<string>

using Fstring = std::string;
using int32 = int;

//All values intialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};




class FbullCowGame
{
public:
	FbullCowGame();//constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(Fstring) const;

	void Reset();// TODO make a more rich return value
	FBullCowCount SubmitValidGuess(Fstring);







	//^^  Please try and ignore this and focus on the interface above
private:
	//See Constructor for Initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	Fstring MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(Fstring) const;
};
