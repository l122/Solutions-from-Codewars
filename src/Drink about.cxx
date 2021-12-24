// https://www.codewars.com/kata/56170e844da7c6f647000063

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string people_with_age_drink(int age) {
    switch (age)
    {
        case 0 ... 13: return "drink toddy";
        case 14 ... 17: return "drink coke";
        case 18 ... 20: return "drink beer";
        default: return "drink whisky";
    }
}

Describe(Fixed_tests) {
  It(Should_drink_toddy) {
    Assert::That(people_with_age_drink(0), Equals("drink toddy"));
    Assert::That(people_with_age_drink(13), Equals("drink toddy"));
  }
  It(Should_drink_coke) {
    Assert::That(people_with_age_drink(14), Equals("drink coke"));
    Assert::That(people_with_age_drink(17), Equals("drink coke"));
  }
  It(Should_drink_beer) {
    Assert::That(people_with_age_drink(18), Equals("drink beer"));
    Assert::That(people_with_age_drink(20), Equals("drink beer"));
  }
  It(Should_drink_whisky) {
    Assert::That(people_with_age_drink(21), Equals("drink whisky"));
    Assert::That(people_with_age_drink(25), Equals("drink whisky"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}