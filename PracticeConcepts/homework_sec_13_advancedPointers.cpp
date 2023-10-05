#include<iostream>

void solveProblem1();
int index();

void solveProblem2();

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
int modulus(int x, int y);
int power(int x, int y);

typedef int (*ArtimethicFunc)(int x, int y) ; // < Typedata ptr functionSignature > < ArtimethicFunc> as newName
typedef void (*Dummy)();
ArtimethicFunc GetFunction(char op);
int (*ArithemeticFunctions (char op))(int x, int y); // Traditional Overengeering shit

int main() {

	/*	Problem 1 : 
	 *	How would you write a 2D Array Using only a 1D array. What Extra functions might you need to solve 
	 *	this problem ? 
	 *
	 *  Problem 2 :
	 *	Create Calculator using Function pointers
	 *
	 * */
	solveProblem1();
	solveProblem2();
	return 0;
}

int index(int r, int c, int num_cols) {
	return r * num_cols + c;
}
void solveProblem1() {
	int max { 3 };
	int array[ max * max];
	//*
	//		Steps :
	//		1. Create 1D Array
	//		2. Understand the Indexing when doing assignment in 2D array
	//		3. num_col = 3 
	//		4. array[1][2] = r[1], c[2] -> array[5] = r * num_col + c
	//*//
	
	for (int r = 0 ; r < max ; ++r) {
		for(int c = 0 ; c < max ; ++c) {
			array[index(r, c, max)] = index(r, c, max);
			std::cout<< "R : " << r << " C : " << c << std::endl;
			std::cout<<"Array[" <<array[index(r, c, max)] << "]"<<std::endl;
		}
	}
}
void solveProblem2() {


	int a , b ;
	char op;
	
	std::cout<<"Please enter 2 number, spaces\n";
	std::cin>>a>>b;
	
	std::cout<<"Please choose Operator";
	std::cin>>op;

	int result = ArithemeticFunctions(op)(a,b);
	ArtimethicFunc func = GetFunction(op);
	
	std::cout<< "Using Traditional : " << result << std::endl;
	std::cout<< "Using Typedef : "<< func(a, b)<<std::endl;
	

}
int add(int x, int y) {
	return x + y;
}

int subtract(int x, int y) {
	return x -y;
}

int multiply(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	return x / y;
}

int modulus(int x, int y) {
	return x % y;
}

int power (int x, int y ) {
	return std::pow(x, y);
}
int (*ArithemeticFunctions (char op))(int x, int y) {
	switch (op) {
		case '+' : return add;
		case '-' : return subtract;
		case '*' : return multiply;
		case '/' : return divide;
		case '%' : return modulus;
		case '^' : return power;
	}
	return add;
}
ArtimethicFunc GetFunction(char op) {

		switch (op) {
			case '+' : return add;
			case '-' : return subtract;
			case '*' : return multiply;
			case '/' : return divide;
			case '%' : return modulus;
			case '^' : return power;
		}
		return add;
}

void withoutParams() {
	std::cout<<"This is without params";
}

Dummy JustPrint() {
	
	return withoutParams;

}
