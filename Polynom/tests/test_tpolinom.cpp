#include "gtest.h"
#include <iostream>
#include "..\Polinom\TList.h"
#include "..\Polinom\TPolinom.h"

TEST(TList, CanCreateNewList)
{
	ASSERT_NO_THROW(TList<int> t);
}

TEST(TList, NewCreatedListIsEmpty)
{
	TList<int> t;
	ASSERT_TRUE(t.IsEmpty());
}

TEST(TList, NotEmptyListIsNotEmpty)
{
	TList<int> t;
	t.InsFirst(10);

	ASSERT_TRUE(!t.IsEmpty());
	ASSERT_TRUE(t.IsNotEmpty());
}

TEST(TList, CanInsertFirstElement)
{
	TList<int> t;
	ASSERT_NO_THROW(t.InsFirst(1));
}

TEST(TList, CanInsertLastElement)
{
	TList<int> t;
	t.InsFirst(1);
	ASSERT_NO_THROW(t.InsLast(2));
}

TEST(TList, CanInsertCurrentElementWhenFirst)
{
	TList<int> t;
	t.InsFirst(1); t.InsFirst(2);
	t.InsFirst(3); t.InsFirst(4);

	t.Reset();
	ASSERT_NO_THROW(t.InsCurr(100));
}

TEST(TList, CanInsertCurrentElementWhenSecond)
{
	TList<int> t;
	t.InsFirst(1); t.InsFirst(2);
	t.InsFirst(3); t.InsFirst(4);

	t.Reset(); t.GoNext();
	ASSERT_NO_THROW(t.InsCurr(100));
}

TEST(TList, CanInsertCurrentElementWhenPenultimate)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext(); t.GoNext();
	t.GoNext();

	ASSERT_NO_THROW(t.InsCurr(100));

	std::cout << "\t     " << t << '\n';
}

TEST(TList, CanInsertCurrentElementWhenLast)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext(); t.GoNext();
	t.GoNext(); t.GoNext();

	ASSERT_NO_THROW(t.InsCurr(100));

	std::cout << "\t     " << t << '\n';
}

TEST(TList, CanDeleteFirstElement)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	ASSERT_NO_THROW(t.DelFirst());

	std::cout << "\t     " << t << '\n';
}

TEST(TList, CanDelete2CurrentElementsWhenFirst)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();

	ASSERT_NO_THROW(t.DelCurr());
	ASSERT_NO_THROW(t.DelCurr());

	std::cout << "\t     " << t << '\n';
}

TEST(TList, CanDeleteCurrentElementWhenSecond)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext();

	ASSERT_NO_THROW(t.DelCurr());

	std::cout << "\t     " << t << '\n';
}

TEST(TList, CanDeleteCurrentElementWhenPenultimate)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext(); t.GoNext();

	ASSERT_NO_THROW(t.DelCurr());

	std::cout << "\t     " << t << '\n';
}

TEST(TList, CanDeleteCurrentElementWhenLast)
{
	TList<int> t;
	t.InsLast(1); t.InsLast(2);
	t.InsLast(3); t.InsLast(4);

	t.Reset();
	t.GoNext(); t.GoNext();
	t.GoNext();

	ASSERT_NO_THROW(t.DelCurr());

	std::cout << "\t     " << t << '\n';
}

TEST(TPolinom, CanCreateNewPolynom)
{
	ASSERT_NO_THROW(TPolynom t);
}

TEST(TPolinom, CanCreatePolynomFromString)
{
	TPolinom t("2xyz+0.5xz");

	TPolinom correct;
	correct.AddMonom(2, 1, 1, 1);
	correct.AddMonom(0.5, 1, 0, 1);

	EXPECT_EQ(t, correct);
}

TEST(TPolinom, NewCreatedPolynomIsZero)
{
	TPolinom t;
	ASSERT_EQ(t.ToStr(), "0");
}

TEST(TPolinom, CanCreateCopiedPolynom)
{
	TPolinom t;
	ASSERT_NO_THROW(TPolinom t2(t));
}

TEST(TPolinom, CanAssignPolynoms)
{
	TPolinom t1;
	t1.AddMonom(2, 0, 0, 0);

	TPolinom t2;

	ASSERT_NO_THROW(t2 = t1);
	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = t1 = " << t2 << '\n';
	EXPECT_EQ(t1.ToStr(), t2.ToStr());
}

TEST(TPolinom, CanAssignPolynomToItself)
{
	TPolinom t;
	t.AddMonom(2, 0, 0, 0);

	ASSERT_NO_THROW(t = t);
	std::cout << "\t     t = " << t << '\n';
	EXPECT_EQ(t.ToStr(), t.ToStr());
}

TEST(TPolinom, CanAddMonomToPolynom)
{
	TPolinom t;
	TMonom mon(1, 1, 1, 1);
	ASSERT_NO_THROW(t.AddMonom(mon));
	std::cout << "\t     t = " << t << '\n';
}

TEST(TPolinom, CanAddPolynomToPolynom_1)
{
	TPolinom t1;
	TMonom mon1(1, 1, 0, 0);
	t1.AddMonom(mon1);
	TMonom mon2(1, 1, 0, 0);
	t1.AddMonom(mon2);

	TPolinom t2;
	TMonom mon3(-1, 1, 0, 0);
	t2.AddMonom(mon3);

	TMonom mon3(-1, 0, 0, 0);
	t2.AddMonom(mon3);

	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = " << t2 << '\n';

	TPolinom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	std::cout << "\t     t1 + t2 = " << sum << '\n';

	TPolinom correct;

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanAddPolynomToPolynom_2)
{
	TPolinom t1;
	t1.AddMonom(1, 1, 0, 0);
	t1.AddMonom(1, 0, 0, 0);

	TPolinom t2;
	t2.AddMonom(-1, 1, 0, 0);

	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = " << t2 << '\n';

	TPolinom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	std::cout << "\t     t1 + t2 = " << sum << '\n';

	TPolinom correct;
	correct.AddMonom(1, 0, 0, 0);

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanAddPolynomToPolynom_3)
{
	TPolynom t1;
	t1.AddMonom(1, 1, 0, 0);
	t1.AddMonom(1, 0, 0, 0);

	TPolynom t2;
	t2.AddMonom(-1, 0, 0, 0);

	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = " << t2 << '\n';

	TPolynom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	std::cout << "\t     t1 + t2 = " << sum << '\n';

	TPolynom correct;
	correct.AddMonom(1, 1, 0, 0);

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanAddPolynomToPolynom_4)
{
	TPolynom t1;
	t1.AddMonom(1, 0, 1, 1);
	t1.AddMonom(2, 1, 0, 1);
	t1.AddMonom(3, 1, 1, 1);

	TPolynom t2;
	t2.AddMonom(1, 0, 1, 1);
	t2.AddMonom(-2, 1, 0, 1);
	t2.AddMonom(3, 1, 1, 1);

	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = " << t2 << '\n';

	TPolynom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	std::cout << "\t     t1 + t2 = " << sum << '\n';

	TPolynom correct;
	correct.AddMonom(6, 1, 1, 1);
	correct.AddMonom(2, 0, 1, 1);

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanAddPolynomToPolynom_5)
{
	TPolynom t1;
	t1.AddMonom(1, 2, 2, 2);
	t1.AddMonom(3, 0, 0, 2);

	TPolynom t2;
	t2.AddMonom(1, 2, 2, 1);
	t2.AddMonom(-2, 0, 0, 2);
	t2.AddMonom(1, 0, 0, 1);

	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = " << t2 << '\n';

	TPolynom sum;
	ASSERT_NO_THROW(sum = t1 + t2);

	std::cout << "\t     t1 + t2 = " << sum << '\n';

	TPolynom correct;
	correct.AddMonom(1, 2, 2, 2);
	correct.AddMonom(1, 2, 2, 1);
	correct.AddMonom(1, 0, 0, 2);
	correct.AddMonom(1, 0, 0, 1);

	EXPECT_EQ(sum, correct);
}

TEST(TPolynom, CanSubstractPolynomFromPolynom)
{
	TPolynom t1;
	t1.AddMonom(1, 0, 1, 1);
	t1.AddMonom(2, 1, 0, 1);
	t1.AddMonom(3, 1, 1, 1);

	TPolynom t2;
	t2.AddMonom(1, 0, 1, 1);
	t2.AddMonom(-2, 1, 0, 1);
	t2.AddMonom(3, 1, 1, 1);

	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = " << t2 << '\n';

	TPolynom difference;
	ASSERT_NO_THROW(difference = t1 - t2);

	std::cout << "\t     t1 - t2 = " << difference << '\n';

	TPolynom correct;
	correct.AddMonom(4, 1, 0, 1);

	EXPECT_EQ(difference, correct);
}

TEST(TPolynom, CanMultiplyPolynomByZeroDouble)
{
	TPolynom t;
	t.AddMonom(1, 0, 1, 1);
	t.AddMonom(2, 1, 0, 1);
	t.AddMonom(3, 1, 1, 1);

	std::cout << "\t     t = " << t << '\n';

	TPolynom result;
	ASSERT_NO_THROW(result = 0 * t);

	std::cout << "\t     0 * t = " << result << '\n';

	EXPECT_EQ(result, TPolynom());
}

TEST(TPolynom, CanMultiplyPolynomByDouble)
{
	TPolynom t;
	t.AddMonom(1, 0, 1, 1);
	t.AddMonom(2, 1, 0, 1);
	t.AddMonom(3, 1, 1, 1);

	TPolynom result;
	ASSERT_NO_THROW(result = -10 * t);

	std::cout << "\t     t = " << t << '\n';
	std::cout << "\t     (-10) * t = " << result << '\n';

	TPolynom correct;
	correct.AddMonom(-10, 0, 1, 1);
	correct.AddMonom(-20, 1, 0, 1);
	correct.AddMonom(-30, 1, 1, 1);

	EXPECT_EQ(result, correct);
}

TEST(TPolynom, CanMultiplyPolynomByMonom)
{
	TPolynom t;
	t.AddMonom(1, 0, 1, 0);
	t.AddMonom(1, 1, 0, 0);

	TMonom m(2, 1, 0, 1);

	std::cout << "\t     t = " << t << '\n';

	TPolynom result;
	ASSERT_NO_THROW(result = t * m);

	std::cout << "\t     t * 2*xz = " << result << '\n';

	TPolynom correct;
	correct.AddMonom(2, 2, 0, 1);
	correct.AddMonom(2, 1, 1, 1);

	EXPECT_EQ(result, correct);
}

TEST(TPolynom, CanMultiplyPolynomByPolynom)
{
	TPolynom t1;
	t1.AddMonom(1, 1, 0, 0);

	TPolynom t2;
	t2.AddMonom(2, 0, 1, 1);
	t2.AddMonom(0.5, 0, 0, 1);

	std::cout << "\t     t1 = " << t1 << '\n';
	std::cout << "\t     t2 = " << t2 << '\n';

	TPolynom result;
	ASSERT_NO_THROW(result = t1 * t2);

	std::cout << "\t     t1 * t2 = " << result << '\n';

	TPolynom correct;
	correct.AddMonom(2, 1, 1, 1);
	correct.AddMonom(0.5, 1, 0, 1);

	EXPECT_EQ(result, correct);
}