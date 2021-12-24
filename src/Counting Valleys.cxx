// https://www.codewars.com/kata/5da9973d06119a000e604cb6

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

int countValleys(const std::string &s)
{
    int ret = 0,
        level = 0;
    for (const auto &s : s)
    {
        if (s == 'D')
        {
            --level;
        }
        else if (s == 'U')
        {
            ++level;
            if (level == 0)
                ++ret;
        }
    }
    return ret;
}

// TODO: Replace examples and use TDD development by writing your own tests

Describe(basic_tests)
{
    It(should_handle_simple_situations)
    {
        Assert::That(countValleys("DU"), Equals(1));
        Assert::That(countValleys("FFFFFFFF"), Equals(0));
    }
    
    It(should_handle_basics)
    {
      Assert::That(countValleys("UFFDDFDUDFUFU"), Equals(1));
      Assert::That(countValleys("UFFDDFDUDFUFUUFFDDUFFDDUFFDDUDUDUDUDUDUUUUUUUUU"), Equals(3));
      Assert::That(countValleys("UFFDDFDUDFUFUUFFDDFDUDFUFUUFFDDFDUDFUFUUFFDDFDUDFUFUUFFDDFDUDFUFUUFFDDFDUDFUFU"), Equals(6));
      Assert::That(countValleys("UFFDDFDUDFUFUUFFDDFDUDFUFU"), Equals(2));
      Assert::That(countValleys("UFFDDFDUDFUFUUFFDDFDUDFUFUUFFDDFDUDFUFUUFFDDFDUDFUFU"), Equals(4));
      Assert::That(countValleys("DFFFU"), Equals(1));
      Assert::That(countValleys("UFFFD"), Equals(0));
      Assert::That(countValleys("DFFFD"), Equals(0));
      Assert::That(countValleys("UFFFU"), Equals(0)); 
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}