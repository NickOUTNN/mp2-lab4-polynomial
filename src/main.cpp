#include "polynom.h"
#include <string>
#include <iostream>
#include <map>
#define pol(n, p) std::pair<int,Polynom>(n,p)
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
	string menu = {"1 Добавить многочлен \n2 Удалить многочлен\n3 Выбрать многочлен\n"};
	menu += "4 Выполнить арифмитическое действие\n5 Задать формат полинома\n";
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

		}
		else if (s == "4")
		{

		}
		else if (s == "5")
		{
			system("cls");
			Polynom::ReadGL();		
		}
		//system("cls");

	}
	return 0;
}