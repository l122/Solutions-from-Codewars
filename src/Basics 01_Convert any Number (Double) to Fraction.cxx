// https://www.codewars.com/kata/569792aa413feea7b3000036

#include <igloo/igloo_alt.h>
using namespace igloo;

class Kata
{
public:
    std::string toFraction(double number)
    {
        return "0";
    }
};

Describe(ExampleTests){
    It(Test1){
        Kata kata;

Assert::That(kata.toFraction(0.75), Is().EqualTo("3/4"));
}

It(Test2)
{
    Kata kata;

    Assert::That(kata.toFraction(-0.333333333333333), Is().EqualTo("-1/3"));
}

It(Test3)
{
    Kata kata;

    Assert::That(kata.toFraction(3), Is().EqualTo("3"));
}

It(Test4)
{
    Kata kata;

    Assert::That(kata.toFraction(0.833333333333333), Is().EqualTo("5/6"));
}

It(Test5)
{
    Kata kata;

    Assert::That(kata.toFraction(0), Is().EqualTo("0"));
}
}
;

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}