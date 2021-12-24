// https://www.codewars.com/kata/56cd44e1aa4ac7879200010b
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

// My solution 1
// bool is_uppercase(const std::string &s) {
//     std::string s2(s);
//     std::transform(s2.begin(), s2.end(), s2.begin(), toupper);
//   return s == s2;
// }

// The best Solution
bool is_uppercase(const std::string &s) {
      return std::all_of(s.begin(), s.end(), isupper);
}

Describe(Is_UpperCase) {
  It(Basic_Tests) {
    Assert::That(is_uppercase("c"), Equals(false));
    Assert::That(is_uppercase("C"), Equals(true));
    Assert::That(is_uppercase("hello I AM DONALD"), Equals(false));
    Assert::That(is_uppercase("HELLO I AM DONALD"), Equals(true));
    Assert::That(is_uppercase("ACSKLDFJSgSKLDFJSKLDFJ"), Equals(false));
    Assert::That(is_uppercase("ACSKLDFJSGSKLDFJSKLDFJ"), Equals(true));
  }
  It(Edge_Cases) {
    Assert::That(is_uppercase(""), Equals(true));
    Assert::That(is_uppercase("!@&*#*(#&@#(&@#$*(&(#@%#%"), Equals(true));
  }
  It(Random_Tests) {
    std::function<bool (const std::string &)> solution = [] (const std::string &s) -> bool {
      for (size_t i = 0; i < s.length(); ++i)
        if (std::islower(s[i]))
          return false;
      return true;
    };
    srand(time(nullptr));
    for (int i = 0; i < 100; ++i) {
      std::string s;
      while (rand() % 20)
        s += 32 + rand() % 95;
      if (rand() % 100 < 33)
        for (size_t i = 0; i < s.length(); ++i)
          s[i] = toupper(s[i]);
      bool expected = solution(s);
      Assert::That(is_uppercase(s), Equals(expected));
    }
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}