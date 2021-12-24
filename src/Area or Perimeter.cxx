// https://www.codewars.com/kata/5ab6538b379d20ad880000ab

#include <igloo/igloo_alt.h>
using namespace igloo;

int area_or_perimeter(int l , int w) {
  return l == w ? l * w : 2 * (l+w);
}

Describe(Fixed_tests)
{
    It(Basics)
    {
        Assert::That(area_or_perimeter(4 , 4) , Equals(16));
        Assert::That(area_or_perimeter(6 , 10) , Equals(32));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}