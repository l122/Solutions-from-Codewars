// https://www.codewars.com/kata/588417e576933b0ec9000045
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>

int seats_in_theater(int total_col, int total_row, int col, int row) {
  int out = (total_row - row) * (total_col - col + 1);
  return out > 1 ? out : 0;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(seats_in_theater(16,11,5,3), Equals(96));
        Assert::That(seats_in_theater(1,1,1,1), Equals(0));
        Assert::That(seats_in_theater(13,6,8,3), Equals(18));
        Assert::That(seats_in_theater(60,100,60,1), Equals(99));
        Assert::That(seats_in_theater(1000,1000,1000,1000), Equals(0));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}