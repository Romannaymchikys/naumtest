#pragma once
class Digit
{
public:
	explicit Digit() : digit(0) { ++counter; };
	explicit Digit(int newDigit) : digit(newDigit) { ++counter; };
	explicit Digit(double newDigit) : digit((int) newDigit) { ++counter; };
	Digit(const Digit& newDigit) :digit(newDigit.digit) { ++counter; };
	Digit(Digit&& newDigit) : digit(newDigit.digit){
		newDigit.digit = 0;
		++counter;
	}

	int getDigit() const;
	static size_t getCounter();

	void setDigit(const int);

	Digit operator+(const Digit newDigit);
	Digit operator-(const Digit newDigit);
	Digit operator*(const Digit newDigit);
	Digit operator/(const Digit newDigit);
	Digit operator%(const Digit newDigit);

	bool operator> (const Digit newDigit) { return  digit >  newDigit.digit; }
	bool operator< (const Digit newDigit) { return  digit <  newDigit.digit; }
	bool operator<=(const Digit newDigit) { return  digit <= newDigit.digit; }
	bool operator>=(const Digit newDigit) { return  digit >= newDigit.digit; }
	bool operator==(const Digit newDigit) { return  digit == newDigit.digit; }
	bool operator!=(const Digit newDigit) { return  digit != newDigit.digit; }

	Digit& operator++();
	Digit& operator--();

	Digit operator+=(const int newDigit);
	Digit operator-=(const int newDigit);
	Digit operator*=(const int newDigit);
	Digit operator/=(const int newDigit);
	Digit operator%=(const int newDigit);
	
	operator int() const { return digit; }
	operator double() const { return	digit; }
	Digit operator=(const Digit newDigit);
	Digit operator()(const int newDigit);
	~Digit() {};
private:
	int digit;
	static size_t counter;
};

