#include "subscriber.h"
#include <string>
#include <iostream>
size_t Subscriber::counter = 0;
size_t Subscriber::getCounter(){ return counter; }

std::string Subscriber::getName() const { return name; }
std::string Subscriber::getSurname() const { return surname; }
std::string Subscriber::getPatronymic() const { return patronymic; }
std::string Subscriber::getHomePhone() const { return homePhone; }
std::string Subscriber::getMobilPhone() const { return mobilPhone; }
std::string Subscriber::getAllSubscriber() const { 
	return name, surname, patronymic, mobilPhone, homePhone;
}
std::string Subscriber::getInfo() const { 
	return surname + ' ' + name + ' ' + patronymic + ' ' + mobilPhone + ' ' + homePhone; 
}
void Subscriber::setName(const std::string newName) { this->name = newName; }
void Subscriber::setSurname(const std::string newSurn) { (*this).surname = newSurn; }
void Subscriber::setPatronymic(const std::string newPat) { patronymic = newPat; }
void Subscriber::setHomePhone(const std::string newHomePhon) { homePhone = newHomePhon; }
void Subscriber::setMobilPhone(const std::string newMobilPhon) { mobilPhone = newMobilPhon; }

void Subscriber::Print() 
{
	std::cout << " Name subscriber - " << name << std::endl; 
	std::cout << " Surname subscriber - " << surname << std::endl;
	std::cout << " Patronymic subscriber - " << patronymic << std::endl;
	std::cout << " HomePhone subscriber - " << homePhone << std::endl;
	std::cout << " MobilPhone subscriber - " << mobilPhone << std::endl;
}

