// https://www.codewars.com/kata/5bb904724c47249b10000131
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <array>
#include <string>

int points(const std::array<std::string, 10>& games) {
  int sum = 0,
    x = 0,
    y = 0;
  for (const auto & game : games){
    x = game[0] - '0';
    y = game[2] - '0';
    sum += x > y ? 3 : x < y ? 0 : 1;
  }
  return sum;
}

Describe(Sample_tests)
{
    It(Tests)
    {
        int r;
        r = points(std::array<std::string, 10>{"1:0","2:0","3:0","4:0","2:1","3:1","4:1","3:2","4:2","4:3"});
        Assert::That(r, Equals(30));
        
        r = points(std::array<std::string, 10>{"1:1","2:2","3:3","4:4","2:2","3:3","4:4","3:3","4:4","4:4"});
        Assert::That(r, Equals(10));
        
        r = points(std::array<std::string, 10>{"0:1","0:2","0:3","0:4","1:2","1:3","1:4","2:3","2:4","3:4"});
        Assert::That(r, Equals(0));
        
        r = points(std::array<std::string, 10>{"1:0","2:0","3:0","4:0","2:1","1:3","1:4","2:3","2:4","3:4"});
        Assert::That(r, Equals(15));
        
        r = points(std::array<std::string, 10>{"1:0","2:0","3:0","4:4","2:2","3:3","1:4","2:3","2:4","3:4"});
        Assert::That(r, Equals(12));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}