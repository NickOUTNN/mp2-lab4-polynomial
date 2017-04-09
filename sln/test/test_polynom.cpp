#include "polynom.h"
#include "gtest.h"
#include <iostream>
using std::cout;
TEST(polynom, canCreate)
{
	List<Monom> l;
	Monom m1("abc", 123, 10, 3.14);
	Monom m2("abc", 13, 10, 3.14);
	Monom m3("abc", 1, 10, 3.14);
	l.push_back(m1);
	l.push_back(m2);
	l.push_back(m3);
	EXPECT_NO_THROW(Polynom pol("abc", 10, l));
}
TEST(polynom, can_assignment)
{
	List<Monom> l;
	Monom m1("abc", 123, 10, 3.14);
	Monom m2("abc", 13, 10, 3.14);
	l.push_back(m1);
	l.push_back(m2);
	Polynom pol1("abc", 10, l);
	Polynom pol2;
	EXPECT_NO_THROW(pol2 = pol1);
}

TEST(polynom, uneq_true)
{
	List<Monom> l1, l2;
	Monom m1("abcde", 321, 10, -1);
	Monom m2("abcde", 10301, 10, 2);
	Monom m3("abcde", 11100, 10, 1);

	l1.push_back(m1);
	l1.push_back(m2);

	l2.push_back(m3);

	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);
	cout << pol1 << '\n' << pol2;
	EXPECT_FALSE(pol1 == pol2);
}
TEST(polynom, eq_true)
{
	List<Monom> l1, l2;
	Monom m1("abcde", 111, 10, 1);
	Monom m2("abcde", 10101, 10, 2);

	l1.push_back(m1);
	l1.push_back(m2);

	l2.push_back(m1);
	l2.push_back(m2);

	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);
	cout << pol1 << '\n' << pol2;
	EXPECT_TRUE(pol1 == pol2);
}

TEST(polynom, can_add1)
{
	List<Monom> l1, l2;
	Monom m1("abcde", 11100, 10, 3);
	l1.push_back(m1);
	l2.push_back(m1);
	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);

	pol1 += pol2;
	cout << pol1;
}
TEST(polynom, can_add2)
{
	List<Monom> l1, l2;
	Monom m1("abcde", 11101, 10, 3), m2("abcde", 2, 10, 3);
	l1.push_back(m1);
	l2.push_back(m2);
	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);
	pol2 = pol1 + pol2;
	cout << pol2 <<'\n';
}
TEST(polynom, can_add3)
{
	List<Monom> l1, l2;
	Monom m1("abcde", 11101, 10, 3), m2("abcde", 2, 10, 3), m3("abcde", 21, 10, 5);
	l1.push_back(m2);
	l1.push_back(m1);
	l2.push_back(m3);
	l2.push_back(m2);
	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);
	cout << pol1 << '+' << pol2 << " = " << pol1 + pol2 << '\n';
}
TEST(polynom, can_add4)
{
	List<Monom> l1, l2;
	Monom m1("abcde", 11101, 10, 3), m2("abcde", 2, 10, 3), m3("abcde", 21, 10, 5);
	l1.push_back(m2);
	l1.push_back(m1);
	l2.push_back(m3);
	l2.push_back(m2);
	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);

	Polynom res;
	res += (Polynom)m1;
	res += (Polynom)m2;
	res += pol2;

	cout << pol1 << '+' << pol2 << " = " << pol1 + pol2 << '\n'<<res;
	EXPECT_EQ(res, pol2 + pol1);
}

TEST(polynom, stringToPolynom1)
{
	Polynom pol("abcd", 10, "3.14*a^9*b+2d-3");
	cout << pol;
}
TEST(polynom, stringToPolynom2)
{
	Polynom pol1("abcd", 100, "3.14*a^91*b^1+2abd-12b^3*c^12d^39+3");
	Polynom pol2("ab", 10, "a");
	Polynom pol3("ab", 10, "-b");
	cout << pol1 << '\n' << pol2 << '\n' << pol3;
}
TEST(polynom, stringToPolynom3)
{
	Polynom pol1("abc", 100, "3.14a^17b-36b");
	cout << pol1 ;
}
TEST(polynom, CanAdd5)
{
	Polynom pol1("ab", 10, "3b");
	Polynom pol2("ab", 10, "a");
	Polynom pol3("ab", 10, "-7b");
	cout << pol1 + pol2 + pol3;
}
TEST(polynom, CanMulty1)
{
	Polynom pol1("ab", 10, "3b");
	Polynom pol2("ab", 10, "-2*a");
	Polynom pol3("ab", 10, "-6*ab");
	cout << pol1 * pol2;
	EXPECT_EQ(pol1 * pol2, pol3);
}
TEST(polynom, CanMulty2)
{
	Polynom pol1("abc", 10, "3.14a^2b");
	Polynom pol2("abc", 10, "-2*a*c^9");
	Polynom pol3("abc", 10, "-6.28*a^3bc^9");
	cout << pol1 * pol2;
	EXPECT_EQ(pol1 * pol2, pol3);
}
TEST(polynom, CanNotMulty1)
{
	Polynom pol1("abc", 10, "3.14a^2b");
	Polynom pol2("abc", 10, "-2*a^9*c^9");
	EXPECT_ANY_THROW(pol1 * pol2);
}


TEST(_end, end)
{
	system("pause");
}
