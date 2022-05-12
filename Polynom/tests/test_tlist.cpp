#include "gtest.h"
#include <iostream>
#include "..\mp2-lab5-list\TList.h"


TEST(TList, CAN_CREATE_LIST)
{
	ASSERT_NO_THROW(TList<int> t);
}

TEST(TList, NEW_LIST_IS_EMPTY)
{
	TList<int> t;
	ASSERT_TRUE(t.IsEmpty());
}

TEST(TList, LIST_WITH_ELEMENTS_IS_NOT_EMPTY)
{
	TList<int> t;
	t.InsFirst(1);
	ASSERT_TRUE(!t.IsEmpty());
}

TEST(TList, CAN_INSERT_FIRST)
{
	TList<int> t;
	ASSERT_NO_THROW(t.InsFirst(1));
}

TEST(TList, CAN_DELETE_FIRST)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);
	ASSERT_NO_THROW(t.DelFirst());

}

TEST(TList, CAN_INSERT_LAST)
{
	TList<int> t;
	t.InsFirst(1);
	ASSERT_NO_THROW(t.InsLast(2));
	
}

TEST(TList, CAN_INSERT_WHEN_ELEMENT_FIRST)
{
	TList<int> t;
	t.InsFirst(1); t.InsFirst(2);
	t.InsFirst(3); t.InsFirst(4);
	t.Reset();
	ASSERT_NO_THROW(t.InsCuer(100));

}

TEST(TList, CAN_INSERT_ELEMENT_WHEN_SECOND)
{
	TList<int> t;
	t.InsFirst(1); t.InsFirst(2);
	t.InsFirst(3); t.InsFirst(4);
	t.Reset(); t.GoNext();
	ASSERT_NO_THROW(t.InsCuer(100));
	
}

TEST(TList, CAN_DELETE_ELEMENT_WHEN_SECOND)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext();
	ASSERT_NO_THROW(t.DelCuer());
}

TEST(TList, CAN_INSERT_ELEMENT_WHEN_LAST)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext(); t.GoNext();
	t.GoNext(); t.GoNext();
	ASSERT_NO_THROW(t.InsCuer(100));
}

TEST(TList, TList_CAN_DELETE_ELEMENT_WHEN_LAST)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext(); t.GoNext();
	t.GoNext();
	ASSERT_NO_THROW(t.DelCuer());
}
