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

	static string globalName;
	static int globalMaxPower;

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
	static bool globalNameExist()
	{
		return (globalName.length() > 0);
	}


	friend bool operator==(const Polynom &p1, const Polynom &p2);
	friend ostream& operator<<(ostream& os, const Polynom &p);
	friend istream& operator>>(istream& os,  Polynom &p);
};