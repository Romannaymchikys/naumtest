#pragma once
#include <iostream>
#include <string>
class Pet
{
public:
	Pet(std::string newShow, std::string newSound, std::string newType) :
		 show(newShow), sound(newSound), type(newType){};

	std::string  getType()  const { return  type; }
	std::string  getShow()  const { return  show; }
	std::string  getSound() const { return sound; }

	void printSound(std::string sound) {
		std::cout << sound << std::endl;
	};
	~Pet() {};
private:
	std::string  type;
	std::string  show;
	std::string sound;
	
};

