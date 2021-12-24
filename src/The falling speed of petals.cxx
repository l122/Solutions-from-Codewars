// https://www.codewars.com/kata/5a0be7ea8ba914fc9c00006b
#include <igloo/igloo_alt.h>
using namespace igloo;

double SakuraFall(double v) {
    return v > 0 ? 5 * 80 / v : 0;
}

Describe(ExampleTest) {
    It(BasicTest) {
        Assert::That(SakuraFall(5), Equals(80));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}