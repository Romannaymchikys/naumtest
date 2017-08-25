#pragma once
#include "Pet.h"
class Humster :
	public Pet
{
public:
	Humster(std::string newShow, std::string newSound, std::string newType) :
		Pet(newShow, newSound, newType) {};
	virtual ~Humster() {};
};

