// https://www.codewars.com/kata/51c89385ee245d7ddf000001

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>

std::string solution(int n) {
    std::string result = "Value is 00000";
    result.replace(result.end() - std::to_string(n).size(), 
                    result.end(), 
                    std::to_string(n));
  return result;
}

Describe(Kata_tests) {
  It(Fixed_tests) {
    Assert::That(solution(0), Equals("Value is 00000"));
    Assert::That(solution(5), Equals("Value is 00005"));
    Assert::That(solution(109), Equals("Value is 00109"));
    Assert::That(solution(1204), Equals("Value is 01204"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}