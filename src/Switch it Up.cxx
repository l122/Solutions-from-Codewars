// https://www.codewars.com/kata/5808dcb8f0ed42ae34000031

#include <igloo/igloo_alt.h>
using namespace igloo;
#include <string>

std::string switch_it_up(int number){
    std::string out [] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  return out[number];
}

Describe(Switch_it_Up)
{
    It(Fixed_tests)
    {
        Assert::That(switch_it_up(0), Equals("Zero"));
        Assert::That(switch_it_up(1), Equals("One"));
        Assert::That(switch_it_up(2), Equals("Two"));
        Assert::That(switch_it_up(3), Equals("Three"));
        Assert::That(switch_it_up(4), Equals("Four"));
        Assert::That(switch_it_up(5), Equals("Five"));
        Assert::That(switch_it_up(6), Equals("Six"));
        Assert::That(switch_it_up(7), Equals("Seven"));
        Assert::That(switch_it_up(8), Equals("Eight"));
        Assert::That(switch_it_up(9), Equals("Nine"));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}