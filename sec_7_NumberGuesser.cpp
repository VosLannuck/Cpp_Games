#include <cmath>
#include<iostream>
#include <random>
/*
 *
 *	Create a program called number guesser --> DONE
 *	There will be a secret number that is set at the start of the program without any user input 
 *The Secret number should be picked from a certain range --> DONE
 *The range of the number should be output to the player --> DONE
 * the prompt should show how many guesses the player has left -->  DONE
 * The player enter his guess --> DONE
 * If the player guess is too high then the game will output that the guess was too high --> DONE
 * If the player guess is too low then the game will output the guess was too low -->DONE
 * The player only has a certain number of guesses --> DONE
 * The number of guesses should be based on the range of the secret number --> 
 * Any wrong guess will decrement the number of guesses left --> DONE
 * THe game ends by saying what the secret number was regardless of if the player guessed the right number
 * When the game is over, the player should be prompted if he would like to play again
 * If yes then the secret number should change
 * Any input Errors by the player should have proper handling
 *
 *
 *
 *	do {
 *
 *		Play The Game ;
 *
 *	}while( Want to play again)
 *
 *	Play the Game: 
 *		1. set the secret number 
 *		2. set the secret number range
 *		3. prompt the secret number to userdr
 *		4. set the number of guesses
 *		
 *		do {
 *			5. Prompt the user to make a guess ('Output the number of guesses left')
 *			6. Get the guees from the user
 *			7. Check the condition of the guess
 *				7a. if the guess is not equal to the secret number then 
 *					7a1. decrement the number of guess
 *					7a2. check if it was higher or lower than the secret number
 *						7a2a. if it was higher -> print (the guess was too high)
 *						7a2b. if it was lower -> print ( the guess was too low ) 
 *		}while(is not game over)
 *		
 *		Display the result -> tell the player if he got it or not
 *
 *
 *
 *
 *
 * */
const int LOWER_BOUND = 0;
const int UPPER_BOUND = 100;
const int IGNORE_CHARS = 256;

bool WantToPlayAgain();
void PlayTheGame();
int GetRandomNumber();
int CalculateNumberOfGuesses();
int GetGuess(int numberOfTries);
bool IsGameOver(int guess, int secretNumber, int numberOfTries);
void DisplayResult(int secretNumber, int numberOfTries);

int main() 
{
	do {
		PlayTheGame();
	} while(WantToPlayAgain());
	return 0;
}

void PlayTheGame() {
	int secretNumber { GetRandomNumber() };
	std::cout<<"In case debugging: " << secretNumber <<std::endl;
	int numberOfTries { CalculateNumberOfGuesses() } ;
	int guess { 0 }; 
	std::cout<< "The Secret number has been set, range of number : "<< LOWER_BOUND << " to " << UPPER_BOUND << std::endl;
	std::cout<<"Have fun playing ! "<<std::endl;
	do {
		guess = GetGuess(numberOfTries);
		if(guess != secretNumber) {
			numberOfTries --;

			if(guess > secretNumber) {
				std::cout<< "The guess was too high"  <<std::endl;
			}

			else {
				std::cout<< "The guess was too low" <<std::endl;
			}

		}

	}while(!IsGameOver(guess, secretNumber, numberOfTries));

	DisplayResult(secretNumber, numberOfTries);
}

void DisplayResult(int secretNumber, int numberOftries) {
	if(numberOftries > 0 ) {
		std::cout << "You got it : "<< secretNumber<<std::endl;
	}
	else {
		std::cout<< "You didnt get it.. "<<secretNumber<<std::endl; 
	}
}
int CalculateNumberOfGuesses() {
	return std::ceil(std::log2(UPPER_BOUND));
}

int GetGuess(int numberOfTries) {
	int guess  { 0 };
	bool isFailure { true };
	do {

		isFailure = false;
		std::cout<<"Please enter your guess-> ( Number of tries: "<<numberOfTries<<" )"<<std::endl;
		std::cin>>guess;

		if(std::cin.fail()) 
		{
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS,'\n');
			std::cout<<"Please enter integer only broo"<<std::endl;
			isFailure = true;
		}

	}while(isFailure);

	return guess;
}
int GetRandomNumber() {
	std::random_device rd;
	std::mt19937 generator{ rd() };

	std::uniform_int_distribution<int> distribution(LOWER_BOUND, UPPER_BOUND);
	
	return distribution(generator);

}
bool IsGameOver(int guess, int secretNumber, int numberOfTries ) {
	return (guess == secretNumber || numberOfTries == 0);
}

bool WantToPlayAgain() {
	
	char input { 'n' };
	bool isNotCorrectChar { false };

	do {
		isNotCorrectChar = false;
		std::cout<<"Would you like to play again ? (y/n) \n";
		std::cin>> input;

		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			isNotCorrectChar = true;
		}

	}while(isNotCorrectChar);
	std::cin.clear();
	return input == 'y';
}






