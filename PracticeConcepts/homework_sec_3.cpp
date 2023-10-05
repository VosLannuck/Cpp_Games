#include<iostream>
#include<cmath>
// Problem 1 : Write an algorithm that takes the temperature in farenheit and outputs in celcius
void solveProblem1() {
	float currentFarenheit { 20 };
	//std::cin>>currentFarenheit;
	std::cout << "F: "<< currentFarenheit << " converted to Celcius "<< (currentFarenheit - 32) * 5/9<<std::endl;
}
// Problem 2 : Write a program that takes three numbers and prints the average
void solveProblem2() {
	float val_1 { 20.0 } , val_2 {25.0}, val_3 {25.0} ;
	// std>>cin>>val_1>>val_2>>val_3;
	std::cout<<"Average:" <<  (( val_1 + val_2 + val_3)/3)<<std::endl;
}
// Problem 3 : Write a program that takes in a character and outputs its ASCII value
void solveProblem3() {
	
	char whatCharacter = 'B';
	//std::cin>>whatCharacter;
	std::cout<< "Word: "<< whatCharacter << " Has ascii value : "<<static_cast<int>(whatCharacter)<<std::endl;
}
// Problem 4 : Write a program to input number of days from user and convert it to years, weeks, and days. ignore leap years
void solveProblem4() {
	
	int currentDays = 24;
	std::cout<<"Year : " << currentDays /30;
	std::cout<<" Weeks : "<< currentDays / 7;
	std::cout<< " Days : "<< currentDays ;
	std::cout<<std::endl;

}
// Problem 5 : Write a program that takes a floating point number and outputs the minimum amount of currency denominations needed to make up that number. Eg. If the user input 45.78 then the output would be:
// 4 ten dollar bills
// 1 five dollar bills
// 0 two dollar bills
// 0 one dollar bills
// 3 twenty five cent pieces
// 0 ten cent pieces
// 0 five cent pieces
// 3 one cent pieces
void solveProblem5() {
	float currency { 45.78};
	int tenDollarbills = currency / 10;
	currency = currency - tenDollarbills * 10;

	int fiveDollarBills =  currency / 5;
	currency = currency - fiveDollarBills * 5;

	int twoDollarBills = currency / 2;
	currency = currency  - twoDollarBills * 2;

	int oneDollarBills = currency ;
	currency = currency - oneDollarBills;

	int twentyFiveCents = currency / 0.25;
	currency = currency - twentyFiveCents * 0.25;

	int tenCents = currency / 0.10;
	currency = currency - tenCents * 0.10;

	int fiveCents = currency / 0.05;
	currency = currency - fiveCents * 0.05;

	int oneCents = currency / 0.01;
	currency = currency - oneCents;

	std::cout<< tenDollarbills << " ten dollar bills\n";
	std::cout<< fiveDollarBills << " five dollar bills\n";
	std::cout<< twoDollarBills << " two dollar bills\n";
	std::cout<< oneDollarBills << " one dollar bills\n";
	std::cout<< twentyFiveCents << " twenty five cent pieces\n";
	std::cout<< tenCents << " ten cent pieces\n";
	std::cout<< fiveCents << " five cent pieces\n";
	std::cout<< oneCents<<"\none cent pieces\n";
}
// Problem 3: Write a program that takes in a number of seconds and outputs the time in this format: hh::mm::ss where hh is the hours, mm is the minutes, and ss is the seconds.
void solveProblem6() {
	int totalSeconds {24000};

	int currentHours = totalSeconds / 3600;
	totalSeconds = totalSeconds - currentHours* 3600;
	
	int currentMinutes = totalSeconds / 60;
	totalSeconds = totalSeconds - currentMinutes * 60;
	
	std::cout<<currentHours<<"::"<<currentMinutes<<"::"<<totalSeconds<<std::endl;

}

int main() 
{
	solveProblem1();
	solveProblem2();
	solveProblem3();
	solveProblem4();
	solveProblem5();
	solveProblem6();

	return 0;
}
