// https://www.codewars.com/kata/55225023e1be1ec8bc000390

#include <igloo/igloo_alt.h>
using namespace igloo;

std::string greet(std::string name) 
{
  return name == "Johnny" ? "Hello, my love!" : "Hello, " + name + "!";
}

Describe(greet_normally)
{
  It(should_append_names)
  {
    Assert::That(greet("James"), Equals("Hello, James!"));
    Assert::That(greet("Jane"), Equals("Hello, Jane!"));
    Assert::That(greet("Jim"), Equals("Hello, Jim!"));
  }
};

Describe(greet_johnny)
{
  It(should_be_a_little_more_special)
  {
    Assert::That(greet("Johnny"), Equals("Hello, my love!"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}