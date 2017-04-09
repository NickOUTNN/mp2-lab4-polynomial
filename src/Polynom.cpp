#include "polynom.h"
#define NodeM Node<Monom> 
#define curMon GetCurMonom()
string Polynom::globalName = "";
int Polynom::globalMaxPower = 0;
Polynom::Polynom() : name(""), maxpower(0)
{
	Monom m;
	listM.push_front(m);
	listM.setCursor();
}
Polynom::Polynom(string _name, int _maxpower, List<Monom> &l): name(_name), maxpower(_maxpower), listM(l)
{
	l.setCursor();
}
Polynom::Polynom(const Polynom &p)
{
	name = p.name;
	maxpower = p.maxpower;
	listM = p.listM;
}
Polynom::Polynom(Monom & m): name(m.name), maxpower(m.maxpower)
{
	listM.push_back(m);
}
Polynom::Polynom(int n, Monom *m)
{
	List <Monom>l;
	for (int i = 0; i < n; i++)
		l.push_back(m[i]);
	Polynom(m->name, m->maxpower, l);
}
Polynom::Polynom(string n, int maxp, string s)
{
	Polynom pol;
	name = n;
	maxpower = maxp;

	char *st = &s[0];
	char *end = st;

	while (*end != '\0')
	{
		*this += (Polynom)ConvertStringToMonom(st, end);
		st = end;
	}
}
Polynom& Polynom::operator=(const Polynom &p)
{
	if (this == &p)
		return *this;
	name = p.name;
	maxpower = p.maxpower;
	listM = p.listM;
	return *this;
}
bool Polynom::IsPositive() const
{
	if (!listM.isEmpty())
		return listM.GetpTop()->data.IsPositive();
	else return false;
}
int Polynom::GetLength() const
{
	return listM.length;
}
string Polynom::GetName() const
{
	return name;
}
double Polynom::Calculate(double * points)
{
	double val = 0;
	SetCurMonom();
	Monom *m1 = GetCurMonom();
	while (m1)
	{
		val += m1->Calculate(points);
		NextMonom();	
		m1 = GetCurMonom();
	}
	return val;
}
Monom Polynom::ConvertStringToMonom(char *st, char *& end)
{
	double coef = strtod(st, &end);
	st = end;
	if (coef == 0)
		if (*st == '-')
		{
			coef = -1;
			st++;
			end++;
		}
		else if (*st == '+')
		{
			coef = 1;
			st++;
			end++;
		}
		else if (*st >= 'a' && *st <= 'z')
			coef = 1;
		else throw 5;

	Monom m(name, 0, maxpower, coef);
	char tmp;
	tmp = *end;
	while (tmp == '*' || tmp >= 'a' && tmp <= 'z' &&  tmp != '\0')
	{
		if (tmp == '*')
		{
			end++;
			st = end;
		}
		else if (*(end + 1) == '^')
		{
			st = end + 2;
			int k = strtol(st, &end, 10);
			m.SetPowerOfVar(tmp, k);
		}
		else if (*(end + 1) =='\0' || *(end + 1) >= 'a' && *(end + 1) <= 'z' || *(end + 1) == '*' || *(end + 1) == '+' || *(end + 1) == '-')
		{
			m.SetPowerOfVar(tmp, 1);
			end++;
		}
		tmp = *end;
	}
	if (tmp == '+' || tmp == '-' || tmp == '\0')
		return m;
	throw 5;
}
Monom* Polynom::GetCurMonom() const
{
	return &(listM.GetCursor()->data);
}

void Polynom::SetCurMonom()
{
	listM.setCursor();
}

void Polynom::InsMonAfterCur(Monom *m)
{
	listM.push_after_cursor(m);
}
void Polynom::InsMonBeforeCur(Monom * m)
{
	listM.push_before_cursor(m);
}
void Polynom::InsMonom(Monom * m)
{
	listM.push_back(*m);
}
bool Polynom::IsCorrect(Polynom & p)
{
	return (name == p.name && maxpower == p.maxpower);
}
bool Polynom::NextMonom()
{
	return listM.MoveCursor();
}

Polynom& Polynom::operator+=(Polynom &pol)
{
	if (name.length() == 0)
		*this = pol;
	else
	{
		if (IsCorrect(pol))
		{
			SetCurMonom();
			pol.SetCurMonom();
			Monom *m1 = GetCurMonom(), *m2 = pol.GetCurMonom();
			while (m1 && m2)
			{
				if (*m1 < *m2)			// m1 < m2
				{
					InsMonBeforeCur(m2);
					pol.NextMonom();
				}
				else if (m1->EqPow(*m2)) // m1 == m2
				{
					*m1 = *m1 + *m2;
					NextMonom();
					pol.NextMonom();
				}
				else					// m1 > m2
					NextMonom();
				m1 = GetCurMonom();
				m2 = pol.GetCurMonom();
			}
			while (m2)
			{
				InsMonBeforeCur(m2);
				pol.NextMonom();
				m2 = pol.GetCurMonom();
			}
		}
	}
	return *this;
}
Polynom Polynom::operator+(Polynom &pol)
{
	Polynom polr;
	if (IsCorrect(pol))
	{
		SetCurMonom();
		pol.SetCurMonom();
		Monom *m1 = GetCurMonom(), *m2 = pol.GetCurMonom();
		while (m1 && m2)
		{
			if (*m1 < *m2)
			{
				polr.InsMonom(m2);
				pol.NextMonom();
			}
			else if (m1->EqPow(*m2))
			{
				polr.InsMonom(&(*m1 + *m2));
				pol.NextMonom();
				NextMonom();
			}
			else
			{
				polr.InsMonom(m1);
				NextMonom();
			}
			m1 = GetCurMonom();
			m2 = pol.GetCurMonom();
		}
			while (m1)
			{
				polr.InsMonom(m1);
				NextMonom();
				m1 = GetCurMonom();
			}
			while (m2)
			{
				polr.InsMonom(m2);
				pol.NextMonom();
				m2 = pol.GetCurMonom();
			}
			polr.name = name;
			polr.maxpower = maxpower;
	}
	
	return polr;
}
Polynom Polynom::operator-(Polynom & pol)
{
	Polynom polr;
	if (IsCorrect(pol))
	{
		SetCurMonom();
		pol.SetCurMonom();
		Monom *m1 = GetCurMonom(), *m2 = pol.GetCurMonom();
		while (m1 && m2)
		{
			if (*m1 < *m2)
			{
				polr.InsMonom(m2);
				pol.NextMonom();
			}
			else if (m1->EqPow(*m2))
			{
				polr.InsMonom(&(*m1 - *m2));
				pol.NextMonom();
				NextMonom();
			}
			else
			{
				polr.InsMonom(m1);
				NextMonom();
			}
			m1 = GetCurMonom();
			m2 = pol.GetCurMonom();
		}
		while (m1)
		{
			polr.InsMonom(m1);
			NextMonom();
			m1 = GetCurMonom();
		}
		while (m2)
		{
			polr.InsMonom(m2);
			pol.NextMonom();
			m2 = pol.GetCurMonom();
		}
		polr.name = name;
		polr.maxpower = maxpower;
	}

	return polr;
}
Polynom Polynom::operator*(Polynom &pol)
{
	if (IsCorrect(pol))
	{
		pol.SetCurMonom();
		Polynom res;
		Monom *m = pol.GetCurMonom();
		while (m)
		{
			res += *this * (*m);
			pol.NextMonom();
			m = pol.GetCurMonom();
		}
		return res;
	}
	throw 3;
}
Polynom Polynom::operator*(Monom & m2)
{
	Polynom res(*this);
	res.SetCurMonom();
	Monom *m1 = res.GetCurMonom();
	while (m1)
	{
		*m1 *= m2;
		res.NextMonom();
		m1 = res.GetCurMonom();
	}
	return res;
}
bool operator==(const Polynom & p1, const Polynom & p2)
{
	return (p1.name == p2.name && p1.maxpower == p2.maxpower && p1.listM == p2.listM);
}
ostream& operator<<(ostream& os, const Polynom &pol)
{
	Node<Monom> *p1 = pol.listM.GetpTop();
	Monom *m1;
	if (p1 != 0)
	{
		m1 = &(p1->data);
		os << *m1;
		p1 = p1->next;
	}
	while (p1 != 0)
	{
		m1 = &(p1->data);
		if (m1->IsPositive()) os << " + ";
		else os << " ";
		os << *m1;
		p1 = p1->next;
	}
	return os;
}
