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
	Polynom(const Polynom &l);
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
	string GetName() const;
	double Calculate(double *points);

	static bool globalNameExist()
	{
		return (globalName.length() > 0);
	}
	static void PrintGB()
	{
		string s = "polynom name "; 
		if (globalName == "")
			s += "empty";
		else s += globalName;
		s += ',';
		std::cout << s << " max pow = " << globalMaxPower << "\n\n";
	}
	static void ReadGL()
	{
		std::cout << "print name polynom\n";
		std::cin >> Polynom::globalName;
		std::cout << "print max power\n";
		std::cin >> Polynom::globalMaxPower;
	}


	friend bool operator==(const Polynom &p1, const Polynom &p2);
	friend ostream& operator<<(ostream& os, const Polynom &p);
	friend istream& operator>>(istream& is, Polynom &p)
	{
		if (!Polynom::globalNameExist())
		{
		std::cout << "print name polynom\n";
		is >> Polynom::globalName;
		std::cout << "print max power\n";
		is >> Polynom::globalMaxPower;
		std::cout << "print polynom\n";
		}
		string s;
		is >> s;
		p = Polynom(Polynom::globalName, Polynom::globalMaxPower, s);
		return is;
	}
};