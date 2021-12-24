// https://www.codewars.com/kata/5786f8404c4709148f0006bf

#include<cmath>

double startingMark(double bodyHeight)
{
    double startingMark = (bodyHeight - 1.52) * (1.22 / 0.31) + 9.45;
    startingMark = std::round(startingMark *100) / 100;

    return startingMark;
}

#include <igloo/igloo_alt.h>
using namespace igloo;

Describe(Tests)
{
    It(ExampleTests)
    {
        Assert::That(startingMark(1.52), Equals(9.45));
        Assert::That(startingMark(1.83), Equals(10.67));
        Assert::That(startingMark(1.22), Equals(8.27));
        Assert::That(startingMark(2.13), Equals(11.85));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}