#include "monom.h"
Monom::Monom(): name("") ,power(0), maxpower(0), coef(0){}
Monom::Monom(Monom & m): name(m.name), power(m.power), maxpower(m.maxpower), coef(m.coef)
{
}
Monom::Monom(string _name, int _power, int _maxpower, double _coef): 
	 name(_name), maxpower(_maxpower), coef(_coef) 
{
	power = 0;
	int curBit = 1, count = name.length(); // curBit - ������� ������
	while (_power > 0)
	{
		power += curBit*(_power % maxpower);
		_power /= maxpower; 
		curBit *= maxpower;
		count--;
	}
	power *= pow(maxpower, count);
}

Monom::~Monom(){}

bool Monom::IsCorrect(const Monom &m)
{
	return (m.name == name && m.maxpower == maxpower && power == m.power);
}
bool Monom::CorrectMulty(const Monom &m)
{
	for (int i = 0; i < name.length(); i++)
	{
		int a = GetPowerOfVar(i);
		int b = m.GetPowerOfVar(i);
		if ((a + b) > maxpower)
			return false;
	}
	return true;
}
bool Monom::IsPositive()
{
	return (coef > 0);
}
int local::GetPower(int mypow, int maxPower, int index, int numBits)
{
	return ((mypow % (int)pow(maxPower, numBits - index)) / (int)pow(maxPower, numBits - index - 1));
}
bool Monom::EqPow(const Monom &m)
{
	return (power == m.power);
}
int Monom::GetPowerOfVar(int index) const
{
	return ((power % (int)pow(maxpower, name.length() - index)) / (int)pow(maxpower, name.length() - index - 1));
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
Monom Monom::operator+(const Monom &m)
{
	if (IsCorrect(m))
	{
		Monom tmp(*this);
		tmp.coef += m.coef;
		return tmp;
	}
	throw error_operation;
}
Monom Monom::operator-(const Monom &m)
{
	if (IsCorrect(m))
	{
		if (m.power == power)
			coef -= m.coef;
		return *this;
	}
	throw error_operation;
}
Monom Monom::operator*(const Monom &m)
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
bool Monom::operator<(const Monom &m)
{
	return power < m.power;
}
bool operator==(const Monom &m1, const Monom &m2)
{
	return (m1.name == m2.name && m1.coef == m2.coef && m1.power == m2.power || m1.coef == 0 && m2.coef == 0);
}
bool operator!=(const Monom &m1, const Monom &m2)
{
	return (!(m1 == m2));
}
ostream& operator<<(ostream& os, const Monom &m)
{
	if (m.coef == 0)
	{
		os << '0';
		return os;
	}
	if (m.coef != 1)
		os << m.coef;
	for (int i = 0; i < m.name.length(); i++)
	{
		int curP = m.GetPowerOfVar(i);
		if (curP != 0)
		{
			if (m.coef != 1 && i!= 0)
				os << '*'; //����� ��������� ����� �����������

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