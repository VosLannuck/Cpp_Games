#include<iostream>
#include<cstring>
#include<cctype>
#include <string>
/*
 * Tic Tac Toe
------------

Write the game of Tic Tac Toe. It's a game with a 3 by 3 grid played by 2 players. One player places O markers and the other player places X markers. Each player takes turns placing his/her marker in order to get 3 of their markers to line up on the board. A player wins when 3 or their markers line up either horizontally, vertically or diagonally. If no player has their markers line up in that fashion, and the board is full, then the game is called a "Cat Game". Your program should output the winner of the game or "Cat Game" if there was no winner. The user should be prompted if they would like to play again when the game is over. If they choose to play again, the player who started second last game should go first. 
 *
 * */

/*
 *		
 *
 * do {
 *
 *	PlayGame();
 *
 * }while(!PlayAgain())
 *
 *
 * PlayGame() : void {
 *	
 *	bool playerTurn { true };
 *	const char * noptrTicTacToe = MakeTicTacToe();
 *	const char markers = { 'O', 'X' };
 *
 *	Drawboard();
 *
 *	do {
 *
 *		Drawboard(const char * noptrTicTacToe);
 *
 *		int playerInput = GetPlayerInput(const bool playerTurn, const char * noptrTicTacToe, const char markers,);	
 *		
 *		Updateboard(int playerInput, bool & playerTurn, char * noptrTicTacToe);
 *
 *
 *	}while(!IsGameOver())
 *	
 * }
 *
 * GetPlayerInput(const bool playerTurn, const char * noptrTicTacToe, const char markers) : Int {
 *	
 *	char input; 
 *	bool isValid  {false};
 *	do {
 *
 *		isValid = true;
 *		input = GetCharacter():
 *		isValid = IsValidTicTacToeInput(input, noptrTicTacToe);
 *
 *	}while(!isValid);
 *	
 *	return input;
 * }
 *
 * IsValidTicTacToeInput(char input, const char * noptrTicTacToe) : bool {
 *		int inputInt = castToInt(input);
 *		isValid  = false; 
 *		
 *		if(inputInt >= 0 && inputInt < 9 ) {
					isValid = noptrTicTacToe[inputInt] == '-';
 *		}
 *
 *		return isValid;
 * }
 *	
 *	Drawboard(const char * noptrTicTacToe) : void {
 *	// Drawboard based the noPtrTicTacToe

			//use ptr indexes
			std::cout<<"+---+---+---+"<<std::endl;
			std::cout<<"| 0 | 1 | 2 |"<<std::endl;
			std::cout<<"+---+---+---+"<<std::endl;
			std::cout<<"| 3 | 4 | 5 |"<<std::endl;
			std::cout<<"+---+---+---+"<<std::endl;
			std::cout<<"| 6 | 7 | 8 |"<<std::endl;
			std::cout<<"+---+---+---+"<<std::endl;

 *	}
 *
 *
 *
 *	Updateboard(int playerInput, bool & playerTurn, char * noptrTicTacToe) {
 *			
 *			noptrTicTacToe[playerInput] = GetPlayerTurnMarker(playerTurn);
 *			playerTurn = !playerTurn;
 *	}
 *
 *	GetPlayerTurnMarker(bool playerTurn) : char {
 *		return if(playerTurn) ? 'O' : 'X'
 *	}
 *
 * */

char GetCharacter(const char * prompt, const char * error);
char GetCharacter(const char * prompt, const char * error, const char validationInput[], int validationInputLength);
bool PlayAgain();
void PlayGame();
char * MakeTicTacToeIdentifier();
bool IsGameOver(const char * noptrTicTacToe, int numberTries);
int GetPlayerInput(const bool playerTurn, const char * noptrTicTacToe, const char markers[], int ticTacToeLength);
bool IsValidTicTacToeInput( const char input ,const char * noptrTicTacToe) ;
int CharToInt(char ch);
void Drawboard(const char * noptrTicTacToe);
void Updateboard(int input, bool & playerTurn, char * noptrTicTacToe, int numberTries);
char GetPlayerMarkers(const bool playerTurn) ;
bool IsWinning(int firstBox, int secondBox, int thirdBox);
void DisplayResult(const bool playerTurn, const int numberTries);



const int IGNORE_CHARS { 256 } ;
const char MARKERS[] {'O', 'X'};
const int MARKERS_LENGTH { 2 } ;
const int TIC_TAC_TOE_SIZE { 3 };
const char INPUT_RANGE[] {'0', '1', '2', '3', '4', '5', '6' ,'7' ,'8'} ;
const int INPUT_RANGE_LENGTH { 9 };
const int NUMBER_TRIES { 9 }; 

int main() {

	do {
		PlayGame();
	}while(!PlayAgain());

	return 0;
}

char GetCharacter(const char * prompt, const char * error ) {

	char input;
	bool isValid { false };

	do {

		std::cout<<prompt;
		std::cin>>input;
		isValid = true;

		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout<<error<<std::endl;

			isValid = false;
		}
	}while(!isValid);

	return input;

}

char GetCharacter(const char * prompt, const char * error, const char validationInput[], int validationInputLength) {

	char input;
	bool isValid { false };

	do {

		std::cout<<prompt;
		std::cin>>input;

		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout<<error<<std::endl;

			isValid = false;
		}
		else {

			if(std::isalpha(input)) 
				input = std::tolower(input);

			for(int i =0; i < validationInputLength ; ++i) {
				if(validationInput[i] == input)  {
					isValid = true;
					break;
				}
			}
		}

	}while(!isValid);

	return input;
}

void Drawboard(const char * noptrTicTacToe) {

	std::cout<<"+---+---+---+"<<std::endl;
	std::cout<<"| "<< noptrTicTacToe[0]<< " | " << noptrTicTacToe[1]<< " | " << noptrTicTacToe[2]<< " |"<<std::endl;
	std::cout<<"+---+---+---+"<<std::endl;
	std::cout<<"| "<< noptrTicTacToe[3]<< " | " << noptrTicTacToe[4]<< " | " << noptrTicTacToe[5]<< " |"<<std::endl;
	std::cout<<"+---+---+---+"<<std::endl;
	std::cout<<"| "<< noptrTicTacToe[6]<< " | " << noptrTicTacToe[7]<< " | " << noptrTicTacToe[8]<< " |"<<std::endl;
	std::cout<<"+---+---+---+"<<std::endl;
}

void PlayGame() {
	bool playerTurn { true };

	char * optrTicTacToe = MakeTicTacToeIdentifier();
	int numberTries = NUMBER_TRIES;
	Drawboard(optrTicTacToe);

	do {
		int playerInput = GetPlayerInput(playerTurn, optrTicTacToe, MARKERS, MARKERS_LENGTH);
		Updateboard(playerInput, playerTurn, optrTicTacToe, numberTries);
		Drawboard(optrTicTacToe);

	}while(!IsGameOver(optrTicTacToe, numberTries));

	DisplayResult(!playerTurn, numberTries);
}

void DisplayResult(const bool playerTurn, const int numberTries) {

	if(numberTries > 0) {
		if(playerTurn) {
			std::cout<<"Congratulations player 1 you WON the game\n";
		}	
		else {

			std::cout<<"Congratulations player 2 you WON the game\n";
		}
	}
	else {
		std::cout<<"NO one win this rounds RIP\n";
	}

}
int GetPlayerInput(const bool playerTurn, const char * noptrTicTacToe, const char markers[], int ticTacToeLength) {
	bool isValid { false };
	char input;
	do {
		input = GetCharacter("Please Enter the index 0 - 9 ", "Please try another index", INPUT_RANGE, INPUT_RANGE_LENGTH);
		isValid = IsValidTicTacToeInput(input, noptrTicTacToe);
		if(!isValid) {
			std::cout<<"Please input another index"<<std::endl;
		}
	}while(!isValid);

	return input - '0';
}

int CharToInt(char ch) {
	return ch - '0';
}
bool IsValidTicTacToeInput(const char input, const char * noptrTicTacToe) {
	int intChar = CharToInt(input);
	bool isValid { false };
	if( (intChar >= 0 && intChar < 9) && noptrTicTacToe[intChar] == '-') {
		isValid = true;
	}
	return isValid;
}


bool IsGameOver(const char * noptrTicTacToe, int numberTries) {

	bool isGameOver = false;
	if(IsWinning(noptrTicTacToe[0], noptrTicTacToe[1], noptrTicTacToe[2])) {

		isGameOver = true;
	} 

	else if(IsWinning(noptrTicTacToe[0], noptrTicTacToe[3], noptrTicTacToe[6])){

		isGameOver = true;

	} 

	else if(IsWinning(noptrTicTacToe[1], noptrTicTacToe[4], noptrTicTacToe[7])) {
		
		isGameOver =true;

	} 

	else if(IsWinning(noptrTicTacToe[2], noptrTicTacToe[5], noptrTicTacToe[8])) {

		isGameOver =true;

	}

	else if(IsWinning(noptrTicTacToe[3], noptrTicTacToe[4], noptrTicTacToe[5])) { // ROW 2

		isGameOver =true;
	} 

	else if(IsWinning(noptrTicTacToe[6] ,noptrTicTacToe[7], noptrTicTacToe[8])) { // ROW 3
		isGameOver = true;

	}
	
	else if(IsWinning(noptrTicTacToe[2], noptrTicTacToe[4], noptrTicTacToe[6])) {
		isGameOver = true;
	}
	else if(IsWinning(noptrTicTacToe[0], noptrTicTacToe[4], noptrTicTacToe[8])) {
		isGameOver = true;
	}

	return isGameOver || numberTries == 0;
}

char * MakeTicTacToeIdentifier() {

	char * ticTacToe = new char[TIC_TAC_TOE_SIZE * TIC_TAC_TOE_SIZE];

	for( int i =0 ; i < TIC_TAC_TOE_SIZE * TIC_TAC_TOE_SIZE; i++) {
		ticTacToe[i] = '-';
	}

	return ticTacToe;
}
char GetPlayerMarkers(const bool playerTurn) {
	if(playerTurn) {
		return MARKERS[0];
	}
	return MARKERS[1];
}
void Updateboard(int input, bool & playerTurn,char * noptrTicTacToe, int numberTries){
	char marker = GetPlayerMarkers(playerTurn);
	noptrTicTacToe[input] = marker;
	numberTries --;
	playerTurn = !playerTurn;
}

bool IsWinning(int firstBox, int secondBox, int thirdBox) {

	bool isWinnerExist { false };
	if(firstBox == 'O' && secondBox == 'O' && thirdBox == 'O') {
		isWinnerExist = true;
	}

	else if(firstBox == 'X' && secondBox == 'X' && thirdBox == 'X' ) {
		isWinnerExist = true;
	}

	return isWinnerExist;
}

bool PlayAgain() {
	char input;

	bool isValid { false };
	const char validInputs[] { 'y', 'n'};
	char character = GetCharacter("Would you like to play again ? (y/n)", "Umm only y / n bro", validInputs, 2);

	return input == 'y';

}
