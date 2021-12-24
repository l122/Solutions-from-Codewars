// https://www.codewars.com/kata/606efc6a9409580033837dfb

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>

std::string plant(char seed, int water, int fert, int temp) {
    std::string result;
    if (temp < 20 || temp > 30){
      fert = 0;
    }
    for (int i = 0; i < water; ++i){
      for (int j = 0; j < water; ++j){
        result += '-';
      }
      for (int f = 0; f < fert; ++f){
        result += seed;
      }
    }
    if (temp < 20 || temp > 30){
      result += seed;
    }
    return result;
}

Describe(SampleTests)
{
    It(basic_test_cases)
    {
        Assert::That(plant(',', 3, 7, 25), Equals("---,,,,,,,---,,,,,,,---,,,,,,,"));
        Assert::That(plant('+', 1, 3, 15), Equals("-+"));
        Assert::That(plant(';', 9, 10, 30), Equals("---------;;;;;;;;;;---------;;;;;;;;;;---------;;;;;;;;;;---------;;;;;;;;;;---------;;;;;;;;;;---------;;;;;;;;;;---------;;;;;;;;;;---------;;;;;;;;;;---------;;;;;;;;;;"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}