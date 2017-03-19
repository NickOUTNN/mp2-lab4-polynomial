#include "monom.h"
Monom::Monom(): power(0), coef(0){}
Monom::Monom(string _name, int _power, int _maxpower, double _coef): 
	 name(_name), power(_power), maxpower(_maxpower), coef(_coef) {}
Monom::~Monom()
{
	
}

bool Monom::IsCorrect(const Monom &m)
{
	return (m.name == name && m.maxpower == maxpower);
}
bool Monom::CorrectMulty(const Monom &m)
{
	for (int i = 0; i < name.length(); i++)
	{
		int a = local::GetPower(power, maxpower, i);
		int b = local::GetPower(m.power, m.maxpower, i);
		if ((a + b) > maxpower)
			return false;
	}
	return true;
}
int local::GetPower(int mypow, int maxPower, int index)
{
	return (mypow % (int)pow(maxPower, (index + 1)) / pow(maxPower, index));
}

Monom& Monom::operator=(const Monom &m)
{
	if (this == &m)
	return *this;
	name = m.name;
	coef = m.coef;
	power = m.power;
	maxpower = m.maxpower;
	return *this;
}
Monom& Monom::operator+(const Monom &m)
{
	if (IsCorrect(m))
	{
		if (m.power == power)
			coef += m.coef;
		return *this;
	}
	throw error_operation;
}
Monom& Monom::operator-(const Monom &m)
{
	if (IsCorrect(m))
	{
		if (m.power == power)
			coef -= m.coef;
		return *this;
	}
	throw error_operation;
}
Monom& Monom::operator*(const Monom &m)
{
	if (IsCorrect(m))
	{
		if (CorrectMulty(m))
		{
			power += m.power;
			coef *= m.coef;
			return *this;
		}
		throw error_max_power;
	}
	throw error_operation;
}
bool operator==(const Monom &m1, const Monom &m2)
{
	return (m1.name == m2.name && m1.coef == m2.coef && m1.power == m2.power || m1.coef == 0 && m2.coef == 0);
}
ostream& operator<<(ostream& os, const Monom &m)
{
	if (m.coef == 0)
		return os;
	if (m.coef != 1)
		os << m.coef;
	for (int i = 0; i < m.name.length(); i++)
	{
		int curP = local::GetPower(m.power, m.maxpower, i);
		if (curP != 0)
		{
			if (i != 0 || m.coef != 1)
			os << '*'; //вывод умножения между переменными
			os << m.name[i];
			if (curP != 1)
			{
				os << '^';
				os << curP;
			}
		}
	}
	return os;
}
/*ostream& operator>>(istream& os, const Monom &m)
{

}*/