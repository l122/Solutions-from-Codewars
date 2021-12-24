// https://www.codewars.com/kata/59342039eb450e39970000a6
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

int odd_count(int n){

  // std::cout << n / 2 << std::endl;
  // std::cout << (n >> 1) << std::endl;

  return n / 2;
}

Describe(basic_tests)
{
    It(test1)
    {
        Assert::That(odd_count(15), Equals(7));
    }
     It(test2)
    {
        Assert::That(odd_count(15023), Equals(7511));
    }
    It(test3)
    {
        Assert::That(odd_count(16), Equals(8));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}