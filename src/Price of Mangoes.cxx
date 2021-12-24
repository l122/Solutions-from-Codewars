// https://www.codewars.com/kata/57a77726bb9944d000000b06
#include <igloo/igloo_alt.h>
using namespace igloo;

int mango(int quantity, int price)
{   
    return quantity / 3 * 2 * price + quantity % 3 * price;
}

Describe(ExmapleTests)
{
    It(BasicTest)
    {
        Assert::That(mango(3, 3), Is().EqualTo(6));
        Assert::That(mango(9, 5), Is().EqualTo(30));
    }
};

int main(int argc, const char *argv[])
{
  return TestRunner::RunAllTests();
}