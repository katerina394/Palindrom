#include <gtest/gtest.h>
#include "palindrom.h"

TEST(IsPalindrom,when_list_0)
{
    CNode *list=0;

    EXPECT_TRUE(IsPalindrom(list));
}

TEST(IsPalindrom,when_there_is_one_list_item)
{
	CNode *list=new CNode;
	list->data=1;
	list->next=0;

	EXPECT_TRUE(IsPalindrom(list));

	delete list;
}

TEST(IsPalindrom,IsPalindrom_works_correctly_with_expectation_of_false)
{
	CNode *list=0;
    for (int i=5; i>0; i--)
	{
		CNode *node=new CNode;
		node->next=list;
		node->data=i;
		list=node;
	}

	EXPECT_FALSE(IsPalindrom(list));

	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}	

TEST(IsPalindrom,IsPalindrom_works_correctly_with_even_length_palindrom)
{
	CNode *list=0;
    CNode *node=new CNode;
	node->next=list;
	node->data=1;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=2;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=2;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=1;
	list=node;

	EXPECT_TRUE(IsPalindrom(list));

	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}

TEST(IsPalindrom,IsPalindrom_works_correctly_with_odd_length_palindrom)
{
	CNode *list=0;
    CNode *node=new CNode;
	node->next=list;
	node->data=1;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=2;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=1;
	list=node;

	EXPECT_TRUE(IsPalindrom(list));

	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}