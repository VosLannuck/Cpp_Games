#include<iostream>

const int MAX { 20 }; 

void staticMultPointers();
void dynamicMultPointerVariance_1();
void dynamicMultPointerVariance_2();

int main() {

	staticMultPointers();
	dynamicMultPointerVariance_1();

	return 0;
}

void staticMultPointers() {

	int array2D[MAX][MAX];
	int (*list)[MAX] = array2D;  
	
	for (int r = 0; r < MAX ; ++r) {

		for(int c = 0 ; c < MAX ; ++c) {
			list[r][c] = r * c ;
			std::cout<< "R : " << r << " C: "<< c<< "Value : " << list[r][c]<<std::endl;
		} 
	}

}


void dynamicMultPointerVariance_1() {
	int (*list)[MAX] = new int [MAX][MAX];
	for (int r = 0; r < MAX ; ++r) {

		for(int c = 0 ; c < MAX ; ++c) {
			list[r][c] = r * c ;
			std::cout<< "R : " << r << " C: "<< c<< "Value : " << list[r][c]<<std::endl;
		} 
	}
		
	delete [] list;
}

void dynamicMultPointerVariance_2() {

}
