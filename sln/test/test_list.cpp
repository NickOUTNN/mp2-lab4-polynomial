#include "gtest.h"
#include "list.h"

TEST(list, canPush)
{
	List <int>l;
	EXPECT_NO_THROW(l.push_front(1));
}
TEST(list, canPop)
{
	List <int>l;
	l.push_front(1);
	EXPECT_NO_THROW(l.quick_pop_front());
}
TEST(list, safely_pop)
{
	List <int>l;
	for (int i = 0; i < 10; i++)
		l.push_front(i);
	while (!l.isEmpty())
		EXPECT_NO_THROW(l.quick_pop_front());
}
TEST(list, reverce)
{
	List <int>l;
	for (int i = 0; i < 10; i++)
		l.push_front(i);
	l.reverce();
	for (int i = 0; i< 10; i++)
		EXPECT_EQ(l.quick_pop_front(), i);
}