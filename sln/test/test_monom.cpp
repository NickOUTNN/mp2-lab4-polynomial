#include "monom.h"
#include "gtest.h"
TEST(Monom, canCreate)
{
	EXPECT_NO_THROW(Monom m("abc", 123, 10, 3.14));
}
TEST(Monom, GetPowerInMonom_work)
{
	Monom m("abcde", 103, 10, -3.14);
	ASSERT_EQ(m.GetPowerOfVar(0), 1);
	ASSERT_EQ(m.GetPowerOfVar(1), 0);
	ASSERT_EQ(m.GetPowerOfVar(2), 3);
	ASSERT_EQ(m.GetPowerOfVar(3), 0);
	std::cout << m;
}
TEST(Monom, monom_assignment_work)
{
	Monom m("abcd", 10213300, 100, -3.14), m_c("a", 12345, 100000, 1);
	{
		Monom m1("a", 12345, 100000, 1);
		{
			m1 = m1;
		}
		m = m1;
	}
	EXPECT_EQ(m,m_c);
	std::cout << m;
}
TEST(Monom, monom_can_add)
{
	Monom m1("abcd", 10213300, 100, 1), m2("abcd", 10213300, 100, 2), m("abcd", 10213300, 100, 3);
	m1 = m2 + m1;
	EXPECT_EQ(m1, m);
}