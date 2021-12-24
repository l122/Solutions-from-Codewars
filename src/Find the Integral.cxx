// https://www.codewars.com/kata/59811fd8a070625d4c000013

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>

#include <string>
std::string integrate(const int& coefficient,const int& exponent){
  return std::to_string(coefficient/(exponent+1)) + "x^" + std::to_string(exponent+1);
}

Describe(Sample_Test_Cases)
{
    It(Fixed_Tests)
    {
        Assert::That(integrate(3,2), Equals("1x^3"));      
        Assert::That(integrate(12,5), Equals("2x^6"));
        Assert::That(integrate(20,1), Equals("10x^2"));
        Assert::That(integrate(40,3), Equals("10x^4"));
        Assert::That(integrate(90,2), Equals("30x^3"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}