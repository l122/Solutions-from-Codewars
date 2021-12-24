// https://www.codewars.com/kata/58649884a1659ed6cb000072
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string update_light(std::string current) {
  return current == "green" ? "yellow" : current == "yellow" ? "red" : "green";
}

Describe(Update_light_tests) {
  It(Basic_cases) {
    Assert::That(update_light("green"), Equals("yellow"));
    Assert::That(update_light("yellow"), Equals("red"));
    Assert::That(update_light("red"), Equals("green"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}