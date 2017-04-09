#pragma once
#define error_operation 0
#define error_max_power 1
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Monom
{
private:
	string name;
	int power;
	int maxpower;
	double coef;
public:
	Monom();
	Monom(Monom &m);
	Monom(string _name, int _power, int _maxpower, double _coef);
	bool IsCorrect(const Monom &m);
	bool CorrectMulty(const Monom &m);
	bool EqPow(const Monom &m);
	bool IsPositive();
	int GetPowerOfVar(int index) const;
	void SetPowerOfVar(char var, int pow);
	double Calculate(double *points);

	Monom& operator=(const Monom &m);
	Monom operator+(const Monom &m);
	Monom operator-(const Monom &m);
	Monom operator*(const Monom &m);
	Monom operator*=(const Monom &m);

	bool operator<(const Monom &m);
	friend bool operator==(const Monom &m1, const Monom &m2);
	friend bool operator!=(const Monom &m1, const Monom &m2);
	friend ostream& operator<<(ostream& os, const Monom &m);
	friend class Polynom;
};
