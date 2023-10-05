#include<iostream>
#include<cstring>

char * ReverseCopy(const char * str) {

	int strLength = std::strlen(str);
	
	char * reverseString = new char[strLength + 1]; // +1 for the null character

	int j = 0 ;

	for (int i = strLength - 1; i >= 0 ; --i) {
		reverseString[j] = str[i]; 
		j++;
	}
	
	reverseString[j] = '\0';
	return reverseString;

};

int main() {


	//Problem 1 : Read a phrase from the user and output it again
	//
	const int MAX_BUFFER_LENGTH { 256 };

	char buffer[MAX_BUFFER_LENGTH];
	
	std::cout<<"Please eneter your phrase: "<<std::endl;
	std::cin.get(buffer, MAX_BUFFER_LENGTH - 1);
	
	std::cout<<"Your phrase was : " << buffer << std::endl;

	
	//Problem 2 : Using problem 1, make a function that will take in the input phrase
	//and returns a reverse copy of the phrase and output it 
	
	const char * reversed = ReverseCopy(buffer);

	std::cout<<"The reversed Copy : " << reversed << std::endl;

	delete[] reversed;
	return 0;
}

