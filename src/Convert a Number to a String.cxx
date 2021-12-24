//https://www.codewars.com/kata/5265326f5fda8eb1160004c8/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>

std::string number_to_string(int num) {
  return std::to_string(num);
}


Describe(number_to_string_function) {
  It(should_convert_a_number_to_string) {
    Assert::That(number_to_string(1+2), Equals("3"));
    Assert::That(number_to_string(67), Equals("67"));
    Assert::That(number_to_string(-5), Equals("-5"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}