#include <iostream>
#include "Digit.h"

void testFunctionDigit()
{
	Digit first;
	Digit second(10);
	Digit third(13.789);
	Digit fournth(second);
	Digit fifth = std::move(third);

	std::cout << first.getDigit() << std::endl;
	std::cout << second.getDigit() << std::endl;
	std::cout << third.getDigit() << std::endl;
	std::cout << fournth.getDigit() << std::endl;
	std::cout << fifth.getDigit() << std::endl;
	std::cout << std::endl;

	third = fournth + fifth;
	std::cout << third.getDigit() << std::endl;
	third = fournth - fifth;
	std::cout << third.getDigit() << std::endl;
	third = fournth * fifth;
	std::cout << third.getDigit() << std::endl;
	third = fournth / fifth;
	std::cout << third.getDigit() << std::endl;
	third = fournth % fifth;
	std::cout << third.getDigit() << std::endl;
	std::cout << std::endl;

	++third;
	std::cout << third.getDigit() << std::endl;
	--third;
	std::cout << third.getDigit() << std::endl;
	std::cout << std::endl;

	third += fifth;
	std::cout << third.getDigit() << std::endl;
	third -= fifth;
	std::cout << third.getDigit() << std::endl;
	third /= fifth;
	std::cout << third.getDigit() << std::endl;
	third *= fifth;
	std::cout << third.getDigit() << std::endl;
	third %= fifth;
	std::cout << third.getDigit() << std::endl;
	std::cout << std::endl;

	int th = fournth;
	std::cout << th << std::endl;
	double th1 = fournth;
	std::cout << th << std::endl;

}


int main()
{
	testFunctionDigit();
	system("pause");
	return 0;
}