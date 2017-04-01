#include "polynom.h"
#define NodeM Node<Monom> 
#define curMon GetCurMonom()
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
Polynom& Polynom::operator=(const Polynom &p)
{
	if (this == &p)
		return *this;
	name = p.name;
	maxpower = p.maxpower;
	listM = p.listM;
	listM.setCursor();
	return *this;
}
bool Polynom::IsPositive() const
{
	if (!listM.isEmpty())
		return listM.GetpTop()->data.IsPositive();
	else return false;
}
Monom* Polynom::GetCurMonom()
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
bool Polynom::NextMonom()
{
	return listM.MoveCursor();
}

Polynom& Polynom::operator+(Polynom &pol)
{
	SetCurMonom();
	pol.SetCurMonom();
	Monom *m1 = GetCurMonom(), *m2 = pol.GetCurMonom();
	if (m1 && m2)
	while (1)
	{
		if (*m1 < *m2)
		{
			InsMonBeforeCur(m2);
			if (!pol.NextMonom())
				break;
		}
		else if (m1->EqPow(*m2)) // m1 == m2
		{	
			*m1 = *m1 + *m2;
			if (!NextMonom())
			{
				while (pol.NextMonom())
					InsMonAfterCur(m2);
				break;
			}				
			if (!pol.NextMonom())
				break;
		}
		else // m1 > m2
		{
			if (!NextMonom())
				break;
		}
	}
	if (!NextMonom())
	{
		while (pol.NextMonom())
			InsMonAfterCur(m2);
	}
	return *this;
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
		if (m1->IsPositive()) os << '+';
		os << *m1;
		p1 = p1->next;
	}
	return os;
}