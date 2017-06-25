#pragma once
class Point
{
	float x;
	float y;
public:
	Point(float newX, float newY) :
		x(newX), y(newY) {}
	Point() :x(0), y(0) {}
	
	float getX() const;
	float getY()const;
	void setX(const float);
	void setY(const float);
	~Point() {}
};
