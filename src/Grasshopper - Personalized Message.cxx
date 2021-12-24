// https://www.codewars.com/kata/5772da22b89313a4d50012f7
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string greet(const std::string& name, const std::string& owner) {
  return name == owner ? "Hello boss" : "Hello guest";
}

Describe(Fixed_tests) {
  It(Basic_cases) {
    Assert::That(greet("Daniel", "Daniel"), Equals("Hello boss"));
    Assert::That(greet("Greg", "Daniel"), Equals("Hello guest"));
  }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}