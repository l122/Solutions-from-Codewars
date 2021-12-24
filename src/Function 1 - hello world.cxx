// https://www.codewars.com/kata/523b4ff7adca849afe000035

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

// Write a function "greet" that returns "hello world!" of type std::string
std::string greet() {return "hello world!";}

Describe(HelloWorld) {
  It(GreetWorld) {
    Assert::That(greet(), Equals("hello world!"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}