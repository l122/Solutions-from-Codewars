// https://www.codewars.com/kata/56f699cd9400f5b7d8000b55

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <array>
#include <string>
#include <algorithm>

std::array<std::string, 3> fixTheMeerkat(std::array<std::string, 3> arr) {
  std::swap(arr[0], arr[2]);
  return arr;
}

using ary = std::array<std::string, 3>;

Describe(Tests) {
  It(BasicTests) {
    Assert::That(fixTheMeerkat(ary { "tail", "body", "head" }), Equals(ary { "head", "body", "tail" }));
    Assert::That(fixTheMeerkat(ary { "tails", "body", "heads" }), Equals(ary { "heads", "body", "tails" }));
    Assert::That(fixTheMeerkat(ary { "bottom", "middle", "top" }), Equals(ary { "top", "middle", "bottom" }));
    Assert::That(fixTheMeerkat(ary { "lower legs", "torso", "upper legs" }), Equals(ary { "upper legs", "torso", "lower legs" }));
    Assert::That(fixTheMeerkat(ary { "ground", "rainbow", "sky" }), Equals(ary { "sky", "rainbow", "ground" }));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}