// https://www.codewars.com/kata/5a3fe3dde1ce0e8ed6000097

#include <igloo/igloo_alt.h>
using namespace igloo;

int centuryFromYear(int year) 
{
    return (year + 99) / 100 ;
}

Describe(Century_From_The_Year)
{
    It(EXtract_The_Century_From_Given_Year)
    {
        Assert::That(centuryFromYear(1705), Equals(18));
        Assert::That(centuryFromYear(1900), Equals(19));
        Assert::That(centuryFromYear(1601), Equals(17));
        Assert::That(centuryFromYear(2000), Equals(20));  
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}