// https://www.codewars.com/kata/5513795bd3fafb56c200049e
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

std::vector<int> countBy(int x,int n){
    std::vector<int> ret(n);
    auto f = [x, n = 0]() mutable {
        return n += x;
    };
    std::generate(ret.begin(), ret.end(), f);
    // std::generate(ret.begin(), ret.end(), [x, n=0]()mutable {return n+=x;});
    return ret;
}


Describe(Count_By_X)
{
    It(Basic_Tests)
    {
        std::vector<int> expected = {1,2,3,4,5,6,7,8,9,10};
        Assert::That(countBy(1,10), Equals(expected));
        expected = {2,4,6,8,10};
        Assert::That(countBy(2,5), Equals(expected));
        expected = {1,2,3,4,5,6,7,8,9,10};
        Assert::That(countBy(1,10), Equals(expected));
        expected = {100,200,300,400,500};
        Assert::That(countBy(100,5), Equals(expected));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}