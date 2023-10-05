#include<iostream>

int * CreateDynamicArray(int capacity, int & size);
void DeleteDynamicArray(int * dynamicArray, int &size);
void InsertElement(int** dynamicArray, int element, int & size, int & capacity);
void DeleteElement(int* dynamicArray, int elementIndex, int & size);
void ResizeDynamicArray(int** dynamicArray, int size, int newCapacity);// Points to Another ptr references
void PrintDynamicArray(int* dynamicArray, int size);

int main() {
	int size { 0 } ;
	int capacity {4};
	int * optrDynamicArray { CreateDynamicArray(capacity, size)};
	InsertElement(&optrDynamicArray, 4, size, capacity);
	
	InsertElement(&optrDynamicArray, 6, size, capacity);

	InsertElement(&optrDynamicArray, 20, size, capacity);
	InsertElement(&optrDynamicArray, 110, size, capacity);
	InsertElement(&optrDynamicArray, 110, size, capacity);
	PrintDynamicArray(optrDynamicArray, size);
	DeleteElement(optrDynamicArray, 0, size);
	DeleteElement(optrDynamicArray, 1, size);
	PrintDynamicArray(optrDynamicArray,size);

	DeleteDynamicArray(optrDynamicArray, size);
	DeleteElement(optrDynamicArray, 1, size);
	DeleteDynamicArray(optrDynamicArray, size);
	return 0;
}

int * CreateDynamicArray(int capacity, int & size ) {
	int * dynamicArray = new int[capacity] {};
	size = 0 ;
	
	return dynamicArray;
}

void DeleteDynamicArray(int * dynamicArray, int & size) {
	if(size != 0 && dynamicArray != nullptr) {
		delete[] dynamicArray;
		dynamicArray = nullptr;
		size = 0;
	}
	else {
		std::cout<<"No Data\n";
	}
	return ;
}

void InsertElement(int** dynamicArray, int element, int & size, int & capacity) {
	if(size < capacity) {
		(*dynamicArray)[size] = element; 
		size++;
	}
	else {
		std::cout<<"Resizing the Array "<<capacity<<std::endl;
		capacity = capacity * 2;
		ResizeDynamicArray(dynamicArray, size, capacity);
		InsertElement(dynamicArray, element, size, capacity);
	}

	return;
}

void DeleteElement(int* dynamicArray, int elementIndex, int & size ) {
	if(elementIndex > size){
		std::cout<<"Invalid index" << std::endl;
		return;
	}

	for(int i = elementIndex; i < size - 1 ; i++ ) {
		dynamicArray[i] = dynamicArray[i+1];
	}
	size -= 1;
}

void ResizeDynamicArray(int** dynamicArray, int size, int newCapacity) {

	int tempSize = size;
	int * newArr = CreateDynamicArray(newCapacity, size);

	for(int i =0 ; i <tempSize;++i) {
		newArr[i] = (*dynamicArray)[i];
	}

	size = tempSize;
	delete[] *dynamicArray;
	*dynamicArray = newArr;
	std::cout<<"Size Increased to "<<newCapacity<<std::endl;
}

void PrintDynamicArray(int* dynamicArray, int size) {

	for(int i =0 ; i < size ; ++i) {
		std::cout<<dynamicArray[i] << " ";
	}
	std::cout<<std::endl;
	return;
}
