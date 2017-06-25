#pragma once
#include <string>

class PrettyPrint
{
public:
	PrettyPrint(const std::string newstr1, const std::string newstr2) :
		str1(newstr1), str2(newstr2) {};

	std::string getStr1() const;
	std::string getStr2() const;

	std::string conclusion();
	std::string substitution(std::string str);
	std::string revolString(std::string str);
	~PrettyPrint() {};
private:
	std::string str1;
	std::string str2;
};