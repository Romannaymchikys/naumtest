#pragma once
#include "Parallelogram.h"
class Rectangle :
	public Parallelogram
{
public:
	Rectangle(const double newFirstSide,
		const double newSecondSide,
		const size_t newAngle) :
		firstSide(newFirstSide), secondSide(newSecondSide),
    	Parallelogram(newFirstSide, newFirstSide, newAngle){};
	
	void setFirstSide(const double newFirstSide) { firstSide = newFirstSide; }
	void setSecondSide(const double newSecondSide) { secondSide = newSecondSide; }
	
	double getFirstSide()  const { return firstSide; }
	double getSecondSide() const { return secondSide; }

	double getArea() const {
		return firstSide * secondSide;
	}
	virtual ~Rectangle() {};
private:
	double  firstSide;
	double secondSide;
};

