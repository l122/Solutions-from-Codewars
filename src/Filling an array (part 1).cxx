// https://www.codewars.com/kata/571d42206414b103dc0006a1
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

std::vector<int> arr(int n = 0) {
  std::vector<int> ret(n);
  std::iota(ret.begin(), ret.end(), 0);
  return ret;
}


typedef std::vector<int> V;

Describe(Example_Tests)
{
    It(example_tests)
    {
        Assert::That(arr(), Equals(V {} ));
        Assert::That(arr(4), Equals( V{0,1,2,3} ));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}