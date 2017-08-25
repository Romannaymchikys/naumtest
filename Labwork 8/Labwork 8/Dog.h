#pragma once
#include "Pet.h"
class Dog :
	public Pet
{
public:
	Dog(std::string newShow, std::string newSound, std::string newType) :
		Pet(newShow, newSound, newType) {};
	virtual ~Dog() {};
};

