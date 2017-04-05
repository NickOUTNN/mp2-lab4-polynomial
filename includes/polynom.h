#pragma once
#include "list.h"
#include "monom.h"
class Polynom
{
private:
	List <Monom> listM;
	int maxpower;
	string name;
	Monom ConvertStringToMonom(char *st, char *&end);
	Monom* GetCurMonom() const;
	void SetCurMonom();
	void InsMonAfterCur(Monom* m);
	void InsMonBeforeCur(Monom* m);
	void InsMonom(Monom *m);
	bool IsCorrect(Polynom &p);
	bool NextMonom();
public:
	Polynom();
	Polynom(string _name, int _maxpower, List<Monom> &l);
	Polynom(Polynom &l);
	Polynom(Monom &m);
	Polynom(int n, Monom *m);
	Polynom(string name, int maxp, string s);

	Polynom& operator=(const Polynom &p);
	Polynom& operator+=(Polynom &p);
	Polynom operator+(Polynom &p);
	Polynom operator-(Polynom &p);
	Polynom operator*(Polynom &p);
	Polynom operator*(Monom &m);

	bool IsPositive() const;
	int GetLength() const;

	friend bool operator==(const Polynom &p1, const Polynom &p2);
	friend ostream& operator<<(ostream& os, const Polynom &p);
	friend ostream& operator>>(istream& os, const Polynom &p);
};