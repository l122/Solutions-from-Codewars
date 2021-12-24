//https://www.codewars.com/kata/57eae65a4321032ce000002d/solutions/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>

std::string fakeBin(std::string str){
  std::string result;
  for (const auto & str:str){
      result += (int) str < 53 ? "0" : "1";
  }
  return result;
}

//Great alternatives:
// std::string fakeBin(std::string str){
//   std::transform(str.cbegin(), str.cend(), str.begin(), [](auto const & c){
//     return c >= '5' ? '1' : '0';
//   });
//   return str;
// }
// std::string fakeBin(std::string str){
//   for (int i = 0; i < str.length(); i++)
//   {
//     str[i] = ((str[i] - '0') > 4) ? '1' : '0';
//   }
//   return str;
// }

Describe(FakeBin){
  It(BasicTests){
    Assert::That(fakeBin("45385593107843568"), Equals("01011110001100111"));
    Assert::That(fakeBin("509321967506747"), Equals("101000111101101"));
    Assert::That(fakeBin("366058562030849490134388085"), Equals("011011110000101010000011011"));
    Assert::That(fakeBin("15889923"), Equals("01111100"));
    Assert::That(fakeBin("800857237867"), Equals("100111001111"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}