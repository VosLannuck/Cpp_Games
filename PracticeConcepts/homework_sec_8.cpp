#include<iostream>

void problem1() {
	int num1 { 50 }, num2{ 30 };
	int temp { num1 + num2 } ;

	std::cout<<"Before: "<< num1<<" "<<num2<<std::endl;
	num1 = temp - num1;
	num2 = temp - num1;

	std::cout<<"After: "<< num1 << " " <<num2 << std::endl;
}

void problem2() {
	int num1 = { 50 };
	int num2 { 30 }; 
	std::cout<<"Before: "<< num1<<" "<<num2<<std::endl;
	
	int * num_ptr { &num1 };
	*num_ptr = num1 + num2; // num1 80
	num_ptr = &num2;

	*num_ptr = num1 - num2; // num2 50
	
	num_ptr = &num1;
	*num_ptr = num1 - num2; // num1 30
	
	std::cout<<"After: "<< num1<< " "<< num2<<std::endl;

}

int main() {
	
	problem1();
	problem2();

	return 0;
}
