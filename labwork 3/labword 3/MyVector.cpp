#include "MyVector.h"
#include <vector>
int* MyVector::getArr() const { return arr; }
size_t MyVector::get_size() const { return size; }
size_t MyVector::get_capacity() const { return capacity; }
//int MyVector::getCounterCreated() { return counterCreated; }
//int MyVector::getCounterExisting() { return counterExisting; }

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
