// https://www.codewars.com/kata/5a0366f12b651dbfa300000c

#include <iostream>
#include <string>

#include <igloo/igloo_alt.h>
using namespace igloo;

std::string arbitrate(const std::string &input, int n)
{
    if (input.size() != n)
    {
        return "The input number doesn't match the size of input string";
    }

    std::string result(n, '0');
    auto index = input.find('1');
    if (index != std::string::npos)
    {
        result[index] = '1';
    }

    return result;
}
Describe(Sample_Tests)
{
    It(example_tests)
    {
      Assert::That(arbitrate("001000101", 9), Equals("001000000"));
      Assert::That(arbitrate("000000101", 9), Equals("000000100"));
      Assert::That(arbitrate("0000", 4), Equals("0000"));    
    };  
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}