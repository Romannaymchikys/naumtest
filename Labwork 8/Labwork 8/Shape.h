#pragma once
class Shape
{
public:
	virtual double getArea() const { return Area; }
	void setArea(const double newArea) { Area = newArea; }
	virtual ~Shape() {};
private:
	double Area;
}; 


