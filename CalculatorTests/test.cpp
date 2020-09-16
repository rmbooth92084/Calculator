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
/*
* Square root tests
*/
TEST(SquareRootTest1, testIntergers){
    Op* four = new Op(4);

    SquRoot* root = new SquRoot(four);
    EXPECT_EQ(root->evaluate(), 2);
}
TEST(SquareRootTest2, testNegative){
    Op* nOne = new Op(-1);

    SquRoot* root = new SquRoot(nOne);
    EXPECT_EQ(root->evaluate(), 0);
}
TEST(SquareRootTest3, testNegativeString){
    Op* nOne = new Op(-1);

    SquRoot* root = new SquRoot(nOne);
    EXPECT_EQ(root->stringify(), "MATH ERROR");
}
TEST(SquareRootTest4, testIntString){
    Op* four = new Op(4);

    SquRoot* root = new SquRoot(four);
    EXPECT_EQ(root->stringify(), "(4.000000)^(1/2)");
}
TEST(SquareRootTest5, testComboTest){
    Op* four1 = new Op(4);
    Op* four = new Op(4);

    Mult* mult = new Mult(four1, four);
    SquRoot* root = new SquRoot(mult);
    EXPECT_EQ(root->evaluate(), 4);
}
//////////////////////////////////////////////////////
/*
* Variable root tests
*/
TEST(VariableRootTest1, testIntergers){
    Op* eight = new Op(8);
    Op* three = new Op(3);

    VarRoot* root = new VarRoot(eight, three);
    EXPECT_EQ(root->evaluate(), 2);
}
TEST(VariableRootTest2, testNonInt){
    Op* eight = new Op(8);
    Op* three = new Op(0.3);

    VarRoot* root = new VarRoot(eight, three);
    EXPECT_EQ(root->evaluate(), 0);
}
TEST(VariableRootTest3, testNonIntNegativeString){
    Op* eight = new Op(8);
    Op* three = new Op(0.3);

    VarRoot* root = new VarRoot(eight, three);
    EXPECT_EQ(root->stringify(), "MATH ERROR");
}
TEST(VariableRootTest4, testIntString){
    Op* eight = new Op(8);
    Op* three = new Op(3);

    VarRoot* root = new VarRoot(eight, three);
    EXPECT_EQ(root->stringify(), "(8.000000) ^ (1 / 3.000000)");
}
TEST(VariableRootTest5, testComboTest){
    Op* two = new Op(2);
    Op* four = new Op(4);
    Op* three = new Op(3);

    Mult* mult = new Mult(two, four);
    VarRoot* root = new VarRoot(mult, three);
    EXPECT_EQ(root->evaluate(), 2);
}
//////////////////////////////////////////////////////
/*
* E^() tests
*/
TEST(eTest1, testIntergers){
    Op* four = new Op(4);

    E* test = new E(four);
    EXPECT_EQ(test->evaluate(), pow(2.718282, 4));
}
TEST(eTest2, testNegative){
    Op* nOne = new Op(-1);

    E* test = new E(nOne);
    EXPECT_EQ(test->evaluate(), pow(2.718282, -1));
}
TEST(eTest3, testNegativeString){
    Op* nOne = new Op(-1);

    E* test = new E(nOne);
    EXPECT_EQ(test->stringify(), "e ^ (-1.000000)");
}
TEST(eTest4, testIntString){
    Op* four = new Op(4);

    E* test = new E(four);
    EXPECT_EQ(test->stringify(), "e ^ (4.000000)");
}
TEST(eTest5, testComboTest){
    Op* four1 = new Op(4);
    Op* four = new Op(4);

    Mult* mult = new Mult(four1, four);
    E* test = new E(mult);
    EXPECT_EQ(test->evaluate(), pow(2.718282, 16));
}
//////////////////////////////////////////////////////
/*
* Mod tests
*/
TEST(ModTest1, testIntergersWithString){
    Op* four = new Op(4);
    Op* three = new Op(3);

    Mod* test = new Mod(three, four);
    EXPECT_EQ(test->evaluate(), 3);
    EXPECT_EQ(test->stringify(), "3.000000 % 4.000000");
}
TEST(ModTest2, testDoubleWithString){
    Op* four = new Op(4.4);
    Op* three = new Op(3);

    Mod* test = new Mod(three, four);
    EXPECT_EQ(test->evaluate(), 3);
    EXPECT_EQ(test->stringify(), "3.000000 % 4.400000");
}
TEST(ModTest3, testNegativeWithString){
    Op* nSeven = new Op(-7);
    Op* three = new Op(3);
    Mod* test = new Mod(nSeven, three);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "MATH ERROR");

}
TEST(ModTest4, testComboTest){
    Op* two = new Op(2);
    Op* four = new Op(4);
    Op* six = new Op(6);

    Mult* mult = new Mult(two, four);
    Mod* test = new Mod(mult, six);
    EXPECT_EQ(test->evaluate(), 2);
    EXPECT_EQ(test->stringify(), "2.000000 * 4.000000 % 6.000000");
}
//////////////////////////////////////////////////////
/*
* Trunc tests
*/
TEST(TruncTest1, OneOp) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Mult* mult = new Mult(first, second);
    Trunc* test = new Trunc(mult);

    EXPECT_EQ(test->stringify(), std::to_string(mult->evaluate()));
}
TEST(TruncTest2, TwoOperations) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Op* third = new Op(5);
    Mult* mult = new Mult(first, second);
    Trunc* test = new Trunc(mult);
    Add* add = new Add(third, test);

    EXPECT_EQ(add->stringify(), "5.000000 + " + std::to_string(mult->evaluate()));
}
//////////////////////////////////////////////////////
/*
* Abs tests
*/
TEST(AbsTest1, OneOpWithDecimal) {
    Op* first = new Op(8.6);
    Abs* test = new Abs(first);

    EXPECT_EQ(test->evaluate(), 8.6);
}
TEST(AbsTest2, NegitiveNumber) {
    Op* first = new Op(-8);
    Abs* test = new Abs(first);

    EXPECT_EQ(test->evaluate(), 8);
 }
//////////////////////////////////////////////////////
/*
* Paren test
*/
TEST(ParenTest, NonZeroTwoOpEquation) {
    Op* first = new Op(8);
    Op* second = new Op(7);
    Op* third = new Op(5);
    Mult* mult = new Mult(first, second);
    Paren* test = new Paren(mult);
    Add* add = new Add(third, test);

    EXPECT_EQ(add->stringify(), third->stringify() + " + (" + mult->stringify() + ")");
}
//////////////////////////////////////////////////////
/*
* Paren/Trunc comb tests
*/
TEST(ParenTruncComboTest1, ThreeOperationsComboSep) {
    Op* ten = new Op(10);
    Op* seven = new Op(7);
    Op* five = new Op(5);
    Op* three = new Op(3);
    Mult* mult = new Mult(five, three);
    Sub* sub = new Sub(ten, seven);
    Trunc* trunc = new Trunc(mult);
    Paren* paren = new Paren(sub);
    Add* add = new Add(trunc, paren);
    EXPECT_EQ(add->stringify(), "15.000000 + (10.000000 - 7.000000)");
}
TEST(ParenTruncComboTest2, FourOperationsTruncInParen) {
    Op* ten = new Op(10);
    Op* seven = new Op(7);
    Op* five = new Op(5);
    Op* three = new Op(3);
    Op* two = new Op(2);

    Mult* mult = new Mult(five, three);
    Sub* sub = new Sub(ten, seven);

    Trunc* truncMult = new Trunc(mult);
    Trunc* truncSub = new Trunc(sub);
    Add* add = new Add(truncMult, truncSub);
    Paren* paren = new Paren(add);
    Add* addTwo = new Add(two, paren);

    EXPECT_EQ(addTwo->stringify(), "2.000000 + (15.000000 + 3.000000)");
}