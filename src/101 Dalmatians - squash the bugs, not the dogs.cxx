// https://www.codewars.com/kata/56f6919a6b88de18ff000b36
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <string>

std::string howManyDalmatians(int number){
  switch(number){
    case 0 ... 10: return "Hardly any";
    case 11 ... 50: return "More than a handful!";
    case 51 ... 100: return "Woah that's a lot of dogs!";
    default: return "101 DALMATIONS!!!";
  }
}

Describe(Tests)
{
    It(ExampleTests)
    {
        Assert::That(howManyDalmatians(26), Equals("More than a handful!"));
        Assert::That(howManyDalmatians(8), Equals("Hardly any"));
        Assert::That(howManyDalmatians(14), Equals("More than a handful!"));
        Assert::That(howManyDalmatians(80), Equals("Woah that's a lot of dogs!"));
        Assert::That(howManyDalmatians(100), Equals("Woah that's a lot of dogs!"));
        Assert::That(howManyDalmatians(50), Equals("More than a handful!"));
        Assert::That(howManyDalmatians(10), Equals("Hardly any"));
        Assert::That(howManyDalmatians(101), Equals("101 DALMATIONS!!!"));      
    }
};

int main(int argc, const char *argv[])
{
  return TestRunner::RunAllTests();
}