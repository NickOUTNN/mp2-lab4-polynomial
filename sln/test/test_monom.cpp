#include "monom.h"
#include "gtest.h"
TEST(Monom, canCreate)
{
	EXPECT_NO_THROW(Monom m("abc", 123, 10, 3.14));
}
TEST(Monom, GetPower_work)
{
	Monom m("abcd", 10213300, 100, -3.14);
	int t = local::GetPower(10213300, 100, 1);
	ASSERT_EQ(local::GetPower(10213300, 100, 0), 0);
	ASSERT_EQ(local::GetPower(10213300, 100, 1), 33);
	ASSERT_EQ(local::GetPower(10213300, 100, 2), 21);
	ASSERT_EQ(local::GetPower(10213300, 100, 3), 10);
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
/*TEST(Monom, homogeneous_monom_can_multy)
{
	Monom m("abcd", 10213300, 100, -3.14);
	std::cout << m;
}*/