#include<iostream>
void resize(int** refPtr, int newSize);
int inputLength { 10 } ;
int main() {


	int * optrArray = new int[inputLength];
	do {

		for(int i =0 ; i < inputLength ; i++ ) {
			optrArray[i] = i;
			std::cout<<optrArray[i]<<std::endl;
		}
		std::cout<<"Input new length > 0"<<std::endl;
		std::cin>>inputLength;
		
		if(inputLength > 0) {
			resize(&optrArray ,inputLength);
		}

	}while( inputLength > 0);

	delete [] optrArray;

	return 0;
}

void resize(int ** refPtr, int newSize) {
	
	if(refPtr != nullptr) {
		delete [] *refPtr;
	} 
	*refPtr = new int [newSize];

}
