#include<iostream>


void solveProblem1(){
	//Problem 1: Wha does result evaluate to ? 
	//

	int x = 0;
	int y = 20;

	bool z = true;
	bool w = false;
	bool result = (!w || z) && !(( y > x) && (!z));

	std::cout<<result<<std::endl; // true

}

void solveProblem2() {

	//Problem 2: 
	//Write a program that finds all roots of quadratic equation.
	//A quadratic equation is in the form ax^2 + bs + c = 0
	//The Quadratic equation: (-b + squareroot(b*b - 4*a*c)) / (2*a) and (b- squareroot(b*b - 4*a*c))/ (2*a)

}

void solveProblem3() {
	//Problem 3:
	//Write a program that enters a number and prints out whther its even or odd/
	//Use switch statment
	//
	int number {20};
	bool isEven = number % 2 == 0;
	switch (number % 2 ) {
		case (0) :
			std::cout<<"Even"<<std::endl;
			break;
		default:
			std::cout<<"Odd"<<std::endl;
			break;
	}
}

void solveProblem4() {
	// Problem 4: Write a program that inputs a character and outputs whether or not it is in the alphabet or not.
	char character = '4';
	int characterInt = static_cast<int>(character);
	if( ( characterInt >= 65 && characterInt <= 90 ) || (characterInt >= 97 && characterInt <= 122) ) {
		std::cout<<"Character: " << character<< "is alphabet"<<std::endl;
	}
	else {
		std::cout<<"Character: " << character<< " is not alphabet"<<std::endl;
	}


}

void solveProblem5() {
	// Problem 5: Write a program that takes in 3 numbers and outputs the biggest number and the smallest number
	int num{-1}, num_2{92}, num_3{20};
	int biggest {0};
	int smallest {0};

	if( num > num_2 && num > num_3) {
		biggest = num;			
		if(num_2 > num_3) {
			smallest = num_3;
		}
		else {
			smallest = num_2;
		}
	} 
	else if (num_2 > num && num_2 && num_3) {
		biggest = num_2;
		if(num > num_3) {
			smallest = num_3;
		}
		else {
			smallest = num;	
		}
	}
	else {
		biggest = num_3;
		if(num > num_2) {
			smallest = num_2;
		}else {
			smallest = num;
		}
	}
	std::cout<<"Smallest: "<<smallest<< " Biggest: "<<biggest<<std::endl;

}

void solveProblem6() {
	// Problem 6 : Write a program that enters 3 sides of a triangle checks whether the triangle is valid or not. Remember that a triangle is valid if and only if the sum of any two sides is greater than the third side.

	int side_a { 10 }, side_b { 20 }, side_c { 15 }; 

	int sum_1 { side_a + side_b };
	int sum_2 { side_a + side_c };
	int sum_3 { side_b + side_c };
	if( sum_1 > side_c && sum_2 > side_b && sum_3 > side_a) {
		std::cout<<"Yes it is triangle\n";
	}
	else {
		std::cout<<"No it's not"<<std::endl;
	}

}

void solveProbem7() {
	//Problem 7: Write a program to enter any alphabet and check whether alphabet is vowel or consonant using switch case.
	char alphabet = 'a';
	bool isAlphabet = false;
	switch(alphabet) {
		case ('a'):
			isAlphabet = true;
			break;

		case('i'):
			isAlphabet = true;
			break;

		case('u'):
			isAlphabet = true;
			break;

		case('e'):
			isAlphabet = true;
			break;

		default:
			isAlphabet = false;
	}

	std::cout<<"is Alphabet : "<< alphabet<< " consonant" << isAlphabet << std::endl;

}

int main() {
	solveProblem1();
	solveProblem2();
	solveProblem3();
	solveProblem4();
	solveProblem5();
	solveProblem6();

	return 0;
}
