// https://www.codewars.com/kata/55fab1ffda3e2e44f00000c6

#include <igloo/igloo_alt.h>
using namespace igloo;

int cockroach_speed(double s)
{
    return s * 100000 / 3600;
}

Describe(Sample_Tests)
{
    It(Basic_Tests)
    {
        Assert::That(cockroach_speed(1.08), Equals(30));
        Assert::That(cockroach_speed(1.09), Equals(30));
        Assert::That(cockroach_speed(0),    Equals(0));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}