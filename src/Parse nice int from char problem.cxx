// https://www.codewars.com/kata/557cd6882bfa3c8a9f0000c1

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

int get_age(const std::string& she_said) {
    return she_said[0] - '0';
}

Describe(SampleTests)
{
    It(should_pass_sample_tests)
    {
        Assert::That(get_age("5 years old"), Equals(5));
        Assert::That(get_age("9 years old"), Equals(9));
        Assert::That(get_age("1 year old"),  Equals(1));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}