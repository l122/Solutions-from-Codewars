// https://www.codewars.com/kata/57f759bb664021a30300007d/train/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>

std::string switcheroo(const std::string &s) {
  std::string result;
  for (const auto & s : s){
      result += (s == 'a') ? 'b' : (s == 'b') ? 'a' : s;
  }
  return result;
}

Describe(Fixed_tests) {
  It(Sample_cases) {
    Assert::That(switcheroo("abc"), Equals("bac"));
    Assert::That(switcheroo("aaabcccbaaa"), Equals("bbbacccabbb"));
    Assert::That(switcheroo("cccccc"), Equals("cccccc"));
    Assert::That(switcheroo("abababababababab"), Equals("babababababababa"));
    Assert::That(switcheroo("aaaa"), Equals("bbbb"));
    Assert::That(switcheroo("bbbb"), Equals("aaaa"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}