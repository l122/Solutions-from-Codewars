// https://www.codewars.com/kata/50ee6b0bdeab583673000025

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string a = "code";
std::string b = "wa.rs";
std::string name = a + b;

Describe(test)
{
    It(correct_value)
    {
        Assert::That(name, Equals("codewa.rs"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}