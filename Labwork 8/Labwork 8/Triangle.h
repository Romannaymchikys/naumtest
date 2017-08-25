#pragma once
#include "Shape.h"
#include <math.h>
#include <iostream>
class Triangle :
	public Shape
{
public:
	bool test(double firstComparator, double secondComparator)
	{
		return firstComparator > secondComparator;
	}
	// по трем сторанам
	Triangle(double newFirstSide, double newSecondSide,
		                          double newThirdSide) :
		firstSide(newFirstSide), secondSide(newSecondSide),
		                          thirdSide(newThirdSide) {
		// проверяем является ли трехугольником
		if (test(firstSide + secondSide, thirdSide) ||
			test(firstSide + thirdSide, secondSide) ||
			test(secondSide + thirdSide, firstSide) )
		{
			firstAngle  = (acos((thirdSide * thirdSide  +
			                    secondSide * secondSide -
				                 firstSide * firstSide) /
				            (2 * thirdSide * secondSide))) * 180 / 3.14;

			secondAngle = (acos((thirdSide * thirdSide +
				                 firstSide * firstSide -
				                secondSide * secondSide) /
				            (2 * thirdSide * firstSide))) * 180 / 3.14;
			//можно по теореме синусов
			//secondAngle = (sin(secondSide * sin(firstAngle) / 
			//                              firstSide)) * 180 / 3.14;
			thirdAngle = 180 - (firstAngle + secondAngle);
     	}
	};
				
	// по двум сторонам и углу между ними
	Triangle(double newFirstSide, double newSecondSide,
		                          size_t newThirdAngle) :
		firstSide(newFirstSide), secondSide(newSecondSide),
		thirdAngle(newThirdAngle) {
		thirdSide = sqrt(firstSide * firstSide + secondSide * secondSide - 
			         2 * firstSide * secondSide  * cos(thirdAngle));

		firstAngle = (asin((firstSide / thirdSide) *
			           sin(thirdAngle))) * 180 / 3.14;

		secondAngle = (asin((secondSide / thirdSide) *
			           sin(thirdAngle))) * 180 / 3.14;
	}
	// по двум углам и староне между ними
	Triangle(double newFirstSide, size_t newThirdAngle,
		                          size_t newSecondAngle) :
		firstSide(newFirstSide), thirdAngle(newThirdAngle),
		secondAngle(newSecondAngle) {
		firstAngle = 180 - (thirdAngle + secondAngle);
		
		secondSide = (firstSide * sin(secondAngle)) / sin(firstAngle);
		thirdSide = (firstSide * sin(thirdAngle)) / sin(firstAngle);
	}
    // основной конструктор
	Triangle(double newFirstData, double newSecondData,
		double newThirdData, int _flags) {
		switch (_flags)
		{
		case 0: *this = Triangle(newFirstData, newSecondData, newThirdData);
			break;
		case 1: *this = Triangle(newFirstData, newSecondData,
			                                   (size_t)newThirdData);
			break;
		case 2: *this = Triangle(newFirstData, (size_t)newSecondData,
			                                   (size_t)newThirdData);
			break;
		 default: break;
		}
	}

	double getArea() const {
		double p = (firstSide + secondSide + thirdSide) / 2;
		return sqrt(p*(p - firstSide)*(p - secondSide)*(p - thirdSide));
	}

	void setFirstSide (const double newFirstSide)  { firstSide  = newFirstSide;  }
	void setSecondSide(const double newSecondSide) { secondSide = newSecondSide; }
	void setThirdSide (const double newThirdSide)  { thirdSide  = newThirdSide;  }

	void setFirstAngle (const size_t newfirstAngle)  { firstAngle  =  newfirstAngle; }
	void setSecondAngle(const size_t newSecondAngle) { secondAngle = newSecondAngle; }
	void setThirdAngle (const size_t newThirdAngle)  { thirdAngle  =  newThirdAngle; }

	double getFirstSide()  const { return firstSide;  }
	double getSecondSide() const { return secondSide; }
	double getThirdSide()  const { return thirdSide;  }

	size_t getFirstAngle()  const { return firstAngle;  }
	size_t getSecondAngle() const { return secondAngle; }
	size_t getThirdAngle()  const { return thirdAngle;  }

	virtual ~Triangle() {};

private:
	int _flags;

	double  firstSide;
	double secondSide;
	double  thirdSide;

	size_t  firstAngle;
	size_t secondAngle;
	size_t  thirdAngle;

};
