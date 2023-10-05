#include <iostream>
#include<cmath>
#include <string>
const float PI = 22.0 / 7.0;

float diameter_of_circle(float radius) 
{
	return 2.0 * radius;
}

float circumference_of_circle(float radius) 
{
	return 2 * PI * radius;
}

float areaOfCircle(float radius) 
{
	return PI * radius * radius;
}

void problem1() 
{

	float radius { 4 }; 

	std::cout<<"Diameter of the circle : "<<diameter_of_circle(radius)<<std::endl;
	std::cout<<"Circumference of the circle : "<<circumference_of_circle(radius)<<std::endl;
	std::cout<<"Area of the circle : "<<areaOfCircle(radius)<<std::endl;

}


void problem2() 
{
	int input { 0 } ;
	bool isNotValidInput { false };
	do {
		isNotValidInput = false;
		std::cout<<"Please input your number: ";
		std::cin>>input;
		if(std::cin.fail()) 
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			isNotValidInput = true;
			std::cout<<"Dude Integer only"<<std::endl;
		}

	}while(isNotValidInput);

	std::cout<<"Your number: "<< input<<std::endl;
}

bool problem_3_helper_isPrime(int nums)  
{
	bool is_prime { false };
	if(nums == 2 || nums == 3 || nums == 5 || nums == 7 || ( nums % 2 != 0 && nums % 3 != 0 && nums % 5 != 0 && nums % 7 != 0 ) )
	{
		is_prime = true;
	} 
	return is_prime;

}
void problem3() 
{
	for( int nums = 2 ; nums <= 100 ; ++nums ) 
	{
		std::cout<<"Nums : "<<nums<<" is prime : "<<problem_3_helper_isPrime(nums)<<std::endl;
		if( nums % 10 == 0 ) std::cout<<std::endl;

	}
}

void problem_4_helper_primRange(int start , int end ){

	for( int nums = start; nums <= end; nums++) 
	{
		if(problem_3_helper_isPrime(nums)) {
			std::cout<< nums << " ";
		}
	}
} 

void problem4() 
{
	int start { 10 }, end { 50 };  
	problem_4_helper_primRange(start, end);
}
std::string concatString( const std::string str_1, const std::string str_2 ){
	return str_1 + str_2;
}

int charToInt(char digitChar) {
	return digitChar - '0';
}
void drawNumber(int num) 
{
	if ( num == 0 ) 
	{
		return;
	}
	else if(num == 1) 
	{
		std::cout<<"1";
	}
	else {

		std::string result = "";
		int count = std::pow(11,num-1);
		std::string countstr = std::to_string(count);

		std::cout<<"1";
		for(int i = 0; i < countstr.length() - 1; i++ ) 
		{
			result += std::to_string(charToInt(countstr[i] + charToInt(countstr[i+1]))) ;
		}

		for(int i = 0; i < result.length() ; i++) 
		{
			std::cout<<result[i];
		}
		std::cout<<"1";

	}
}

void problem5() 
{
	// Better to think it first rather than use the string approach bro
	int nums { 6 };
	for (int i = 0; i <= nums; i++) {
		// Print leading spaces to format the triangle
		for (int space = 0; space <= nums - i; space++) {
			std::cout << " ";
		}

		// Print values in the current row
		int value = 1;
		for (int j = 0; j <= i; j++) {
			std::cout << value << " ";
			value = value * (i - j) / (j + 1);
		}

		std::cout << std::endl;
	}
}

int main() {
	problem1();
	std::cout<<std::endl;

	problem2();
	std::cout<<std::endl;
	problem3();

	std::cout<<std::endl;
	problem4();

	std::cout<<std::endl;
	problem5();

	std::cout<<std::endl;
	return 0;
}
