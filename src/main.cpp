#include "polynom.h"
#include <string>
#include <iostream>
#include <map>
#define pol(n, p) std::pair<int,Polynom>(n,p)
#define polM(index) m.find(index)->second
#define polName(it) it->second.GetName()
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
	string menu = {"1 Добавить многочлен \n2 Удалить многочлен\n3 Выполнить арифмитическое действие\n"};
	menu += "4 Задать формат полинома\n5 Вывести формат полинома\n6 Вывести список полиномов\n7 Вычислить полином в точке\nq Выход\n";
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
			else cout << "polynoms don't found\n";

		}
		else if (s == "4")
		{
			system("cls");
			Polynom::ReadGL();		
		}
		else if (s == "5")
		{
			system("cls");
			Polynom::PrintGB();
		}
		else if (s == "6")
		{
			system("cls");
			cout << "LIST:\nnumber polynom\n";
			for (auto el : m)
				cout << el.first << " " << el.second << "\n";
		}		
		else if (s == "7")
		{
			system("cls");
			cout << "LIST: number polynom\n";
			for (auto el : m)
				cout << el.first << " " << el.second << "\n";
			int num;
			cout << "print number of polynom\n";
			cin >> num;
			auto it = m.find(num);
			if (it != m.end())
			{
				cout << "print value of variable\n";
				string name = polName(it);
				double *points = new double[name.length()];
				for (int i = 0; i < name.length(); i++)
				{
					cout << "val of " << name[i] <<' ';
					cin >> points[i];
				}
				cout << "answer = " << it->second.Calculate(points)<<'\n';
				delete[] points;
			}
			else cout << "polynom don't found\n";
		}
		else system("cls");

	}
	return 0;
}