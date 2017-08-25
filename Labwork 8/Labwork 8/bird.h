#pragma once
#include "Pet.h"
class bird :
	public Pet

{
public:
	bird(std::string newShow, std::string newSound, std::string newType) :
		Pet(newShow, newSound, newType) {};
	virtual ~bird() {};
};

