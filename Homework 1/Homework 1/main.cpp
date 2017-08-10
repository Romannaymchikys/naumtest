#include <iostream>
#include "FrequencyDictionary.h"
#include <Windows.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FrequencyDictionary freqDict("dictionary.txt");
	freqDict.BasicFunctionality();
	system("pause");
}