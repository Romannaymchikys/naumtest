#pragma once

class Digit
{
public:
	explicit Digit() : digit(0) { ++counter; };
	explicit Digit(int newDigit) : digit(newDigit) { ++counter; };
	explicit Digit(double newDigit) : digit((int) newDigit) { ++counter; };
	Digit(const Digit& newDigit) :digit(newDigit.digit) { ++counter; };
	Digit(Digit&& newDigit) : digit(newDigit.digit){// ”неверсальна€ ссылка &&
		newDigit.digit = 0;
		++counter;
	}

	int getDigit() const;
	static size_t getCounter();

	void setDigit(const int);
	
	Digit operator+(const Digit&) const;// cтавить ссылку потомучто тип Digit может быть весомым и нам необходимо передавать его, а не копию работать с ним
	Digit operator-(const Digit&) const;
	Digit operator*(const Digit&) const;
	Digit operator/(const Digit&) const;
	Digit operator%(const Digit&) const;
	Digit operator+(const int) const;
	Digit operator-(const int) const;
	Digit operator*(const int) const;
	Digit operator/(const int) const;
	Digit operator%(const int) const;

	bool operator> (const Digit& newDigit) const { return  digit >  newDigit.digit; }
	bool operator< (const Digit& newDigit) const { return  !(*this >  newDigit); }
	bool operator<=(const Digit& newDigit) const { return  digit <= newDigit.digit; }
	bool operator>=(const Digit& newDigit) const { return  !(*this >  newDigit); }
	bool operator==(const Digit& newDigit) const { return  digit == newDigit.digit; }
	bool operator!=(const Digit& newDigit) const { return  !(*this == newDigit); }

	Digit& operator++();
	Digit& operator--();

	Digit& operator+=(const int newDigit);
	Digit& operator-=(const int newDigit);
	Digit& operator*=(const int newDigit);
	Digit& operator/=(const int newDigit);
	Digit& operator%=(const int newDigit);
	
	operator int() const    { return digit; }
	operator double() const { return digit; }
	Digit& operator=(const Digit& newDigit);// присваивание
	Digit& operator()(const int newDigit);
	~Digit() {};
private:
	int digit;
	static size_t counter;
};

