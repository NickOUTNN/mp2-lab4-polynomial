#pragma once
#include "list.h"
#include "monom.h"
class Polynom
{
private:
	List <Monom> listM;
	int maxpower;
	string name;
	Polynom(const Polynom &l);
	Polynom(Polynom &l);
public:
	Polynom();
	Polynom(string _name, int _maxpower, List<Monom> &l);

	Polynom& operator=(const Polynom &p);
	Polynom& operator+(const Polynom &p);
	Polynom& operator-(const Polynom &p);
	Polynom& operator*(const Polynom &p);

	bool IsPositive() const;
	friend bool operator==(const Polynom &p1, const Polynom &p2);
	friend ostream& operator<<(ostream& os, const Polynom &p);
	friend ostream& operator>>(istream& os, const Polynom &p);
};