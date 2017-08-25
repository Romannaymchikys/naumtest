#pragma once
#include "Pet.h"
#include <iostream>
class Cat : public Pet
{
public:
	Cat(std::string newShow, std::string newSound, std::string newType) :
		Pet(newShow, newSound, newType) {};
	virtual ~Cat() {};
};

