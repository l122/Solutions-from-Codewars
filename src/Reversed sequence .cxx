// https://www.codewars.com/kata/5a00e05cc374cb34d100000d
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <algorithm>

//My first solution
// std::vector<int> reverseSeq(int n) {
//   std::vector<int> out(n);
//   std::generate(out.begin(), out.end(), [v = n]()mutable{return v--;});
// // std::ranges::generate(out, [v = n]()mutable{return v--;});
//   return out;
// }

//Best solution
#include <numeric>
std::vector<int> reverseSeq(int n) {
  std::vector<int> out(n);
  std::iota(out.rbegin(), out.rend(), 1);
  return out;
}

Describe(ReverseSeq)
{
    It(BasicTests)
    {
        Assert::That(reverseSeq(1), Equals(std::vector<int>{1}));
        Assert::That(reverseSeq(2), Equals(std::vector<int>{2,1}));
        Assert::That(reverseSeq(5), Equals(std::vector<int>{5,4,3,2,1}));
        Assert::That(reverseSeq(10), Equals(std::vector<int>{10,9,8,7,6,5,4,3,2,1}));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}