// https://www.codewars.com/kata/57d814e4950d8489720008db
#include <igloo/igloo_alt.h>
using namespace igloo;


#include <vector>
#include <cmath>

int index(const std::vector<int> &vector, int n) {

    // int result = 0;
    // if (n >= vector.size())
    //     result = -1;
    // else {
    //     result = std::pow(vector[n], n);
    // }
    // return result;

  return n >= vector.size() ? -1 : std::pow(vector[n], n);
}

typedef std::vector<int> V;

Describe(Basic_Tests)
{
    It(basic_tests)
    {
        Assert::That(index(V{ 1,2,3,4 }, 2), Equals(9));
        Assert::That(index(V{ 5,1,3,3 }, 3), Equals(27));
        Assert::That(index(V{ 1,2 }, 3), Equals(-1));
        Assert::That(index(V{ 1 }, 0), Equals(1));
        Assert::That(index(V{ 1,1,1,1,1,1,1,1,1,1 }, 9), Equals(1));
        Assert::That(index(V{ 1,1,1,1,1,1,1,1,1,2 }, 9), Equals(512));
        Assert::That(index(V{ 29,82,45,10 }, 3), Equals(1000));
        Assert::That(index(V{ 6,31 }, 3), Equals(-1));
        Assert::That(index(V{ 75,68,35,61,9,36,89,11,30 }, 10), Equals(-1));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}