#include <iostream>
#include "Header.h"
#include "Pair.h"
#include "Stack.h"
#include "myPrint.h"
#include "queue.h"

void testQueueFunctional() {
	Queue<int>queue(1000);
	std::cout << queue.empty() << std::endl;
	queue.push(123);
	std::cout << queue.size()  << std::endl;
	queue.push(234);
	std::cout << queue.size()  << std::endl;
	std::cout << queue.front() << std::endl;
	std::cout << queue.back()  << std::endl;
	

	queue.pop();
}
void testStackFunctional() {
	Stack<int>stack(100);
	std::cout << stack.empty() << std::endl;
	stack.push(123);
	std::cout << stack.getSize() << std::endl;
	stack.push(234);
	std::cout << stack.getSize() << std::endl;
	stack.pop();
	std::cout << stack.getSize() << std::endl;
	std::cout << stack.getTopValue() << std::endl;
	Stack<int>stackSecond(stack.getSize());
	Stack<int>stackThird = std::move(stack);
	stackSecond.push(1);
	stackSecond == stack;
	stackSecond != stack;
	stackSecond = stack;
	std::cout << stackSecond.getTopValue() << std::endl;

}

void testPairFunctional(){
	const size_t arSize = 6;
	int arr[arSize] = { 2, 5, 6, 8, 15, 25 };
	float max = getMax(arr, arSize);
	std::cout << max << std::endl;
	float max1 = getMax<5>(arr);
	std::cout << max1 << std::endl;
	sort(arr, arSize);
	printarr(arr, arSize);
	int index = find(arr, arSize, 3);
	std::cout << index << std::endl;
	auto x = getmax(5, 7.8);
	std::cout << x;
	Pair<int, float> value(20, 15.5);
	std::cout << value.first() << std::endl;
}

void testMyPrintFunctional() {
	myPrint();
	myPrint(1);
	std::cout << std::endl;
	myPrint(10, 34, 45.12, 99.1189);
	std::cout << std::endl;
	myPrint(10, 34, 45.12, "text", "new string");
	std::cout << std::endl;
	myPrint("Student", 17, 2017, "18-11S", 9.1);
	std::cout << std::endl;
}


void main() {
	//testPairFunctional();
	//testStackFunctional();
	//testMyPrintFunctional();
	testQueueFunctional();
	system("pause");
}