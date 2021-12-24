// https://www.codewars.com/kata/523b66342d0c301ae400003b

#include <igloo/igloo_alt.h>
using namespace igloo;


template<typename T>
T multiply(T x, T y){return x * y;}

// //Maybe a better way
// template <typename T1, typename T2>
// auto multiply (T1 a, T2 b) -> decltype(a * b)
// {
//   return a * b;
// }

Describe(testing)
{
    It(example_tests)
    {
        Assert::That(multiply(2, 2), Equals(4));
        Assert::That(multiply(4, 5), Equals(20));
        Assert::That(multiply(10, 100), Equals(1000));
        // Assert::That(multiply(2147483647, 2147483647), Equals(4611686014132420609)); // give a stack overflow
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}