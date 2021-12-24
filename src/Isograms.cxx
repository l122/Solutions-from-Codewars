// https://www.codewars.com/kata/54ba84be607a92aa900000f1
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

bool is_isogram(std::string str) {
  std::set<char> set;
  for(const auto & symbol : str){
    set.insert(std::tolower(symbol));
  }
  // std::string temp(str.length(), 'x');
  // std::string temp;
  // temp.resize(str.length());
  // std::transform(str.begin(), str.end(), temp.begin(), ::tolower);
  // std::set<char> set(str.begin(), str.end());
  return set.size() == str.size();
}

Describe(Tests)
{
    It(isogram_or_not)
    {
        Assert::That(is_isogram("Dermatoglyphics"), Equals(true));
        Assert::That(is_isogram("moose"), Equals(false));
        Assert::That(is_isogram("isIsogram"), Equals(false));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}