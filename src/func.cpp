#include "func.h"
//быстрое возведение снизу вверх
double qp(double base, int p, int pcur, int &pnow)
{
	double val;
	if (2 * pcur <= p)
		val = qp(base*base, p, 2 * pcur, pnow);
	else
	{
		pnow = pcur;
		return base;
	}
	while (pnow + pcur <= p)
	{
		pnow += pcur;
		val *= base;
	}
	return val;
}
//быстрое возведение сверху вниз
//...