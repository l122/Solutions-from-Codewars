// https://www.codewars.com/kata/5d59576768ba810001f1f8d6
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
std::vector<int> quadratic(int a,int b){
    return {1, -a-b, a*b};
    
    // std::vector<int> result = {1};
    // result.push_back(-a-b);
    // result.push_back(a*b);

    // return result;
}

Describe(quadratic_coefficient)
{
    It(FixedTest)
    {
        std::vector<int> res1{ 1, -1, 0 };
        std::vector<int> res2{ 1, -2, 1 };
        std::vector<int> res3{ 1, 13, 36 };
        std::vector<int> res4{ 1, 9, 20 };
        std::vector<int> res5{ 1, 5, -36 };
        std::vector<int> res6{ 1, -1, -20 };
      
        Assert::That(quadratic(0,1), Equals(res1));
        Assert::That(quadratic(1,1), Equals(res2));
        Assert::That(quadratic(-4,-9), Equals(res3));
        Assert::That(quadratic(-5,-4), Equals(res4));
        Assert::That(quadratic(4,-9), Equals(res5));
        Assert::That(quadratic(5,-4), Equals(res6));
    }
};



int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}