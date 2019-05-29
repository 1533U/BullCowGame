/*This is the console exe., use of bullcow class acting like view mvc paattern,
responsible for all user interactio. for game ogic

*/

#include <iostream>
#include <string>
#include "fBullCowGame.h"


using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext guessatempt();
void Printgamesummary();
bool Asktoplayagain();

fBullCowGame BCGame;

//application entry
int main()
{

	
	do
	{
	PrintIntro();//intro welcome
	PlayGame();//run game
	
	} while (Asktoplayagain() == true);
	
	return 0;//end
}
void PrintIntro()
{

	//introduce game
	

	int32 WordLength = BCGame.GetHiddenWordLenght();

	std::cout << "Welcome to Bull and Cow Game, not so fun game\n";
	printf("Can you guess the %d letter isogram I'm thinking of?\n\n", WordLength);
	return;
}
void PlayGame()
{

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	//loop for difficulty
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{


		Fstring Guess = guessatempt();

	}
	Printgamesummary();
	return;
	
	//todo summirse the game

}
Ftext guessatempt()
{
	EWordStatus Status = EWordStatus::Invalid_status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
	Ftext Guess = "";
	std::cout << " please type your one word answer, Try "<<CurrentTry<<"\n";
	std::getline(std::cin, Guess);//todo make loop checkingvalid
	
	EWordStatus Status = BCGame.CheckGuessValidity(Guess);
	
		switch (Status)
		{
		case EWordStatus::Not_Isogram:
			std::cout << "\n The word was not a Isogram";
			break;
		case EWordStatus::Wrong_Lenght:
			std::cout << "\n The word was not the right word lenght of "<< BCGame.GetHiddenWordLenght();
			break;
		case EWordStatus::NOT_Lowercase:
			std::cout << "\n The word was not in lowercase";
			break;
		default:
			std::cout << "Your answer was: " << Guess << std::endl;
			std::cout << "\n";
			FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << "Cows = " << BullCowCount.Cows;

			return Guess;
			break;
		}
	} while (Status != EWordStatus::OK);
	


	//sumit
	//print number of bulls and cows


	
}
bool Asktoplayagain() 
{
	Ftext Response = "";

	std::cout << "do you want to play again? Y for yes or N for no\n";
	std::getline(std::cin, Response);
	if (Response[0] == 'y')
	{
		return true;
	}
	if (Response[0] == 'n')
	{

		return false;
	}
	else
	{
		Asktoplayagain();
	}


}
void Printgamesummary() {

	if (BCGame.IsGameWon()) {

		std::cout << "\nWELL DONE - YOU WIN!!\n";
	}
	else
	{
		std::cout << "\nBETTER LUCK NEXT TIME - YOU LOSE\n";
	}
}