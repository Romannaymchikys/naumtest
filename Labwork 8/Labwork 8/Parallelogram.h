#pragma once
#include "Shape.h"
#include <math.h>
class Parallelogram :
	public Shape
{
public:
	
	Parallelogram(double newFirstSide, double newSecondSide,
		                               size_t newAngle) :
		firstSide(newFirstSide), secondSide(newSecondSide),
		                              angle(newAngle) {};
		
	void setFirstSide(const double newFirstSide)   { firstSide = newFirstSide; }
	void setSecondSide(const double newSecondSide) { secondSide = newSecondSide; }
	void setAngle(const size_t newAngle)           { angle = newAngle; }

	double getFirstSide()  const { return firstSide; }
	double getSecondSide() const { return secondSide; }
	size_t getAngle()      const { return angle; }

	double getArea() const {
	    return  firstSide * secondSide * sin(angle);
	}

	virtual ~Parallelogram() {};
private:
	double  firstSide;
	double secondSide;
	
	size_t  angle;
};

