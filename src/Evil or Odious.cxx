// https://www.codewars.com/kata/56fcfad9c7e1fa2472000034


#include <iostream>

#include <bitset>
#include <string>
#include <algorithm>

std::string evil(int n)
{
    std::bitset<32> in(n);
    // std::cout << in << std::endl;

    std::string s = in.to_string();
    // std::cout << s << std::endl;

    int count = std::count(s.begin(), s.end(), '1');
    // std::cout << count << std::endl;

    // std::cout << "count % 2 = " << count % 2 << std::endl;

  return count % 2 ? "It's Odious!" : "It's Evil!";
}



#include <igloo/igloo_alt.h>
using namespace igloo;
#include <random>

Describe(your_solution)
{
    It(should_pass_sample_tests)
    {
        // Assert::That(evil(1), Equals("It's Odious!"));
        // Assert::That(evil(2), Equals("It's Odious!"));
        // Assert::That(evil(3), Equals("It's Evil!"));
        Assert::That(evil(19), Equals("It's Evil!"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}