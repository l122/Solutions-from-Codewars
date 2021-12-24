// https://www.codewars.com/kata/57ebaa8f7b45ef590c00000c/train/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <vector>
#include <iostream>

std::string switcher(const std::vector<std::string>& arr) {
    std::string result; 
    int num = 0;
    for (const auto & number : arr){
        num = 123-std::stoi(number);
        if (num == 123-27) num = 33; // '!'
        else if (num == 123-28) num = 63; //'?'
        else if (num == 123 -29) num = 32; //' '
        result = result + char(num);
    }
  return result;
}


Describe(Fixed_tests) {
  It(Sample_cases) {
    Assert::That(switcher(std::vector<std::string> {"24", "12", "23", "22", "4", "26", "9", "8"}), 
                 Equals("codewars"));
    Assert::That(switcher(std::vector<std::string> {"25", "7", "8", "4", "14", "23", "8", "25", "23", "29", "16", "16", "4"}), 
                 Equals("btswmdsbd kkw"));
    Assert::That(switcher(std::vector<std::string> {"4", "24"}), 
                 Equals("wc"));
    Assert::That(switcher(std::vector<std::string> {"12"}), 
                 Equals("o"));
    Assert::That(switcher(std::vector<std::string> {"12", "28", "25", "21", "25", "7", "11", "22", "15"}), 
                 Equals("o?bfbtpel"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}