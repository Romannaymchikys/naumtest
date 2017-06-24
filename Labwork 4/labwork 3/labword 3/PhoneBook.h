#pragma once
#include "subscriber.h"
#include <array>
class PhoneBook
{
	size_t index;
	Subscriber* subscriberArray;
	std::array<Subscriber, 1000> subArrayStatic;
public:
	size_t getIndex() const;
	Subscriber* getSubscriberArray() const;
	Subscriber getSubArrayStatic() const;

	void setIndex(const size_t);
	void setSubscriberArray(Subscriber*);
	void setSubArrayStatic(Subscriber, size_t);

	void newCopySubscriberArray();
	void creatItemSubscriber();
	void searchDeleteSubscriber();

	void creatItemSubscriberStatic();
	void printSubscriberArrayStatic();
	void searchDeleteSubscriberStatic();
	
	void printSubscriberArray();
    ~PhoneBook(){ delete[]subscriberArray;}
};

