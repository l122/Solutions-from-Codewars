// https://www.codewars.com/kata/5b5e0ef007a26632c400002a
#include <igloo/igloo_alt.h>
using namespace igloo;

#include<vector>

long elementsSum(const std::vector<std::vector<int>>& arr, int d = 0){
    long sum = 0;
    size_t n = arr.size();
    for (size_t i = 0; i < n; ++i){
        sum+= (n - i - 1 < arr[i].size()) 
            ? arr[i][n-i-1]
            : d;
    }
  return sum;
}


Describe(ElementSum){
  It(BasicTests){
    Assert::That(elementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}), Equals(16));
    Assert::That(elementsSum({{3}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}), Equals(15));
    Assert::That(elementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}}), Equals(7));
    Assert::That(elementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}}, 5), Equals(12));
    Assert::That(elementsSum({{3, 2}, {4}, {}}), Equals(0));
  }
};

int main(int argc, const char *argv[])
{
    TestRunner::RunAllTests();
    return 0;
}