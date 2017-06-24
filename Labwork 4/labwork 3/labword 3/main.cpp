#include "subscriber.h"
#include "PhoneBook.h"
#include "Test.h"
#include "MyVector.h"

#include <iostream>
#include <array>

void main2()
{ 
	Subscriber subscriber("Ivan", "Ivanov",
		"Ivanovich", "+375172343434", "+375172343434");
	subscriber.Print();
	subscriber.setName("Alex");
	subscriber.setSurname("Alexov");
	subscriber.setPatronymic("Alexeev");
	subscriber.setHomePhone("111111");
	subscriber.setMobilPhone("22222");
	subscriber.Print();

	std::string allSubscriber = subscriber.getInfo();
	std::cout << allSubscriber << std::endl;
	std::cout << std::endl;
	std::cout << Subscriber::getCounter() << std::endl;
}

void TestSubscriberArrayDin(){
	Subscriber* subArray = new Subscriber[10];
	for (Subscriber* pt = subArray; pt < subArray + 10; ++pt)
	{
		pt->Print();
	}
	delete[] subArray;
}

void TestSubscriberArrayStat(){
	Subscriber subscriberArray[2] = 
	{ Subscriber("Ivan", "Ivanov", "Ivanovich", "+375172343434", "+375172343434"),
		Subscriber("Iv", "Ivanov", "Inovich", "+343434", "+375172343434") };
	for (size_t i(0); i < 2; ++i)
	{
		subscriberArray[i].Print();
	}
}
void TestSubscriberArrayStat2(){
	std::array<Subscriber, 2> subscriberArray;
}
// task 1
int TestPhoneBookDynamic(){
	size_t number = 1;
	PhoneBook phoneBook;
	phoneBook.setIndex(0);
	while (number)
	{
		std::cout << "0 - exit\n";
		std::cout << "1 - adding contacts \n";
		std::cout << "2 - View contacts \n";
		std::cout << "3 - Search for contacts and delete contacts \n";
		std::cin >> number;
		switch (number)
		{
		case(0): return 0;
		case(1): 
			phoneBook.newCopySubscriberArray();
			phoneBook.creatItemSubscriber();
			break;
		case(2):
			phoneBook.printSubscriberArray();
			break;
		case(3):
			phoneBook.searchDeleteSubscriber();
			break;
		}	
	}
}
float TestPhoneBookStatic(){
	size_t number = 1;
	PhoneBook phoneBook;
	phoneBook.setIndex(0);
	while (number)
	{
		std::cout << "0 - exit\n";
		std::cout << "1 - adding contacts \n";
		std::cout << "2 - View contacts \n";
		std::cout << "3 - Search for contacts and delete contacts \n";
		std::cin >> number;
		switch (number)
		{
		case(0): return 0;
		case(1):
			phoneBook.creatItemSubscriberStatic();
			break;
		case(2):
			phoneBook.printSubscriberArrayStatic();
			break;
		case(3):
			phoneBook.searchDeleteSubscriberStatic();
			break;
		}
	}
}
void TestMyVectorOperator(){
	const size_t vec_size = 1024;
	Test test;
	MyVector v = test.createVector(vec_size);
	std::cout << v[1] << std::endl;
	MyVector v1, v2;
	v1 = v2;
	v2 = v1 + v2;
}
int main()
{
	//main2();
	//TestSubscriberArrayDin();
	//TestSubscriberArrayStat();
	//TestSubscriberArrayStat2();
	//Task 1
	//TestPhoneBookDynamic();
	//TestPhoneBookStatic();
	//Task 2
	//Test t;
	//t.test();
    //Task2(Labwork 4)
	TestMyVectorOperator();
	system("pause");
	return 0;
}