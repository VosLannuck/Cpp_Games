#include<iostream>
#include<cctype>
#include<cstring>

/*
 * Create the program Hangman. Prompt the player to enter a phrase.
 * That phrase will be hidden by a series of dashes ( excluding spaces ) 
 * The Player can guess the letters. If They guess correctly all the letters that match will be revealed
 * If they guess incorrectly, then 1 more body part will be added to the gallows.
 * If they lose, the gallows should look like this 
 * +---+
 * |   |
 * |   o
 * |  /|\
 * |  / \
 * |
 * -+-
 * If the player loses, the phrase should be revealed
 * After the game is over, the player should be prompted if they want to play again
 *
 * 
 * //
 *	
 * // Step 1 : Bentuk Higher level untuk menyelesaikan problem 
 * 
 * do {
 *
 *	PlayTheGame();
 *
 * }while(IsPlayingAgain())
 *
 *  # Step 2: Mulai perkecil Scope levelnya 
 *	
 *	PlayTheGame : VOID
 *	-----------
 *	// Remember all string using cString style
 *	var secretPhrase : char[]  = GetSecretPhrase();
 *	const char * hiddenPhrase = MakeHiddenPhrase(secretPhrase) ;
 *  var numberOfTries = 6;
 *  Drawboard(numberOfTries);  // For Drawing the hangman and starting information 
 *
 *  do {
 *		var userGuess : char[]= getGuess();
 *		UpdateDrawboard(guess, secretPhrase, hiddenPhrase); // Todo later
 *	
 *	DisplayResult();
 *
 *	# Step 3 : Perkecil Scope fungsi lainnya
 *
 * DrawBoard(numberOfTries : Int, ) : VOID
 * -------------------------------------
 *  when(numberOfTries) {
 *		case 6 -> {
 *			// Draw Fully Hangman
 *		}
 *		...
 *		 // Gradually Decreased the body part
 *
 *		case 0 -> {
 *		... // no body part 
 *		}
 *
 *  }
 *  	
 *  print(total number of tries left ) ;
 *  print(hidden phrase yang berhasil ketebak );
 *
 *	
 *	MakeHiddenPhrase(secretPhrase, secretPhraseLength) : dynamic heap memory
 *  ----------------------------------
 *	int heapHiddenPhrase = new char[secretPhrase];
 *	for (int i = 0 ; i < secretPhraseLength ; ++i ) {
 *		
 *		if(secretPhrase[i] != ' ') {
 *			heapHiddenPhrase = '-';
 *		}
 *		else {
 *			heapHiddenPhrase = ' ';
 *		}
 *
 *	}
 *
 *	return heapHiddenPhrase;
 *
 * */

/*
 * Utils Start
 *
 * */

const char * INPUT_ERROR_STRING {"You cannot do that"};
const int IGNORE_CHARS = 256;

char GetCharacter(const char * prompt, const char * error);
char GetCharacter(const char * prompt, const char * error, const char validInput[], int validInputLength);

/*
 *	Utils End
 *
 * */
bool PlayAgain();
void PlayGame();
int GetSecretPhraseLength(char secretPhrase[], int secret_phrase_max_length);
char * MakeHiddenPhrase(const char secretPhrase[], int secretPhraseLength);
bool IsGameOver(int numberOfTries, const char* noptrHiddenPhrase, int secretPhraseLength );
char GetGuess();
void Drawboard(int numberOfTries, const char * noptrHiddenPhrase);
void UpdateDrawboard(char guess, char * noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int & numberOfTries);
void DisplayResult(int numberOfTries, const char * secretPhrase);
void ClearScreen();




int main() {

	do {
		PlayGame();

	}while(!PlayAgain());

	return 0;
}

/*
 *	Utils Start impl 
 *
 * */

char GetCharacter(const char* prompt, const char* error) {
	const int IGNORE_CHARS = 256;
	char input { '\0' };
	bool isValid { false };

	do {

		isValid = true;

		std::cout<<prompt<<std::endl;
		std::cin>>input;

		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout<<error<<std::endl;
			isValid = false;
		}
		else {

			std::cin.ignore(IGNORE_CHARS, '\n');

			if(std::isalpha(input)) {
				input = tolower(input);
			}
			else {
				std::cout<< error << std::endl;
				isValid = false;
			}
		}

	}while(!isValid);

	return input;
}

char GetCharacter(const char* prompt, const char* error, const char validInput[], int validInputLength ) {
	char input;
	bool isValid { false }; 

	do {
		isValid = true;
		std::cout<<prompt;
		std::cin>>input;

		if(std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore(256, '\n');
			isValid = false;
			std::cout<<error<<std::endl;
		}
		else {
			std::cin.ignore(256, '\n');
			if(std::isalpha(input)) {
	
				input = std::tolower(input);

				for(int i = 0 ; i < validInputLength; ++i) {
					if(input == validInput[i]) {
						return input;
					}
				}
			}
		}

	}while(!isValid);


	return input;
}

/*
 *	Utils Start end 
 *
 * */

bool PlayAgain() {
	const char validInputs[] = {'y', 'n'};
	char response = GetCharacter("Would you like to Play Again? (y/n)", INPUT_ERROR_STRING, validInputs, 2);

	return response != 'y';
}
char GetGuess() {
	return GetCharacter("Please input your guess: ", INPUT_ERROR_STRING);
}
void PlayGame() {

	const int SECRET_PHRASE_MAX_LENGTH = 256;
	int number_of_tries = 6;
	char secretPhrase[SECRET_PHRASE_MAX_LENGTH] {""};  
	int secretPhraseLength = GetSecretPhraseLength(secretPhrase, SECRET_PHRASE_MAX_LENGTH);
	char * optrHiddenPhrase = MakeHiddenPhrase(secretPhrase, secretPhraseLength);

	Drawboard(number_of_tries, optrHiddenPhrase);

	do {
		char userGuess = GetGuess();

		UpdateDrawboard(userGuess, optrHiddenPhrase, secretPhrase, secretPhraseLength, number_of_tries );

		Drawboard(number_of_tries, optrHiddenPhrase);
	}while(!IsGameOver(number_of_tries, optrHiddenPhrase, secretPhraseLength));

	DisplayResult(number_of_tries, secretPhrase);
	delete[] optrHiddenPhrase;
}

bool IsGameOver(int numberOfGuessesLeft, const char * noptrHiddenPhrase, int secretPhraseLength ) {

	bool hasDash { false };


	for(int i =0 ; i < secretPhraseLength; ++i) {

		if(noptrHiddenPhrase[i] == '-') {
			hasDash = true;
		}
	}

	return (numberOfGuessesLeft == 0 || !hasDash);

}
void UpdateDrawboard(char guess, char * noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int & numberOfTries) {

	bool isFound { false };

	for(int i =0 ; i < secretPhraseLength; ++i) {
		if(std::tolower(secretPhrase[i]) == guess) {
			noptrHiddenPhrase[i] = secretPhrase[i];
			isFound = true;
		}
	}
	if(!isFound) {
		numberOfTries -- ;
	}
}


void Drawboard(int numberOfTries, const char * noptrHiddenPhrase) {

	ClearScreen();

	switch(numberOfTries) {
		case 0:{
			std::cout<<" +---+"<<std::endl;
			std::cout<<" |   |"<<std::endl;
			std::cout<<" |   o"<<std::endl;
			std::cout<<" |  /|\\"<<std::endl;
			std::cout<<" |  / \\"<<std::endl;
			std::cout<<"-+-"<<std::endl<<std::endl;;
			}
			break;
		case 1: {

			std::cout<<" +---+"<<std::endl;
			std::cout<<" |   |"<<std::endl;
			std::cout<<" |   o"<<std::endl;
			std::cout<<" |  /|\\"<<std::endl;
			std::cout<<" |  /"<<std::endl;
			std::cout<<"-+-"<<std::endl<<std::endl;;

			}
			break;
		case 2: {

			std::cout<<" +---+"<<std::endl;
			std::cout<<" |   |"<<std::endl;
			std::cout<<" |   o"<<std::endl;
			std::cout<<" |  /|\\"<<std::endl;
			std::cout<<" |  "<<std::endl;
			std::cout<<"-+-"<<std::endl<<std::endl;;
			}
			break;
		case 3: {

			std::cout<<" +---+"<<std::endl;
			std::cout<<" |   |"<<std::endl;
			std::cout<<" |   o"<<std::endl;
			std::cout<<" |  /|"<<std::endl;
			std::cout<<" |  "<<std::endl;
			std::cout<<"-+-"<<std::endl<<std::endl;;
			}
			break;
		case 4: {

			std::cout<<" +---+"<<std::endl;
			std::cout<<" |   |"<<std::endl;
			std::cout<<" |   o"<<std::endl;
			std::cout<<" |  /"<<std::endl;
			std::cout<<" |  "<<std::endl;
			std::cout<<"-+-"<<std::endl<<std::endl;;

			}
			break;
		case 5: {

			std::cout<<" +---+"<<std::endl;
			std::cout<<" |   |"<<std::endl;
			std::cout<<" |   o"<<std::endl;
			std::cout<<" |  "<<std::endl;
			std::cout<<" |  "<<std::endl;
			std::cout<<"-+-"<<std::endl<<std::endl;;

			}
			break;
		case 6: {

			std::cout<<" +---+"<<std::endl;
			std::cout<<" |   |"<<std::endl;
			std::cout<<" |   "<<std::endl;
			std::cout<<" |  "<<std::endl;
			std::cout<<" |  "<<std::endl;
			std::cout<<"-+-"<<std::endl<<std::endl;;

			}
			break;

		default:
			break;
	}

	std::cout<<"Secret Phrase: "<< noptrHiddenPhrase<<std::endl;

}

int GetSecretPhraseLength(char secretPhrase[], int secret_phrase_max_length) {
	bool isValid { false };
	int length { 0 };

	do {
		isValid = true;
		std::cout<<"Please enter the secret phrase: "<<std::endl;
		std::cin.get(secretPhrase, secret_phrase_max_length);

		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS);
			std::cout<< INPUT_ERROR_STRING << std::endl;
			isValid = false;

		}else {

			length = std::strlen(secretPhrase);

			if(length == 0 ) {
				std::cout<<"You must enter a word that's longer than 0 chracters! Try Again" << std::endl;
			}
		}

	}while(!isValid);

	return length;
}

char * MakeHiddenPhrase(const char secretPhrase[], int secretPhraseLength) {

	char* hiddenPhrase = new char[secretPhraseLength];

	for( int i =0 ; i < secretPhraseLength; ++i) {

		if(secretPhrase[i] != ' ') {
			hiddenPhrase[i] = '-';
		}
		else {
			hiddenPhrase[i] = ' ';
		}
	}

	return hiddenPhrase;

}

void DisplayResult(int numberOfTries, const char * secretPhrase ) {

	if(numberOfTries > 0) {

		std::cout<<"You got it! The phrase was: "<< secretPhrase <<std::endl;

	} 
	else {

		std::cout<<"You didn't get it... The phrase was: "<< secretPhrase<<std::endl;

	}
}

void ClearScreen() {
		system("clear");
}
