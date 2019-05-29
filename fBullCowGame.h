#pragma once
#include <string>


using Fstring = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;


};


enum class EWordStatus
{
	OK,
	Not_Isogram,
	Wrong_Lenght,
	NOT_Lowercase,
	Invalid_status

};

class fBullCowGame
{
public:

	fBullCowGame();//constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLenght()const;

	void Reset();//better return.
	EWordStatus CheckGuessValidity(Fstring) const;

	//provide c,b increase tries number
	FBullCowCount SubmitGuess(Fstring);




	//ingnore
private:
	//see construc
	int32 MycurrentTry;
	int32 MyMaxTry;
	Fstring  MyHiddenWord;
	bool bGameiswon = false;

};

