// https://www.codewars.com/kata/523b623152af8a30c6000027

#include <igloo/igloo_alt.h>
using namespace igloo;

// My frist solution
// unsigned long long square(int x){return x * x;}

// From codewar
// template <typename T>
// T square(T x){return x * x; }

//Maybe a better solution --- still gives an overflow
template <typename T>
auto square(T x) -> decltype(x * x)
{
    return x * x;
}

Describe(Basic)
{
    It(should_work_for_a_basic_test)
    {
        Assert::That(square(42), Equals(42 * 42));
        Assert::That(square(2147483647), Equals(2147483647 * 2147483647));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}