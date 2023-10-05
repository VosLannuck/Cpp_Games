#include<iostream>
/*
 *
 *
 * The game of 8 is played by 2 players. The game starts with the initial number 8 (from here on refered to as the initial number). The first player will choose a number from 1 to 3 (from here on refered to as the chosen number). If the player inputs something outside of the 1 to 3 range it should be an error and the player must choose again. The initial number is subtracted by the chosen number. Then the next player's turn happens. The next player cannot choose the number that the last player chose. If the initial number goes to 0 on your turn, then you win. Otherwise if the number goes below 0, your opponent wins. The player should always see what choices are available to him when prompted to enter his choice. After the game is over, the user should be prompted whether they want to play again.

Write a program to solve this problem. 

Pseudo code : 
	1. Set the initialNumber { 8 }
	2. Set turn counters;
	2. Get input from the player 1 
		2.1 if the first turn, ignore the previous player number
		else
			2.1a Check if it is in range ( 1 - 3 and its not same as previous player number)
	3. Get input from the player 2 
		3.1 Check if it is in range ( 1 - 3 and its not same as previous player number)
 *
 * Check the final condition ( who is the first player get zero ) 
 * */

const int LOWER_BOUND = 1;
const int UPPER_BOUND = 3;
bool WantToPlayAgain();
void PlayTheGame();
int GetInputFromPlayer(int turn, int second_player_number = 0 );
void Display(int player_1_number, int player_2_number);

int main() {

	do {
	PlayTheGame();
}while(WantToPlayAgain());

	return 0;
}

bool WantToPlayAgain() {
	char input { 'n' };
	bool isCorrectChar {true};

	do {
		isCorrectChar = true;

		std::cout<<"Would you like to play again ? \n";
		std::cin>>input;

		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			isCorrectChar = false;
		}

	}while(!isCorrectChar);

	return input =='y';
}

int GetInputFromPlayer( int turn, int second_player_number ) {

	bool correctValue = { false };
	int input = { 0 };

	do {
		std::cout<<"Enter your number from 1 to 3 except "<< second_player_number <<std::endl;
		std::cin>>input;
		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout<<"Only integer 1 - 3 "<<std::endl;
			continue;
		}

		if( ( input >= LOWER_BOUND && input <= UPPER_BOUND)) {
			if( turn == 0) {
				correctValue = true;
			} 
			else if( turn > 0 && second_player_number != input) {
				correctValue = true;
			}else {
				std::cout<<"Your number should not same as the previous opponent number"<<std::endl;
			}
		}else {
			std::cout<<"Either your number is above or lower from the range \n";
		}

	}while(!correctValue);

	return input;

}
void PlayTheGame() {
	int player_1_number { 8 };
	int player_2_number { 8 };
	int turns_counter { 0 };
	int previousPlayerInput { 0 };
	bool player_turn { true } ;
	bool isPlayerWinning { false };
	do {

		if(player_turn) {
			std::cout<<"\nYour Turn #Player 1 : "<<player_1_number<<std::endl;
			previousPlayerInput = GetInputFromPlayer(turns_counter, previousPlayerInput);
			player_1_number -= previousPlayerInput;
			turns_counter ++;
			player_turn = !player_turn;
			if(player_1_number == 0) {
				isPlayerWinning = true;
			}
			else if (player_1_number < 0) {
				isPlayerWinning = true;
			}
		}
		else {
			std::cout<<"\nYour Turn #Player 2 : "<<player_2_number<<std::endl;
			previousPlayerInput = GetInputFromPlayer(turns_counter, previousPlayerInput);
			player_2_number -= previousPlayerInput;
			turns_counter ++;
			player_turn = !player_turn;
			if(player_2_number == 0) {
				isPlayerWinning = true;
			}
			else if (player_2_number < 0) {
				isPlayerWinning = true;
			}
		}

	}while(!isPlayerWinning);

	Display(player_1_number, player_2_number);
}


void Display(int player_1_number, int player_2_number) {
	std::cout<<player_1_number<< " " << player_2_number<<std::endl;
	if(player_1_number == 0 || player_2_number < 0 ) {
		std::cout<< "Player 1 Won "<<std::endl;
	}
	else {
		std::cout<< "Player 2 Won " << std::endl;
	}

}
