// https://www.codewars.com/kata/586c1cf4b98de0399300001d
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

// Solution 1
// int combat(int health, int damage){
//   return  health > damage ? health - damage : 0;
// }

// Solution 2
int combat(int health, int damage){
    return std::max(health - damage, 0);
}

Describe(combat_tests)
{
    It(basic_test)
    {
        Assert::That(combat(100,5), Equals(95));
        Assert::That(combat(83,16), Equals(67));
        Assert::That(combat(20,30), Equals(0));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}