#include<iostream>

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

int main() {

	problem1();
	problem2();
	problem3();
	problem4();
	problem5();
	problem6();
	problem7();
	return 0;
}
int dotProduct(const int arr[], const int arr2[], const int length) {
	int dotProduct { 0 };
	for (int i =0 ; i < length; i++) {
		dotProduct += arr[i] * arr2[i];
	}

	return dotProduct;
} 

void problem1() {
	// Write a function that takes 2 vectors and returns the dot product of the two vectors. 
	int arr[] { 2, 3, 5};
	int arr2[] { 4, 2, 1};
	
	std::cout<<dotProduct(arr, arr2, 3)<<std::endl;
}

void problem2() {
}

void problem3() {

}
std::string reverseString(const std::string str) {
	
	char result[str.length()];
	char *resultPtr = result;
	int j = -1;
	for (int i =str.length() - 1; i >= 0; i-- ) {
		resultPtr[++j] = str[i]; 
	}

	return result;
}
void problem4() {
	// str var
	// an array x
	// loop trhough the end of string, and store it inside an array x
	// Loop through array x, print the value

	std::cout<<reverseString("Hello")<<std::endl;
}

void problem5() {

	int arr[] { 4, 5, 7, 10, 20};
	int duplicate[] {};
	int *arrPtr = duplicate;
	for (int i { 0 }; i < sizeof(arr) / sizeof(int) ; i++) {
		*arrPtr = arr[i];
		arrPtr++;
	}

	for(int i { 0 } ; i < sizeof(arr) / sizeof(int); i++) {
		std::cout<<duplicate[i]<<" ";
	}

	std::cout<<std::endl;
}

void problem6() {
	
	int arr[] { 3 , 20, 19, 23 ,4 };
	int indexToBeInserted { 2  } ;
	int valueToBeInserted { 100 };
	
	int* arr_ptr = arr;
	std::cout<<"Before: " <<std::endl;
	for(int i { 0 } ; i < sizeof(arr) / sizeof(int) ; i ++ ) {
		std::cout<< *arr_ptr<<" ";
		
		if( indexToBeInserted == i ) {
			*arr_ptr = valueToBeInserted;
		}
		arr_ptr++;
	}
	
	// Reset the pointer
	arr_ptr = arr;
	std::cout<<"\nAfter: "<<std::endl;
	for (int i { 0 }; i < sizeof(arr) / sizeof(int); i++) {
		std::cout<<*arr_ptr<<" ";
		arr_ptr++;
	}
}

void problem7() {
	int sampleArr[] { 3, 41, 2, 15, 0};

	int indexToDelete { 0 }; 
	bool isANumber {false};
	do {
		isANumber = true;
		std::cout<<"Bwang delete index berapa"<<std::endl;
		std::cin>>indexToDelete;

		if(std::cin.fail() || !(indexToDelete >= 0 && indexToDelete < sizeof(sampleArr) / sizeof(int))) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout<<"Yang benera lah bg\n";
			isANumber = false;
		}

	}while(!isANumber);
	int newIndex { 0 };
	for(int i =0 ; i < sizeof(sampleArr) / sizeof(int) - 1 ; i++) {
		if(i != indexToDelete) {
			sampleArr[newIndex] = sampleArr[i];
			newIndex++;
		};
	}
	for(int i =0 ; i < sizeof(sampleArr) / sizeof(int) ; i++) {
		std::cout<<sampleArr[i]<<" ,";
	}

}
