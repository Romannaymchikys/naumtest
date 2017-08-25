#pragma once
#include "bird.h"
#include "Pet.h"
class parrot :
	public bird, public Pet
{
public:
	parrot(std::string newShow, std::string newSound, std::string newType) :
		bird(newShow, newSound, newType), Pet(newShow, newSound, newType){};
	virtual ~parrot() {};
};

