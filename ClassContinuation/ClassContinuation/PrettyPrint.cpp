#include "PrettyPrint.h"
#include <iostream>

std::string PrettyPrint::getStr1() const { return str1; }
std::string PrettyPrint::getStr2() const { return str2; }

std::string PrettyPrint::conclusion(){
	return str1 + "." + str2;
}

std::string PrettyPrint::substitution(std::string str){
	for (int i = 0; i <= str.length(); ++i){
		if (str[i] == 'o') { str[i] = 'a'; }
	}
	std::cout << "\n" << str;
	return str;
}
std::string PrettyPrint::revolString(std::string str)
{
	for (int i = 0, j = str.length() - 1; i <= str.length() / 2; ++i, --j)
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	std::cout << "\n" << str << std::endl;
	return str;
}
