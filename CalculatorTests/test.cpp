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
//////////////////////////////////////////////////////
/*
* TwoPow tests
*/
TEST(TwoPowTest1, OneOp) {
    Op* eight = new Op(8);
    TwoPow* test = new TwoPow(eight);

    EXPECT_EQ(test->evaluate(), 256);
    EXPECT_EQ(test->stringify(), "2 ^ (" + eight->stringify() + ")");
}
TEST(TwoPowTest2, OneNegativeOp) {
    Op* three = new Op(-3);
    TwoPow* test = new TwoPow(three);

    EXPECT_EQ(test->evaluate(), 0.125);
    EXPECT_EQ(test->stringify(), "2 ^ (" + three->stringify() + ")");
}
TEST(TwoPowTest3, Zero) {
    Op* zero = new Op(0);
    TwoPow* test = new TwoPow(zero);

    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "2 ^ (" + zero->stringify() + ")");
}
TEST(TwoPowTest4, Combo) {
    Op* three = new Op(3);
    Op* four = new Op(4);
    Add* add = new Add(three, four);

    TwoPow* test = new TwoPow(add);

    EXPECT_EQ(test->evaluate(), 128);
    EXPECT_EQ(test->stringify(), "2 ^ (" + add->stringify() + ")");
}

//////////////////////////////////////////////////////
/*
* Cos tests
*/
TEST(CosTest1, OneOpPI) {
    Op* pi = new Op(PI);
    Cos* test = new Cos(pi);

    EXPECT_EQ(test->evaluate(), -1);
    EXPECT_EQ(test->stringify(), "cos(" + pi->stringify() + ")");
}
TEST(CosTest2, Zero) {
    Op* zero = new Op();
    Cos* test = new Cos(zero);

    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "cos(" + zero->stringify() + ")");
}

TEST(CosTest3, Combo) {
    Op* pi = new Op(PI);;
    Add* add = new Add(pi, pi);

    Cos* test = new Cos(add);

    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "cos(" + add->stringify() + ")");
}
//////////////////////////////////////////////////////
/*
* Sin tests
*/
TEST(SinTest1, OneOpPI) {
    Op* pi = new Op(PI);
    Sin* test = new Sin(pi);

    EXPECT_EQ(test->evaluate(), sin(PI));
    EXPECT_EQ(test->stringify(), "sin(" + pi->stringify() + ")");
}
TEST(SinTest2, OneOpPIOvertwo) {
    Op* pi = new Op(PI/2);
    Sin* test = new Sin(pi);

    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "sin(" + pi->stringify() + ")");
}

TEST(SinTest3, Combo) {
    Op* pi = new Op(PI);
    Op* onePointFive = new Op(1.5);
    Mult* add = new Mult(pi, onePointFive);

    Sin* test = new Sin(add);

    EXPECT_EQ(test->evaluate(), -1);
    EXPECT_EQ(test->stringify(), "sin(" + add->stringify() + ")");
}
//////////////////////////////////////////////////////
/*
* tan tests
*/
TEST(TanTest1, OneOpPIDivFour) {
    Op* pi = new Op(PI/4);
    Tan* test = new Tan(pi);

    EXPECT_EQ(test->evaluate(), tan(PI/4));
    EXPECT_EQ(test->stringify(), "tan(" + pi->stringify() + ")");
}
TEST(TanTest2, OneOpPIOvertwo) {
    Op* pi = new Op(PI / 2);
    Tan* test = new Tan(pi);

    EXPECT_EQ(test->evaluate(), tan(PI / 2));
    EXPECT_EQ(test->stringify(), "tan(" + pi->stringify() + ")");
}

TEST(TanTest3, Combo) {
    Op* pi = new Op(PI);
    Op* onePointFive = new Op(1.5);
    Mult* add = new Mult(pi, onePointFive);

    Tan* test = new Tan(add);

    EXPECT_EQ(test->evaluate(), tan(PI * 1.5));
    EXPECT_EQ(test->stringify(), "tan(" + add->stringify() + ")");
}
//////////////////////////////////////////////////////
/*
* Bubble sort tests
*/
//This test makes sure that it can sort a basic list
TEST(BubbleSortTest1, SortingBasicList){
    std::vector<int> test = { 9,8,7,6,5,4,3,2,1,0 };
    int sorted[] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(BubbleSort(test).at(i), sorted[i]);
    }

}

TEST(BubbleSortTest2, SortingBasicListWithNegatives){
    std::vector<int> test = { 9,-8,7,6,-5,4,-3,2,-1,0 };
    int sorted[] = { -8,-5,-3,-1,0,2,4,6,7,9 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(BubbleSort(test).at(i), sorted[i]);
    }

}

TEST(BubbleSortTest3, SortingBasicListWithMultiDigitNums){
    std::vector<int> test = { 90,8,700,6,5,40,3,26,12,0 };
    int sorted[] = { 0,3,5,6,8,12,26,40,90,700 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(BubbleSort(test).at(i), sorted[i]);
    }

}

TEST(BubbleSortTest4, AlreadySortedList){
    std::vector<int> test = { 1,2,3,4,5 };
    int sorted[] = { 1,2,3,4,5 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(BubbleSort(test).at(i), sorted[i]);
    }

}

TEST(BubbleSortTest5, OneNumberLongList){
    std::vector<int> test = { 0 };
    int sorted[] = { 0 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(BubbleSort(test).at(i), sorted[i]);
    }

}

TEST(BubbleSortTest6, EmptyList){
    std::vector<int> test = {};

    EXPECT_EQ(BubbleSort(test), test);


}
//////////////////////////////////////////////////////
/*
* Merge sort tests
*/
TEST(MergeSortTest1, SortingBasicList){
    std::vector<int> vec = { 9,8,7,6,5,4,3,2,1,0 };
    int sorted[] = { 0,1,2,3,4,5,6,7,8,9 };

    std::vector<int> test = MergeSort(vec);
    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(test.at(i), sorted[i]);
    }

}
TEST(MergeSortTest2, SortingBasicListWithNegatives){
    std::vector<int> vec = { 9,-8,7,6,-5,4,-3,2,-1,0 };
    int sorted[] = { -8,-5,-3,-1,0,2,4,6,7,9 };

    std::vector<int> test = MergeSort(vec);
    for (int i = 0; i < test.size(); i++)
    {
        std::cout << test.at(i) << std::endl;
    }
    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(test.at(i), sorted[i]);
    }

}

TEST(MergeSortTest3, SortingBasicListWithMultiDigitNums){
    std::vector<int> test = { 90,8,700,6,5,40,3,26,12,0 };
    int sorted[] = { 0,3,5,6,8,12,26,40,90,700 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(MergeSort(test).at(i), sorted[i]);
    }

}

TEST(MergeSortTest4, AlreadySortedList){
    std::vector<int> test = { 1,2,3,4,5 };
    int sorted[] = { 1,2,3,4,5 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(MergeSort(test).at(i), sorted[i]);
    }

}

TEST(MergeSortTest5, OneNumberLongList){
    std::vector<int> test = { 0 };
    int sorted[] = { 0 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(MergeSort(test).at(i), sorted[i]);
    }

}

TEST(MergeSortTest6, EmptyList){
    std::vector<int> test = {};

    EXPECT_EQ(MergeSort(test), test);


}
//////////////////////////////////////////////////////
/*
* Quick sort tests
*/
TEST(QuickSortTest1, SortingBasicList){
    std::vector<int> test = { 9,8,7,6,5,4,3,2,1,0 };
    int sorted[] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(QuickSort(test).at(i), sorted[i]);
    }

}

TEST(QuickSortTest2, SortingBasicListWithNegatives){
    std::vector<int> test = { 9,-8,7,6,-5,4,-3,2,-1,0 };
    int sorted[] = { -8,-5,-3,-1,0,2,4,6,7,9 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(QuickSort(test).at(i), sorted[i]);
    }

}

TEST(QuickSortTest3, SortingBasicListWithMultiDigitNums){
    std::vector<int> test = { 90,8,700,6,5,40,3,26,12,0 };
    int sorted[] = { 0,3,5,6,8,12,26,40,90,700 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(QuickSort(test).at(i), sorted[i]);
    }

}

TEST(QuickSortTest4, AlreadySortedList){
    std::vector<int> test = { 1,2,3,4,5 };
    int sorted[] = { 1,2,3,4,5 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(QuickSort(test).at(i), sorted[i]);
    }

}

TEST(QuickSortTest5, OneNumberLongList){
    std::vector<int> test = { 0 };
    int sorted[] = { 0 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(QuickSort(test).at(i), sorted[i]);
    }

}

TEST(QuickSortTest6, EmptyList){
    std::vector<int> test = {};

    EXPECT_EQ(QuickSort(test), test);


}
//////////////////////////////////////////////////////
/*
* Selection sort tests
*/
TEST(SelectionSortTest1, SortingBasicList){
    std::vector<int> vec = { 9,8,7,6,5,4,3,2,1,0 };
    int sorted[] = { 0,1,2,3,4,5,6,7,8,9 };

    std::vector<int> test = SelectionSort(vec);
    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(test.at(i), sorted[i]);
    }

}
TEST(SelectionSortTest2, SortingBasicListWithNegatives){
    std::vector<int> test = { 9,-8,7,6,-5,4,-3,2,-1,0 };
    int sorted[] = { -8,-5,-3,-1,0,2,4,6,7,9 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(SelectionSort(test).at(i), sorted[i]);
    }

}

TEST(SelectionSortTest3, SortingBasicListWithMultiDigitNums){
    std::vector<int> test = { 90,8,700,6,5,40,3,26,12,0 };
    int sorted[] = { 0,3,5,6,8,12,26,40,90,700 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(SelectionSort(test).at(i), sorted[i]);
    }

}

TEST(SelectionSortTest4, AlreadySortedList){
    std::vector<int> test = { 1,2,3,4,5 };
    int sorted[] = { 1,2,3,4,5 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(SelectionSort(test).at(i), sorted[i]);
    }

}

TEST(SelectionSortTest5, OneNumberLongList){
    std::vector<int> test = { 0 };
    int sorted[] = { 0 };

    for (int i = 0; i < test.size(); i++)
    {
        EXPECT_EQ(SelectionSort(test).at(i), sorted[i]);
    }

}

TEST(SelectionSortTest6, EmptyList){
    std::vector<int> test = {};

    EXPECT_EQ(SelectionSort(test), test);


}