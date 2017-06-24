#include "MyVector.h"
#include <vector>
int MyVector::counterCreated = 0;
int MyVector::counterExisting = 0;
int* MyVector::getArr() const { return arr; }
size_t MyVector::get_size() const { return size; }
size_t MyVector::get_capacity() const { return capacity; }
int MyVector::getCounterCreated() { return counterCreated; }
int MyVector::getCounterExisting() { return counterExisting; }

void MyVector::setArr(int* newArr) { arr = newArr; }
void MyVector::setSize(size_t newSize) { size = newSize; }
void MyVector::setCapacity(size_t newCapacity) { capacity = newCapacity; }
int* MyVector::push_back (int element)
{
	if (size < capacity)
	{
		arr[size++] = element;
		return arr;
	}
	// если нам не хватает памяти
	else
	{
		capacity *= 2;
		int* newArr = new int[capacity];
		int* newArray = newArr;
		for (int* array = arr;
			array < arr + size; ++array, ++newArray)
		{
			*newArray = *array;
		}
		int* deletArray = arr;
		arr = newArr;
		newArray = nullptr;
		delete[] deletArray;
		arr[size++] = element;
		return arr;
	}
}
int MyVector::pop_back()
{
	/*int* ptrArr = arr + size;
	ptrArr = nullptr;
	--size; удаление последнего элемента*/
	return arr[--size];
}
int& MyVector::at(size_t index)
{
	return arr[index];
}

MyVector& MyVector::operator=(const MyVector& obj) {
	if (this == &obj) {
		return *this;
	}
	size = obj.size;
	delete[] arr;
	arr = new int[size];
	for (size_t i = 0; i < size; ++i) { arr[i] = obj.arr[i]; }
	return *this;
}
MyVector& MyVector::operator=(MyVector&& obj) {
	if (this == &obj) {
		return *this;
	}
	size = obj.size;
	delete[] arr;
	arr = obj.arr;
	obj.size = 0;
	obj.arr = nullptr;
	return *this;
}
int* MyVector::operator[](size_t index) {
	return arr + index;
}

bool MyVector::operator>(const MyVector newDigit) {
	for (size_t i(0); i < size; ++i){
		if (!(arr[i] > newDigit.arr[i])) { return false; }
	}
	return true;
}
bool MyVector::operator<(const MyVector newDigit){
	for (size_t i(0); i < size; ++i){
		if (!(arr[i] < newDigit.arr[i])) { return false; }
	}
	return true;
}
bool MyVector::operator<=(const MyVector newDigit){
	for (size_t i(0); i < size; ++i) {
		if (!(arr[i] <= newDigit.arr[i])) { return false; }
	}
	return true;
}
bool MyVector::operator>=(const MyVector newDigit){
	for (size_t i(0); i < size; ++i) {
		if (!(arr[i] >= newDigit.arr[i])) { return false; }
	}
	return true;
}
bool MyVector::operator==(const MyVector newDigit){
	for (size_t i(0); i < size; ++i) {
		if (arr[i] != newDigit.arr[i]) { return false; }
	}
	return true;
}
bool MyVector::operator!=(const MyVector newDigit){
	for (size_t i(0); i < size; ++i) {
		if (arr[i] == newDigit.arr[i]) { return false; }
	}
	return true;
}

MyVector MyVector::operator+(const MyVector newDigit) {
	MyVector newTmpMyVector;
	newTmpMyVector.arr= new int[size + newDigit.size];
	for (size_t i = 0; i < size + newDigit.size; ++i) {
		if (i < size) { newTmpMyVector.arr[i] = arr[i]; }
		else { newTmpMyVector.arr[i] = newDigit.arr[i]; }
	}
	return newTmpMyVector;
}
