// https://www.codewars.com/kata/5bb0c58f484fcd170700063d
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
long pillars(int num_of_pillars, int distance, int width) {

  return num_of_pillars > 1 ? (num_of_pillars-1) * distance * 100 + (num_of_pillars-2)*width : 0;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(pillars(1, 10, 10), Equals(0));
        Assert::That(pillars(2, 20, 25), Equals(2000));
        Assert::That(pillars(11, 15, 30), Equals(15270));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}