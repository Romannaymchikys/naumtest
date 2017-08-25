#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
public:
	Circle(const double newRadius) : radius(newRadius) {};

	virtual ~Circle() {};
private:
	double radius;
};

