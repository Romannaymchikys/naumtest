#pragma once
#include <iostream>

void myPrint() {};

template <typename T, typename ... Types>
void myPrint(const T value,  const Types ... args){
	std::cout << value << ' ';
	return myPrint(args ...);
}

