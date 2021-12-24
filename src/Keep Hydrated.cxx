// https://www.codewars.com/kata/582cb0224e56e068d800003c

#include <igloo/igloo_alt.h>
using namespace igloo;



int litres(double time) {
    return static_cast<int>(time * 0.5);
}

Describe(SampleTests)
{
    It(should_pass_sample_tests)
    {
        Assert::That(litres(2), Equals(1));
        Assert::That(litres(1.4), Equals(0));
        Assert::That(litres(12.3), Equals(6));
        Assert::That(litres(0.82), Equals(0));
        Assert::That(litres(11.8), Equals(5));
        Assert::That(litres(1787), Equals(893));
        Assert::That(litres(0), Equals(0));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}