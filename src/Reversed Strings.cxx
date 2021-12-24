// https://www.codewars.com/kata/5168bb5dfe9a00b126000018/solutions/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;


#include <algorithm>
#include <string>
#include <iostream>

std::string reverseString(std::string str) {
  std::cout << "str = " << str << std::endl;
  std::cout << "*(str.begin()) = " << *(str.begin()) << std::endl;
  std::cout << "*(str.rbegin()) = " << *(str.rbegin()) << std::endl;
  std::cout << "*(str.rbegin()-1) = " << *(str.rbegin()-1) << std::endl;
  std::cout << "*(str.rbegin()+1) = " << *(str.rbegin()+1) << std::endl;
  std::cout << "*(str.end()-1) = " << *(str.end()-1) << std::endl;
  std::cout << "*(str.rend()-1) = " << *(str.rend()-1) << std::endl;
  return std::string(str.rbegin(), str.rend());
}

Describe(Reverse_String)
{
    It(Check_Short_Words)
    {
        Assert::That(reverseString("hello"), Equals("olleh"));
        Assert::That(reverseString("rat"), Equals("tar"));
        Assert::That(reverseString("alpha"), Equals("ahpla"));
    }
    It(Check_Longer_Words)
    {
        Assert::That(reverseString("codewars"), Equals("srawedoc"));
        Assert::That(reverseString("football"), Equals("llabtoof"));
        Assert::That(reverseString("translation"), Equals("noitalsnart"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}