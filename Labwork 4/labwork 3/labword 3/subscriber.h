#pragma once
#include <string>
class Subscriber
{
	std::string name;
	std::string surname;
	std::string patronymic;
	std::string homePhone;
	std::string mobilPhone;
	static size_t counter;
public:
	Subscriber(){}
	static size_t getCounter();
	Subscriber(std::string newName, std::string newSurn,
		std::string newPat, std::string newHomePhon, std::string newMobilPhon) :
		name(newName), surname(newSurn), patronymic(newPat),
		homePhone(newHomePhon), mobilPhone(newMobilPhon) 
	{
		++counter;
	}
	
	std::string getName() const;
	std::string getSurname() const;
	std::string getPatronymic() const;
	std::string getHomePhone() const;
	std::string getMobilPhone() const;
	std::string getAllSubscriber() const;
	std::string getInfo()const;
	
	void setName(const std::string newName);
	void setSurname(const std::string newSurn);
	void setPatronymic(const std::string newPat);
	void setHomePhone(const std::string newHomePhon);
	void setMobilPhone(const std::string newMobilPhon);
	void Print();

	~Subscriber(){}
};

