// https://www.codewars.com/kata/555a67db74814aa4ee0001b5
#include <igloo/igloo_alt.h>
using namespace igloo;

//My frist solution
// bool is_even(double n)
// {
//     return (n - static_cast<long long>(n))  == 0 && static_cast<long long>(n) % 2 == 0;
// }

// Best soultion
#include <cmath>
bool is_even(double n)
{
    return fmod(n, 2) == 0;
}

void do_test(double n, bool expected){
    Assert::That(is_even(n), Equals(expected));
}

Describe(is_it_even)
{
    It(example_tests)
    {
        do_test(0,   true);
        do_test(-4.5, false);
        do_test(1,   false);
        do_test(2,   true);
        do_test(500000000000,  true);
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}