#include "polynom.h"
#include <string>
#include <iostream>
#include <map>
#define pol(n, p) std::pair<int,Polynom>(n,p)
#define polM(index) m.find(index)->second
using std::map;
using std::cout;
using std::cin;



int main()
{
	map<int, Polynom> m;
	int numPol = 0;
	Polynom p;
	setlocale(LC_ALL, "Russian");
	string s;
	string menu = {"1 Добавить многочлен \n2 Удалить многочлен\n"};
	menu += "3 Выполнить арифмитическое действие\n4 Задать формат полинома\n5 Вывести список полиномов\n";
	while (s != "q")
	{
		cout << menu;
		cin >> s;

		if (s == "1")
		{
			system("cls");
			cin >> p;
			m.insert(pol(numPol++, p));
		}
		else if (s == "2")
		{
			system("cls");
			cout << "LIST: number polynom\n";
			for (auto el : m)
				cout << el.first << " " << el.second << "\n";
			cin >> s;
			if (s == "q")
				s.clear();
			else
			{
				int c = std::atoi(&s[0]);
				m.erase(c);
			}

		}
		else if (s == "3")
		{
			system("cls");
			cout << "LIST: number polynom\n";
			for (auto el : m)
				cout << el.first << " " << el.second << "\n";
			cout << "print \"number polynom1\" + or - or * \"number polynom2\"\n" ;
			int n1, n2;			
			char op;
			cin >> n1 >> op >> n2;			
			if (m.count(n1) && m.count(n2))
			{
				switch (op)
				{
				case '+': 
					p = polM(n1) + polM(n2);
					m.insert(pol(numPol++, p)); 
					cout << "results: " << p <<" num=" << numPol << "\n"; break;

				case '-': 
					p = polM(n1) - polM(n2);
					m.insert(pol(numPol++,p)); 
					cout << "results: " << p <<" num="<< numPol<<"\n"; break;

				case '*': 
					p = polM(n1) * polM(n2);
					m.insert(pol(numPol++, p)); 
					cout << "results: " << p <<" num="<< numPol<<"\n"; break;

				default: cout << "there is no this operator";			break;
				}
			}

		}
		else if (s == "4")
		{
			system("cls");
			Polynom::ReadGL();		
		}
		else if (s == "5")
		{
			system("cls");
			cout << "LIST: number polynom\n";
			for (auto el : m)
				cout << el.first << " " << el.second << "\n";
		}

	}
	return 0;
}