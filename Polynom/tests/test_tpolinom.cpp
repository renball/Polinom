#include "gtest.h"
#include <iostream>
#include "..\Polinom\TList.h"
#include "..\Polinom\TPolinom.h"

TEST(TMonom, CREATE_MONOM)
{
	ASSERT_NO_THROW(TMonom mon);
}

TEST(TPolinom, CREATE_POLINOM)
{
	ASSERT_NO_THROW(TPolinom pol);
}

TEST(TPolinom, COPY_POLINOM)
{
	TPolinom pol;
	pol.AddMonom(TMonom(1, 1, 1, 1));
	TPolinom n_pol(pol);
	EXPECT_TRUE(pol == n_pol);
}
TEST(TPolinom, CORRECT_COEFF)
{
	TPolinom pol0;
	TMonom mon0(1, 1, 1, 1);
	TMonom mon1(2, 2, 2, 2);
	pol0.AddMonom(mon0);
	pol0.AddMonom(mon1);
	TPolinom pol1;
	TMonom mon2(2, 1, 1, 1);
	TMonom mon3(4, 2, 2, 2);
	pol1.AddMonom(mon2);
	pol1.AddMonom(mon3);
	EXPECT_TRUE((pol0 * 2) == pol1);
}
TEST(TPolinom, ASSIGN_POLINOM)
{
	TPolinom pol0;
	TMonom mon0(1, 1, 1, 1);
	pol0.AddMonom(mon0);
	TPolinom pol1 = pol0;
	EXPECT_TRUE(pol0 == pol1);
}

TEST(TPolinom, ASSIGN_POLINOM_TO_ITSELF)
{
	TPolinom pol;
	TMonom mon(1, 1, 1, 1);
	pol.AddMonom(mon);
	ASSERT_NO_THROW(pol = pol);
	EXPECT_TRUE(pol == pol);
}
TEST(TPolinom, ASSIGNEP_POLINOM_IS_EQUAL)
{
	bool result = true;
	TPolinom pol0;
	TMonom mon0(1, 1, 1, 1);
	TMonom mon1(2, 2, 2, 2);
	pol0.AddMonom(mon0);
	pol0.AddMonom(mon1);
	TPolinom pol1;
	pol1 = pol0;
	EXPECT_TRUE(pol0 == pol1);
}
TEST(TPolinom, CAN_ADD_MONOM_TO_POLINOM)
{
	TPolinom pol;
	TMonom mon(1, 1, 1, 1);
	ASSERT_NO_THROW(pol.AddMonom(mon));
}
TEST(TPolinom, CORRECT_ADD_POLINOM_TO_POLINOM)
{
	TPolinom pol0;
	TMonom mon0(2, 1, 1, 1);

	TMonom mon1(1, 1, 1, 1);
	TMonom mon2(1, 2, 2, 2);


	pol0.AddMonom(mon1);
	pol0.AddMonom(mon2);

	TPolinom pol1;

	pol1.AddMonom(mon0);
	pol1.AddMonom(mon2);

	TPolinom pol_res;
	TMonom mon3(3, 1, 1, 1);
	TMonom mon4(2, 2, 2, 2);
	pol_res.AddMonom(mon4);
	pol_res.AddMonom(mon3);

	EXPECT_TRUE((pol0+pol1) == pol_res);
}
TEST(TPolinom, CORRECT_ADD_POLINOM_TO_POLINOM_2)
{
	TPolinom pol0;
	TMonom mon1(2, 1, 1, 1);
	TMonom mon1_1(1, 1, 1, 1);

	TMonom mon2(1, 2, 2, 2);
	TMonom mon2_2(5, 2, 2, 2);

	TMonom mon3(3, 3, 3, 3);
	TMonom mon3_3(-3, 3, 3, 3);

	pol0.AddMonom(mon1);
	pol0.AddMonom(mon2);
	pol0.AddMonom(mon3);

	TPolinom pol1;

	pol1.AddMonom(mon1);
	pol1.AddMonom(mon2_2);
	pol1.AddMonom(mon3_3);

	TPolinom pol_res;

	TMonom pol3(6, 2, 2, 2);
	
	pol_res.AddMonom(mon1);
	pol_res.AddMonom(pol3);


	EXPECT_TRUE((pol0 + pol1) == pol_res);
}
TEST(TPolinom, CORRECT_ADD_POLINOM_TO_POLINOM_3)
{
	TPolinom pol0;
	TMonom mon0(-1, 1, 1, 1);

	TMonom mon1(1, 1, 1, 1);
	TMonom mon2(1, 2, 2, 2);
	TMonom mon2_2(5, 2, 2, 2);
	TMonom mon3(3, 3, 3, 3);
	TMonom mon3_3(2, 3, 3, 3);


	pol0.AddMonom(mon0);
	pol0.AddMonom(mon2);
	pol0.AddMonom(mon3);

	TPolinom pol1;

	pol1.AddMonom(mon1);
	pol1.AddMonom(mon2_2);
	pol1.AddMonom(mon3_3);

	TPolinom pol_res;

	TMonom mon4(6, 2, 2, 2);
	TMonom mon5(5, 3, 3, 3);

	pol_res.AddMonom(mon4);
	pol_res.AddMonom(mon5);


	EXPECT_TRUE((pol0 + pol1) == pol_res);
}
TEST(TPolinom, CORRECT_ADD_POLINOM_TO_POLINOM_4)
{
	TPolinom pol0;
	TMonom mon(2, 1, 1, 1);

	TMonom mon1(1, 1, 1, 1);
	TMonom mon2(-5, 2, 2, 2);
	TMonom mon2_2(5, 2, 2, 2);
	TMonom mon3(3, 3, 3, 3);
	TMonom mon3_3(2, 3, 3, 3);

	TMonom mon4(6, 2, 2, 2);
	TMonom mon5(5, 3, 3, 3);


	pol0.AddMonom(mon);
	pol0.AddMonom(mon2);
	pol0.AddMonom(mon3);

	TPolinom pol1;

	pol1.AddMonom(mon1);
	pol1.AddMonom(mon2_2);
	pol1.AddMonom(mon3_3);

	TPolinom pol_res;

	pol_res.AddMonom(mon);
	pol_res.AddMonom(mon5);


	EXPECT_TRUE((pol0 + pol1) == pol_res);
}
TEST(TPolinom, CAN_MULTIPLY_MONOM_BY_POLINOM)
{
	TPolinom pol;

	TMonom mon(4, 3, 2, 1);

	TMonom mon1(1, 1, 1, 1);
	TMonom mon2(2, 2, 2, 2);
	pol.AddMonom(mon1);
	pol.AddMonom(mon2);


	TPolinom pol_res;
	TMonom mon3(8, 5, 4, 3);
	TMonom mon4(4, 4, 3, 2);
	pol_res.AddMonom(mon3);
	pol_res.AddMonom(mon4);

	EXPECT_TRUE(pol*mon == pol_res);
}
TEST(TPolinom, CAN_MULTIPLY_POLINOMS)
{
	TPolinom pol0;
	TMonom mon1(2, 2, 3, 3);
	TMonom mon2(4, 4, 4, 4);
	pol0.AddMonom(mon1);
	pol0.AddMonom(mon2);

	TMonom mon3(4, 1, 2, 2);
	TMonom mon4(1, 3, 2, 5);
	TPolinom pol1;
	TPolinom pol_res;
	pol1.AddMonom(mon3);
	pol1.AddMonom(mon4);
	TMonom mon_1_1(4, 7, 6, 9);
	TMonom mon_1_2(2, 5, 5, 8);
	TMonom mon_1_3(8, 3, 5, 5);
	pol_res.AddMonom(mon_1_1);
	pol_res.AddMonom(mon_1_2);
	pol_res.AddMonom(mon_1_3);
	

	EXPECT_TRUE(pol0 * pol1 == pol_res);
}

TEST(TList, CAN_CREATE_LIST)
{
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, NEW_LIST_IS_EMPTY)
{
	TList<int> list;
	ASSERT_TRUE(list.IsEmpty());
}

TEST(TList, LIST_WITH_ELEMENTS_IS_NOT_EMPTY)
{
	TList<int> list;
	list.InsFirst(1);
	ASSERT_TRUE(!list.IsEmpty());
}

TEST(TList, CAN_INSERT_FIRST)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsFirst(1));
}

TEST(TList, CAN_DELETE_FIRST)
{
	TList<int> list;
	list.InsLast(1); list.InsLast(2);
	list.InsLast(3); list.InsLast(4);
	ASSERT_NO_THROW(list.DelFirst());

}

TEST(TList, CAN_INSERT_LAST)
{
	TList<int> list;
	list.InsFirst(1);
	ASSERT_NO_THROW(list.InsLast(2));

}

TEST(TList, CAN_INSERT_WHEN_ELEMENT_FIRST)
{
	TList<int> list;
	list.InsFirst(1); list.InsFirst(2);
	list.InsFirst(3); list.InsFirst(4);
	list.Reset();
	ASSERT_NO_THROW(list.InsCuer(100));

}

TEST(TList, CAN_INSERT_ELEMENT_WHEN_SECOND)
{
	TList<int> list;
	list.InsFirst(1); list.InsFirst(2);
	list.InsFirst(3); list.InsFirst(4);
	list.Reset(); list.GoNext();
	ASSERT_NO_THROW(list.InsCuer(100));

}

TEST(TList, CAN_DELETE_ELEMENT_WHEN_SECOND)
{
	TList<int> list;
	list.InsLast(1); list.InsLast(2);
	list.InsLast(3); list.InsLast(4);

	list.Reset();
	list.GoNext();
	ASSERT_NO_THROW(list.DelCuer());
}

TEST(TList, CAN_INSERT_ELEMENT_WHEN_LAST)
{
	TList<int> list;
	list.InsLast(1); list.InsLast(2);
	list.InsLast(3); list.InsLast(4);

	list.Reset();
	list.GoNext(); list.GoNext();
	list.GoNext(); list.GoNext();
	ASSERT_NO_THROW(list.InsCuer(100));
}

TEST(TList, TList_CAN_DELETE_ELEMENT_WHEN_LAST)
{
	TList<int> list;
	list.InsLast(1); list.InsLast(2);
	list.InsLast(3); list.InsLast(4);

	list.Reset();
	list.GoNext(); list.GoNext();
	list.GoNext();
	ASSERT_NO_THROW(list.DelCuer());
}
