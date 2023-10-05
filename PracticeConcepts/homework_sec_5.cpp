#include <cmath>
#include<iostream>
#include <string>


void problem1() 
{
	// Problem 1 : Write a program that will take in a number from the user and print the reverse of that number.
	//
	
	int nums { 42301 };
	
	while(nums != 0 ) {
		
		int lastNum { nums % 10 };
		std::cout<< lastNum;
		nums /= 10;
	}

}

void problem2() {
	// Write a program that takes in two numbers from the user and prints a star pattern in a rectangular pattern
	// First number, rows
	// second number, columns
	int rows { 4 }, columns { 6 };
	for (int i =0 ; i < rows ; i ++ ) {
		for(int j=0 ; j < columns; j++) {
			std::cout<<"*";
		}	
		std::cout<<std::endl;
	}
}

void problem3() {
	// Write a program that takes in a number and prints a pyramid star pattern. 
	
	int nums { 5 } ;
	
	for ( int i = 0 ; i < nums ; i++ ) {
		
		for (int j = 0; j < nums - i ; j++ ) {
			std::cout<<" ";
		}

		for (int j = 0; j < 2 * i + 1 ; j++) {
			std::cout<<"*";
		}

		for (int j = 1; j < nums - 2*i +1 ; j++) {
			std::cout<<" ";
		}

		std::cout<<std::endl;
	}
}

void problem4() {
	
	std::string numsBinary { "01000011" };
	
	for (int i = 0 ; i < numsBinary.length(); i++) {
		bool converted = !( static_cast<int>(numsBinary[i] - 48)) ;
		std::cout << converted;

	}

	std::cout<<std::endl;

}

void problem5() {
	for (int ch = 0; ch < 128; ch++) {
		std::cout<<static_cast<char>(ch)<<" ";
		if(ch % 10 == 0) {
			std::cout<<std::endl;
		}

	}
}

void problem6() {
	
	int nums {11652201};

	int num_0 { 0 }, num_1 { 0 }, num_2 { 0 }, num_3 { 0 }, num_4 { 0 }, 
	num_5 { 0 }, num_6 { 0 }, num_7 { 0 }, num_8 { 0 }, num_9 { 0 };

	while(nums != 0 ) {
		
		int theNum { nums % 10 };
		
		switch (theNum) {
			case 0 : 
				num_0 ++;
			break;

			case 1 : 
				num_1 ++;
			break;

			case 2 :
				num_2++;
			break;
			
			case 3: 
				num_3++;
			break;

			case 4:
				num_4++;
			break;

			case 5:
				num_5++;
			break;

			case 6:
				num_6++;
			break;

			case 7:
				num_7++;
			break;

			case 8:
				num_8++;
			break;

			default:
				num_9++;
			break;


		}
			nums /= 10;
	}

		std::cout<<"Frequency of 0 : "<<num_0<<std::endl;
		std::cout<<"Frequency of 1 : "<<num_1<<std::endl;
		std::cout<<"Frequency of 2 : "<<num_2<<std::endl;
		std::cout<<"Frequency of 3 : "<<num_3<<std::endl;
		std::cout<<"Frequency of 4 : "<<num_4<<std::endl;
		std::cout<<"Frequency of 5 : "<<num_5<<std::endl;
		std::cout<<"Frequency of 6 : "<<num_6<<std::endl;
		std::cout<<"Frequency of 7 : "<<num_7<<std::endl;
		std::cout<<"Frequency of 8 : "<<num_8<<std::endl;
		std::cout<<"Frequency of 9 : "<<num_9<<std::endl;

}

void problem7() {
	int nums { 12131821 };
	int nums2 {2232};
	int num_pal2 { 212 };
	int num_pal { 121212121 };

	bool isPalindrome {true}; 
	std::string numsStr = std::to_string(num_pal2);
	int lengthNums = numsStr.length() - 1; // -1 because array starts from 0
	
	for ( int i {0} ; i <= lengthNums/2 ; i++) {
		int ptr_1 {numsStr[i]} ;
		int ptr_2 {numsStr[lengthNums - i]};
		std::cout<<ptr_1 << " " <<ptr_2<<std::endl;

		if(ptr_1 != ptr_2 ) isPalindrome = false;
	}

	std::cout<<"Is Palindrome: "<<isPalindrome<<std::endl;

}

void problem8() {
	
	int nums { 5 }  ;
	std::string numsStr = std::to_string(nums);
	int numsLength = 5;
	for (int i =0; i < numsLength; i++) {
		
		for(int j = 0; j < numsLength -i ; j++) {
			std::cout<<" ";
		}

		for(int j =0; j < i * 2 + 1; j++) {
			std::cout<<"*";
		}

		std::cout<<std::endl;
	}


	for (int i = numsLength - 2; i >= 0 ; i--) {
		for (int j = 0 ; j < numsLength - i; j++) {
			std::cout<<" ";
		}
		
		for(int j =0 ; j < 2*i+1; j++) {
			std::cout<<"*";
		}
		
		for (int j = 0 ; j < numsLength - (2*i+1); j++) {
			std::cout<<" ";
		}

			std::cout<<std::endl;
	}
	
}

void problem9() {
	int nums { 5 };
	int numsLength = nums ;
	
	for(int i = 0 ; i < numsLength ;i++) {
		for(int j = 0; j < numsLength - i; j++) {
			std::cout<<"*";
		}

		for (int j = 0; j < 2 * i ;j++) {
			std::cout<<" ";
		}

		for(int j = 0; j < numsLength - i; j++) {
			std::cout<<"*";
		}
		std::cout<<std::endl;
	}

	for(int i = numsLength - 1; i >= 0; i--) {
		for(int j = 0; j < numsLength - i; j++) {
			std::cout<<"*";
		}

		for (int j = 0; j < 2 * i ;j++) {
			std::cout<<" ";
		}

		for(int j = 0; j < numsLength - i; j++) {
			std::cout<<"*";
		}

		std::cout<<std::endl;
	}

}

int main() 
{
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

	problem6();
	std::cout<<std::endl;

	problem7();
	std::cout<<std::endl;

	problem8();
	std::cout<<std::endl;

	problem9();
	std::cout<<std::endl;
	return 0;
};
