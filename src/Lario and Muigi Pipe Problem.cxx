// https://www.codewars.com/kata/56b29582461215098d00000f

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> pipe_fix(const std::vector<int>& nums) {
  int start = *std::min_element(nums.begin(), nums.end());
  int end = *std::max_element(nums.begin(), nums.end());
  std::vector<int> out(end - start + 1);
    std::iota(out.begin(), out.end(), start);
  return out;
}

Describe(Fixed_tests) {
  It(Sample_cases) {
    Assert::That(pipe_fix(std::vector<int>{1, 2, 3, 5, 6, 8, 9}), 
                 Equals(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
    
    Assert::That(pipe_fix(std::vector<int>{1, 2, 3, 12}), 
                 Equals(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));
    
    Assert::That(pipe_fix(std::vector<int>{6, 9}), 
                 Equals(std::vector<int>{6, 7, 8, 9}));
    
    Assert::That(pipe_fix(std::vector<int>{-1, 4}), 
                 Equals(std::vector<int>{-1, 0, 1, 2, 3, 4}));
    
    Assert::That(pipe_fix(std::vector<int>{1, 2, 3}), 
                 Equals(std::vector<int>{1, 2, 3}));
    
    Assert::That(pipe_fix(std::vector<int>{1}), 
                 Equals(std::vector<int>{1}));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}