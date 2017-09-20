
#include <iostream>
#include "sensible.h"
#include <Windows.h>

void main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	sensible _sensible("recipes.txt");
	_sensible.readAvailablefileNames();
	_sensible.InputFiles();
	_sensible.textCreatorWritingFile();


	system("pause");
}