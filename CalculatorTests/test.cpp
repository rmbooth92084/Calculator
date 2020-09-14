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
