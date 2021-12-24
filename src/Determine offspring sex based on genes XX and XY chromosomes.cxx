// https://www.codewars.com/kata/56530b444e831334c0000020
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string chromosomeCheck(std::string sperm) {
    return sperm.find('Y') == std::string::npos ? "Congratulations! You're going to have a daughter." :
                                                    "Congratulations! You're going to have a son.";
}

Describe(TEST)
{
    It(SEX)
    {
        Assert::That(chromosomeCheck("XY"), Equals("Congratulations! You're going to have a son."));
        Assert::That(chromosomeCheck("XX"), Equals("Congratulations! You're going to have a daughter."));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}