// https://www.codewars.com/kata/5f70c883e10f9e0001c89673
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>

std::vector<int> flip(const char dir, std::vector<int> arr) {
    if (dir == 'L')
      std::sort(arr.begin(), arr.end(), std::greater<int>());
    else std::sort(arr.begin(), arr.end());
    return arr;
}

Describe(SampleTests)
{
    It(should_pass_sample_tests)
    {
        using v = std::vector<int>;
      
        Assert::That(flip('R', { 3, 2, 1, 2 }), Equals(v{ 1, 2, 2, 3 })); //, ExtraMessage("Invalid result for dir = 'R', arr = [ 3, 2, 1, 2 ]"));
        Assert::That(flip('L', { 1, 4, 5, 3, 5 }), Equals(v{ 5, 5, 4, 3, 1 })); //, ExtraMessage("Invalid result for dir = 'L', arr = [ 1, 4, 5, 3, 5 ]"));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}