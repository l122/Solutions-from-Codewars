// https://www.codewars.com/kata/5601409514fc93442500010b
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints) {
  return yourPoints > std::accumulate(classPoints.begin(), classPoints.end(), 0) / classPoints.size();
}

using vec = std::vector<int>;

Describe(HowGoodAreYouReally) {
  It(BasicTests) {
    Assert::That(betterThanAverage(vec{2, 3}, 5), Equals(true));
    Assert::That(betterThanAverage(vec{100, 40, 34, 57, 29, 72, 57, 88}, 75), Equals(true));
    Assert::That(betterThanAverage(vec{12, 23, 34, 45, 56, 67, 78, 89, 90}, 69), Equals(true));
  }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}