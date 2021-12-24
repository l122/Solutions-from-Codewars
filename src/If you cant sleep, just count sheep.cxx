// https://www.codewars.com/kata/5b077ebdaf15be5c7f000077
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string countSheep(int number) {
    std::string out = std::to_string(number) + " sheep...";
    return number ? countSheep(--number) + out : "";
}

Describe(CountingSheep) {
  It(BasicTests) {
    Assert::That(countSheep(1), Equals("1 sheep..."));
    Assert::That(countSheep(2), Equals("1 sheep...2 sheep..."));
    Assert::That(countSheep(3), Equals("1 sheep...2 sheep...3 sheep..."));
    Assert::That(countSheep(4), Equals("1 sheep...2 sheep...3 sheep...4 sheep..."));
    Assert::That(countSheep(5), Equals("1 sheep...2 sheep...3 sheep...4 sheep...5 sheep..."));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}