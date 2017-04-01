#include "gtest.h"
#include "list.h"
class test
{
public:
	List<int> *l;
	int ShowElement(int ind)
	{
		Node<int> *i = l->head;
		for (int j = 0; j < ind && i != 0; i = i->next)
		{
			j++;
		}
		return i->data;
	}
	test(List<int> *l1) : l (l1) {}
};
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
TEST(list, canMoveCursor)
{
	List <int>l;
	for (int i = 0; i < 10; i++)
		l.push_front(i);
	l.setCursor();
	bool f = l.MoveCursor();
	test t(&l);
	
	EXPECT_EQ(f, true);
	EXPECT_EQ(l.GetCursor()->data, t.ShowElement(1));
}

TEST(list, workMoveCursor)
{
	List <int>l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	l.setCursor();
	int test, i = 0;
	while (l.MoveCursor())
	{
		i++;
		test = l.GetCursor()->data;
		EXPECT_EQ(test, i);
	}
	EXPECT_EQ(i, 9);
}