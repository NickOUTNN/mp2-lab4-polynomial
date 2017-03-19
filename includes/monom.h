#pragma once
#define error_operation 0
#define error_max_power 1
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

namespace local
{
	int GetPower(int mypow, int maxPower, int index);
}
class Monom
{
private:
	string name;
	int power;
	int maxpower;
	double coef;
public:
	Monom();
	Monom(string _name, int _power, int _maxpower, double _coef);
	~Monom();
	bool IsCorrect(const Monom &m);
	bool CorrectMulty(const Monom &m);
	bool EqPow(const Monom &m);

	Monom& operator=(const Monom &m);
	Monom& operator+(const Monom &m);
	Monom& operator-(const Monom &m);
	Monom& operator*(const Monom &m);
	bool operator<(const Monom &m);
	friend bool operator==(const Monom &m1, const Monom &m2);
	friend bool operator!=(const Monom &m1, const Monom &m2);
	friend ostream& operator<<(ostream& os, const Monom &m);
	friend ostream& operator>>(istream& os, const Monom &m);
};
