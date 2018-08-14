#include <iostream>
#include <string>
#include "FBullCowGame.h"

constexpr int WORD_LENGTH = 7;

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//The entry point to the game
int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PlayGame() {
	int MaxTries = BCGame.GetMaxTries();

	//Loop for the number of turns asking for guesses
	for (int i = 0; i <= MaxTries; i++) {
		//Prompt the player for a guess and then repeats it back
		std::string Guess = GetGuess();
		//Prints back their guess
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

void PrintIntro() {
	//Introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	//Takes their guess
	std::cout << "Try " << CurrentTry << ". Enter your guess here: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "You wanna play again? (Y/N)";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}
