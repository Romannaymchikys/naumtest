#include "Digit.h"

size_t Digit::counter = 0;
int Digit::getDigit() const { return digit; }
size_t Digit::getCounter() { return counter; }

void Digit::setDigit(const int newDigit) { digit = newDigit; }

Digit Digit::operator + (const Digit& newDigit) const{
	return  Digit(digit + newDigit.digit);
}
Digit Digit::operator - (const Digit& newDigit) const{
	return  Digit(digit - newDigit.digit);
}
Digit Digit::operator / (const Digit& newDigit) const{
	return  Digit(digit / newDigit.digit);
}
Digit Digit::operator * (const Digit& newDigit) const{
	return  Digit(digit * newDigit.digit);
}
Digit Digit::operator % (const Digit& newDigit) const{
	return  Digit(digit % newDigit.digit);
}
Digit Digit::operator + (const int newDigit) const{
	return  Digit(digit + newDigit);
}
Digit Digit::operator - (const int newDigit) const{
	return  Digit(digit - newDigit);
}
Digit Digit::operator * (const int newDigit) const{
	return  Digit(digit * newDigit);
}
Digit Digit::operator / (const int newDigit) const{
	return  Digit(digit / newDigit);
}
Digit Digit::operator % (const int newDigit) const{
	return  Digit(digit % newDigit);
}
Digit& Digit::operator++(){//префекная форма 
	++digit;
	return *this;
}

/*Digit Digit::operator++(int){//постфиксная форма 
    Digit tmp = *this;
	++digit;
	return tmp;
}
*/
Digit& Digit::operator--(){
	--digit;
	return *this;
}
Digit& Digit::operator+=(const int newDigit){	
	digit += newDigit;
	return *this;
}
Digit& Digit::operator-=(const int newDigit){
	digit -= newDigit;
	return *this;
}
Digit& Digit::operator*=(const int newDigit){
	digit *= newDigit;
	return *this;
}
Digit& Digit::operator/=(const int newDigit){
	digit /= newDigit;
	return *this;
}
Digit& Digit::operator%=(const int newDigit){
	digit %= newDigit;
	return *this;
}
Digit& Digit::operator=(const Digit& newDigit){// присваивание
	if (this == &newDigit) {//сравниваем адреса обьектов
		return *this; }
	digit = newDigit.digit;
	return *this;
}
Digit& Digit::operator()(const int newDigit){
	digit = newDigit;
	return *this;
}

