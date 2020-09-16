#include "pch.h"
#include "../Calculator/headers.h"
/*
* These are all the tests for op code
*/
TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);

}
TEST(OpTestDecimal, OpEvaluateNonZeroDecimal) {
    Op* test = new Op(1.2);
    EXPECT_EQ(test->evaluate(), 1.2);

}
TEST(OpTestString, OpEvaluateNonZeroString) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), std::to_string(test->evaluate()));

}
TEST(OpTestDoubleDige, OpEvaluateNonZeroDoubleDig) {
    Op* test = new Op(1238);
    EXPECT_EQ(test->evaluate(), 1238);

}
//////////////////////////////////////////////////////
/*
*  Mult tests
*/
TEST(MultTest, MultEvaluateNonZero) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Mult* test = new Mult(first, second);
    EXPECT_EQ(test->evaluate(), 56);
}
TEST(MultTest, MultAndPow) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Pow* test2 = new Pow(first, second);
    Mult* test = new Mult(first, test2);
    EXPECT_EQ(test->evaluate(), 16777216);
}

TEST(MultTestString, MultEvaluateNonZeroString) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Mult* test = new Mult(first, second);
    EXPECT_EQ(test->stringify(), first->stringify() + " * " + second->stringify());
}
//////////////////////////////////////////////////////
/*
* Pow tests
*/
TEST(PowTest, PowEvaluateNonZero) {
    Op* base = new Op(2);
    Op* expo = new Op(4);
    Pow* test = new Pow(base, expo);
    EXPECT_EQ(test->evaluate(), 16);
}
TEST(PowTest3, PowWithMult) {
    Op* base = new Op(2);
    Op* expo = new Op(4);
    Mult* test2 = new Mult(base, expo);
    Pow* test = new Pow(test2, expo);
    EXPECT_EQ(test->evaluate(), 4096);
}

TEST(PowTest2, PowEvaluateNonZeroString) {
    Op* base = new Op(2);
    Op* expo = new Op(4);
    Pow* test = new Pow(base, expo);
    EXPECT_EQ(test->stringify(), base->stringify() + " ** " + expo->stringify());
}
//////////////////////////////////////////////////////
/*
* Add tests
*/
TEST(AddTest, AddEvaluateNonZero) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Add* test = new Add(first, second);
    EXPECT_EQ(test->evaluate(), 6);
}
TEST(AddTest2, AddWithMult) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Mult* test = new Mult(first, second);
    Add* test2 = new Add(test, second);
    EXPECT_EQ(test2->evaluate(), 12);
}

TEST(AddTest3, AddEvaluateNonZeroString) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Add* test = new Add(first, second);
    EXPECT_EQ(test->stringify(), first->stringify() + " + " + second->stringify());
}
//////////////////////////////////////////////////////
/*
* Subtract tests
*/
TEST(SubTest, SubEvaluateNonZero) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Sub* test = new Sub(first, second);
    EXPECT_EQ(test->evaluate(), -2);
}
TEST(SubTest2, SubWithMult) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Mult* test = new Mult(first, second);
    Sub* test2 = new Sub(test, second);
    EXPECT_EQ(test2->evaluate(), 4);
}

TEST(SubTest3, SubEvaluateNonZeroString) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Sub* test = new Sub(first, second);
    EXPECT_EQ(test->stringify(), first->stringify() + " - " + second->stringify());
}
//////////////////////////////////////////////////////
/*
* Division tests
*/
TEST(DivTest, DivEvaluateNonZero) {
    Op* first = new Op(8);
    Op* second = new Op(4);
    Div* test = new Div(first, second);
    EXPECT_EQ(test->evaluate(), 2);
}
TEST(DivTest2, DivWithMult) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Mult* test = new Mult(first, second);
    Div* test2 = new Div(test, second);
    EXPECT_EQ(test2->evaluate(), 2);
}

TEST(DivTest3, DivEvaluateNonZeroString) {
    Op* first = new Op(2);
    Op* second = new Op(4);
    Div* test = new Div(first, second);
    EXPECT_EQ(test->stringify(), first->stringify() + " / " + second->stringify());
}
//////////////////////////////////////////////////////
/*
* Factorial tests
*/
TEST(FactorialTest1, testIntergersWithString){
    Op* four = new Op(4);

    Factorial* test = new Factorial(four);
    EXPECT_EQ(test->evaluate(), 24);
    EXPECT_EQ(test->stringify(), "!4.000000");
}
TEST(FactorialTest2, testDoubleWithString)
{
    Op* four = new Op(4.4);

    Factorial* test = new Factorial(four);
    EXPECT_EQ(test->evaluate(), 24);
    EXPECT_EQ(test->stringify(), "!4.400000");
}
TEST(FactorialTest3, testNegativeWithString){
    Op* nSeven = new Op(-7);

    Factorial* test = new Factorial(nSeven);
    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "1");

}
TEST(FactorialTest4, testComboTest){
    Op* two = new Op(2);
    Op* four = new Op(4);

    Mult* mult = new Mult(two, four);
    Factorial* test = new Factorial(mult);
    EXPECT_EQ(test->evaluate(), 40320);
    EXPECT_EQ(test->stringify(), "!" + mult->stringify());
}
//////////////////////////////////////////////////////