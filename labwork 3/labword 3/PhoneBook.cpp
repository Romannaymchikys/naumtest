#include "PhoneBook.h"
#include "subscriber.h"
#include <iostream>
#include <string>
# include <array>
size_t PhoneBook::getIndex() const 
{ 
	return index;
}
Subscriber* PhoneBook::getSubscriberArray() const
{ 
	return  subscriberArray;
}
Subscriber  PhoneBook::getSubArrayStatic()  const 
{ 
	return getSubArrayStatic();
}

void PhoneBook::setIndex(const size_t newIndex)
{ 
	index = newIndex;
}

void PhoneBook::setSubscriberArray(Subscriber* newPhoneBookArray)
{ 
	subscriberArray = newPhoneBookArray; 
}
void PhoneBook::setSubArrayStatic(Subscriber newSetSubArrayStatic, size_t index)
{
	subArrayStatic.at(index) = newSetSubArrayStatic;
}

void  PhoneBook::creatItemSubscriberStatic()
{
	std::string _name, _surname, _patronym, _homePhone, _mobilPhone;

	std::cout << " Name subscriber - ";
	std::cin >> _name;
	subArrayStatic.at(index).setName(_name);
	std::cout << " Surname subscriber - ";
	std::cin >> _surname;
	subArrayStatic.at(index).setSurname(_surname);
	std::cout << " Patronymic subscriber - ";
	std::cin >> _patronym;
	subArrayStatic.at(index).setPatronymic(_patronym);
	std::cout << " HomePhone subscriber - ";
	std::cin >> _homePhone;
	subArrayStatic.at(index).setHomePhone(_homePhone);
	std::cout << " MobilPhone subscriber - ";
	std::cin >> _mobilPhone;
	subArrayStatic.at(index).setMobilPhone(_mobilPhone);
	++index;
}
void PhoneBook::printSubscriberArrayStatic()
{
	for (auto i(0); i < index; ++i)
	{
		std::cout << " Name subscriber - " <<
			subArrayStatic.at(i).getName() << std::endl;
		std::cout << " Surname subscriber - " <<
			subArrayStatic.at(i).getSurname() << std::endl;
		std::cout << " Patronymic subscriber - " <<
			subArrayStatic.at(i).getPatronymic() << std::endl;
		std::cout << " HomePhone subscriber - " <<
			subArrayStatic.at(i).getHomePhone() << std::endl;
		std::cout << " MobilPhone subscriber - " << 
			subArrayStatic.at(i).getMobilPhone() << std::endl;
	}
}

void PhoneBook::searchDeleteSubscriberStatic()
{
	bool selector = false, selectorTwo;
	std::string _name, _surname, _patronym;
	std::cout << " Name subscriber - ";
	std::cin >> _name;
	std::cout << " Surname subscriber - ";
	std::cin >> _surname;
	std::cout << " Patronymic subscriber - ";
	std::cin >> _patronym;
	for (auto i(0); i < index; ++i)
	{
		if (subArrayStatic.at(i).getName() == _name &&
			subArrayStatic.at(i).getSurname() == _surname &&
			subArrayStatic.at(i).getPatronymic() == _patronym)
		{
			selector = true;
			std::cout << " Name subscriber - " << 
				subArrayStatic.at(i).getName() << std::endl;
			std::cout << " Surname subscriber - " << 
				subArrayStatic.at(i).getSurname() << std::endl;
			std::cout << " Patronymic subscriber - " <<
				subArrayStatic.at(i).getPatronymic() << std::endl;
			std::cout << " HomePhone subscriber - " << 
				subArrayStatic.at(i).getHomePhone() << std::endl;
			std::cout << " MobilPhone subscriber - " <<
				subArrayStatic.at(i).getMobilPhone() << std::endl << std::endl;
			
			std::cout << " Remove subscriber - 0" << std::endl;
			std::cout << " Continue search - 1" << std::endl;
			std::cin >> selectorTwo;
			if (!selectorTwo)
			{
				// удаляем элемент
				for (auto j(i); j < index; ++j)
				{
					subArrayStatic.at(j) = subArrayStatic.at(j + 1);
				}
				--index;
			}
		}
	}
	if (!selector)
	{
		std::cout << " There is no such subscriber!" << std::endl;
	}
}

void PhoneBook::newCopySubscriberArray()
{
	//создаём иассив на 1 больше PhoneBookArray
	if (index)
	{
		++index;
		Subscriber* newPhoneBookArray = new Subscriber[index];
		// копируем данные из PhoneBookArray в newPhoneBookArray
		Subscriber* newArray = newPhoneBookArray;
		for (Subscriber* array = subscriberArray; 
			array < subscriberArray + index - 1;++array, ++newArray)
		{
			*newArray = *array;
		}
		Subscriber* deletArray = subscriberArray;
		subscriberArray = newPhoneBookArray;
		delete[] deletArray;
	}
	else 
	{ 
		++index;
		subscriberArray = new Subscriber[index];
	}	
}
void PhoneBook::creatItemSubscriber()
{
	std::string _name, _surname, _patronym, _homePhone, _mobilPhone;
	
	std::cout << " Name subscriber - ";
	std::cin >> _name;
	(subscriberArray + index - 1)->setName(_name);
	std::cout << " Surname subscriber - ";
	std::cin >> _surname;
	(subscriberArray + index - 1)->setSurname(_surname);
	std::cout << " Patronymic subscriber - ";
	std::cin >> _patronym;
	(subscriberArray + index - 1)->setPatronymic(_patronym);
	std::cout << " HomePhone subscriber - ";
	std::cin >> _homePhone;
	(subscriberArray + index - 1)->setHomePhone(_homePhone);
	std::cout << " MobilPhone subscriber - ";
	std::cin >> _mobilPhone;
	(subscriberArray + index - 1)->setMobilPhone(_mobilPhone);
}
void PhoneBook::printSubscriberArray()
{
	for (Subscriber* array = subscriberArray;array < subscriberArray + index; ++array )
	{
		std::cout << " Name subscriber - " << array->getName() << std::endl;
		std::cout << " Surname subscriber - " << array->getSurname() << std::endl;
		std::cout << " Patronymic subscriber - " << array->getPatronymic() << std::endl;
		std::cout << " HomePhone subscriber - " << array->getHomePhone() << std::endl;
		std::cout << " MobilPhone subscriber - " << array->getMobilPhone() << std::endl;
	}
}
void PhoneBook::searchDeleteSubscriber()
{
	bool selector = false, selectorTwo;
	std::string _name, _surname, _patronym;
	std::cout << " Name subscriber - ";
	std::cin >> _name;
	std::cout << " Surname subscriber - ";
	std::cin >> _surname;
	std::cout << " Patronymic subscriber - ";
	std::cin >> _patronym;
	for (Subscriber* array = subscriberArray;
		array < subscriberArray + index; ++array)
	{
		//поиск элемента
		if (array->getName() == _name && array->getSurname() == _surname &&
			array->getPatronymic() == _patronym)
		{
			std::cout << " Name subscriber - " <<
				array->getName() << std::endl;
			std::cout << " Surname subscriber - " <<
				array->getSurname() << std::endl;
			std::cout << " Patronymic subscriber - " <<
				array->getPatronymic() << std::endl;
			std::cout << " HomePhone subscriber - " << 
				array->getHomePhone() << std::endl;
			std::cout << " MobilPhone subscriber - " <<
				array->getMobilPhone() << std::endl << std::endl;
			selector = true;
			std::cout << " Remove subscriber - 0" << std::endl;
			std::cout << " Continue search - 1" << std::endl;
			std::cin >> selectorTwo;
			if (!selectorTwo)
			{
				// удаляем элемент
				for (Subscriber* arrayTwo = array, *arrayThree = array + 1;
					arrayThree < subscriberArray + index; ++arrayTwo, ++arrayThree)
				{
					*arrayTwo = *arrayThree;
				}
				// освобождение памяти на один элемент
				--index;
				if (index)
				{
					Subscriber* newPhoneBookArray = new Subscriber[index];
					Subscriber* newArray = newPhoneBookArray;
					for (Subscriber* array = subscriberArray;
						array < subscriberArray + index; ++array, ++newArray)
					{
						*newArray = *array;
					}
					Subscriber* deletArray = subscriberArray;
					subscriberArray = newPhoneBookArray;
					delete[] deletArray;
				}
				else { break; }
		     }
		}
	}
	if (!selector)
	{
		std::cout << " There is no such subscriber!"  << std::endl;
	}
}
