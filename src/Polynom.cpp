#include "polynom.h"
Polynom::Polynom() : name(""), maxpower(0)
{
	Monom m;
	pol.push_front(m);
}