#include "polynom.h"
#include "gtest.h"
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
	Monom m1("abcde", 111, 10, 1);
	Monom m2("abcde", 10101, 10, 2);
	Monom m3("abcde", 11100, 10, 1);
	Monom m4("abcde", 1, 10, 3);
	Monom m5("abcde", 0, 10, 1);

	l1.push_back(m1);
	l1.push_back(m2);
	//l1.push_back(m3);
	//l1.push_back(m4);
	//l1.push_back(m5);

	l2.push_back(m1);
	//l2.push_back(m2);
	l2.push_back(m3);
	//l2.push_back(m4);
	//l2.push_back(m5);

	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);
	EXPECT_FALSE(pol1 == pol2);
}

TEST(polynom, eq_true)
{
	List<Monom> l1, l2;
	Monom m1("abcde", 111, 10, 1);
	Monom m2("abcde", 10101, 10, 2);
	Monom m3("abcde", 11100, 10, 1);
	Monom m4("abcde", 1, 10, 3);
	Monom m5("abcde", 0, 10, 1);

	l1.push_back(m1);
	l1.push_back(m2);
	//l1.push_back(m3);
	//l1.push_back(m4);
	//l1.push_back(m5);

	l2.push_back(m1);
	l2.push_back(m2);
	//l2.push_back(m3);
	//l2.push_back(m4);
	//l2.push_back(m5);

	Polynom pol1("abcde", 10, l1);
	Polynom pol2("abcde", 10, l2);
	EXPECT_TRUE(pol1 == pol2);
}

TEST(_end, end)
{
	system("pause");
}
