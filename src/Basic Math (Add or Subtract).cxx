//https://www.codewars.com/kata/5809b62808ad92e31b000031/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

std::string calculate(std::string str)
{
  int result = 0;
  int sign = 1;
  std::string temp = ""; 
  for (int i = 0; i < str.size(); ++i){
    if (str[i] == 'p'){
      i+=3;
      result = result + sign * std::stoi(temp);
      temp = "";
      sign = 1;
    }
    else if (str[i] == 'm'){
      i+=4;
      result = result + sign * std::stoi(temp);
      temp = "";
      sign = -1;
    } else {
      temp += str[i];
    }
  }
  result = result + sign * std::stoi(temp);
  return std::to_string(result);
}

Describe(sample_tests)
{
    It(sample_basic_tests)
    {
        Assert::That(calculate("1plus2plus3plus4"), Equals("10"));
        Assert::That(calculate("1minus2minus3minus4"), Equals("-8"));
        Assert::That(calculate("1plus2plus3minus4"), Equals("2"));
    }
};
int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}