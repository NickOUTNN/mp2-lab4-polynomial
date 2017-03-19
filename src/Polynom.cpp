#include "polynom.h"
Polynom::Polynom() : name(""), maxpower(0)
{
	Monom m;
	listM.push_front(m);
}

Polynom::Polynom(string _name, int _maxpower, List<Monom> &l): name(_name), maxpower(_maxpower), listM(l){}
Polynom& Polynom::operator=(const Polynom &p)
{
	if (this == &p)
		return *this;
	name = p.name;
	maxpower = p.maxpower;
	listM = p.listM;
	return *this;
}
bool operator==(const Polynom &p1, const Polynom &p2)
{
	return (p1.name == p2.name && p1.maxpower == p2.maxpower && p1.listM == p2.listM);
}
Polynom& Polynom::operator+(const Polynom &pol)
{
	Node<Monom> *p1, *p2, *p = 0;
	p1 = listM.GetpTop();
	p2 = pol.listM.GetpTop();
	Monom *m1 = &(p1->data);
	Monom *m2 = &(p2->data);
	while (p1 && p2)
	{
		m1 = &(p1->data);
		m2 = &(p2->data);
		if (*m1 < *m2)
		{
			//insert m2
			p2 = p2->next;
		}
		else if (m1->EqPow(*m2))
		{
			*m1 = *m1 + *m2;
			p = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			p = p1;
			p1 = p1->next;
		}
	}
	while (p2 != 0)
	{
		listM.push_back(p2->data);
		p2 = p2->next;
	}
	return *this;
}
ostream& operator<<(ostream& os, const Polynom &pol)
{
	Node<Monom> *p1 = pol.listM.GetpTop();
	Monom *m1 = &(p1->data);
	return os;
}