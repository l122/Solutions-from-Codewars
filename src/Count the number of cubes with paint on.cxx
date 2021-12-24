// https://www.codewars.com/kata/5763bb0af716cad8fb000580/train/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

int countSquares(int cuts)
{
  return 1 + cuts * (8 + cuts);
}

Describe(ExampleTests)
{
    It(BasicTests)
    {
        Assert::That(countSquares(0), Is().EqualTo(1));
        Assert::That(countSquares(5), Is().EqualTo(152));
        Assert::That(countSquares(16), Is().EqualTo(1538));
        Assert::That(countSquares(23), Is().EqualTo(3176));
    }
};


int main(int argc, const char *argv[])
{

    return TestRunner::RunAllTests();
}