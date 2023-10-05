#include<iostream>

int Sum(int arr[], int length);
int Average(int arr[], int length);
void PrintOutput(int arr[], int length, int (*Func)(int arr[], int length) );

int main() {

	int arr[] { 2, 4, 6, 8, 10} ;
	int length = 5;
	PrintOutput(arr, length, Sum);
	PrintOutput(arr, length, Average);

	return 0;
}

int Sum(int arr[], int length) {
	int totalSum { 0 } ;
	for (int i =0 ; i < length ; ++i ) {
		totalSum += arr[i];
	}

	return totalSum;

}

int Average(int arr[], int length){
	
	int totalSum = Sum(arr, length);
	return totalSum / length;
}


void PrintOutput(int arr[], int length, int (*Func)(int arr[], int length)) {
	std::cout<<Func(arr, length)<<std::endl;
}
