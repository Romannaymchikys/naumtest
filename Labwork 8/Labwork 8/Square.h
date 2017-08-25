#pragma once
#include "Rectangle.h"
class Square :
	public Rectangle
{
public:
	Square(const double newFirstSide,
		   const double newSecondSide,
		   const size_t newAngle) :
		side(newFirstSide),
		Rectangle(newFirstSide, newFirstSide, newAngle) {};

	void setSide(const double newSide) { side = newSide; }
	
	double getSide()  const { return side; }
	
	double getArea() const {
		return side * side;
	}
	virtual ~Square() {};
private:
	double  side;
};

