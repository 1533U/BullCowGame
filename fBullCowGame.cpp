#include "fBullCowGame.h"

using int32 = int;


fBullCowGame::fBullCowGame()
{
	Reset();
}

int32 fBullCowGame::GetMaxTries() const { return MyMaxTry; }
int32 fBullCowGame::GetCurrentTry() const { return MycurrentTry; }

void fBullCowGame::Reset()
{
	constexpr int32 Maxtries = 8;
	MycurrentTry = 1;
	MyMaxTry = Maxtries;
	const Fstring	HidenWord = "plant";
	MyHiddenWord = HidenWord;

	return;
}


bool fBullCowGame::IsGameWon()const{return bGameiswon;}

int32 fBullCowGame::GetHiddenWordLenght() const
{

	return MyHiddenWord.length();
}

EWordStatus fBullCowGame::CheckGuessValidity(Fstring Guess)const

{
	int32 lower = 0;
	for (int32 i = 0; i < Guess.length(); i++)
	{
		
			if (1== isupper(Guess[i]))
			{
				lower = 1;
				
			}

	}

	int32 isograme = 0;
	for (int32 i = 0; i < Guess.length(); i++)
	{
		for (int32 j = 0; j < Guess.length(); j++)
		{
			if (Guess[i]==Guess[j])
			{
				isograme++;

			}

		}

	}

	
	if (isograme>Guess.length())
	{
		

		return EWordStatus::Not_Isogram;
	}
	else if (lower==1)
	{
		return EWordStatus::NOT_Lowercase;
	}
	else if (GetHiddenWordLenght() != Guess.length())
	{

		return EWordStatus::Wrong_Lenght;
	}
	else
	{
		return EWordStatus::OK;
	}
	

}

//res=ieb=ve valid geuss, incremetns turn
FBullCowCount fBullCowGame::SubmitGuess(Fstring Guess)
{

	//increment the returnnumber
	MycurrentTry++;
	//setup a return valie
	FBullCowCount BullCowCount;

	int32 HiddenwordLenght = GetHiddenWordLenght();

	for (int32 i = 0; i < HiddenwordLenght; i++)
	{


		if (Guess[i]==MyHiddenWord[i])
		{
			BullCowCount.Bulls++;

		}
		else
		{
			for (int32 j = 0; j < HiddenwordLenght; j++)
			{
				if (Guess[i]==MyHiddenWord[j])
				{

					BullCowCount.Cows++;

				}

			}

		}


	}

	//loop through all leters in the guess
		//compare letter against the word
	if (BullCowCount.Bulls == HiddenwordLenght)
	{
		bGameiswon = true;
	}
	else
	{
		bGameiswon = false;
	}
	return BullCowCount;
}
