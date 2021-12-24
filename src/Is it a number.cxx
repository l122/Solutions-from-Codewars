// https://www.codewars.com/kata/57126304cdbf63c6770012bd
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
// Solutions from codewars
// bool is_digit(std::string s) {
//   std::istringstream iss(s);
//   float checker;
//   // iss >> std::noskipws >> checker;
//   iss >> checker >> std::ws;
//   std::cout << "checker = " << checker << std::endl;
//   std::cout << "iss.str() = " << iss.str() << std::endl;
//   std::cout << "iss.eof() = " << iss.eof() << std::endl;
//   std::cout << "iss && iss.eof() = " << (iss && iss.eof()) << std::endl;
//   return iss && iss.eof(); 
// }

#include <regex>
bool is_digit(std::string s) {
  return std::regex_match(s, std::regex(R"(\s*[+-]?([0-9]*[.])?[0-9]+\s*)"));
}


Describe(Sample_tests) {
  It(Valid_positive_values) {
    Assert::That(is_digit("3"), Is().True());
    Assert::That(is_digit(" 3 "), Is().True());
    Assert::That(is_digit("  3"), Is().True());
    Assert::That(is_digit("3   "), Is().True());
    Assert::That(is_digit("365"), Is().True());
  }
  It(Valid_negative_values) {
    Assert::That(is_digit("-3.23 "), Is().True());
    Assert::That(is_digit("-234.4"), Is().True());
    Assert::That(is_digit("-0"), Is().True());
  }
  It(Null) {
    Assert::That(is_digit("0.0"), Is().True());
  }
  It(Invalid_cases) {
    Assert::That(is_digit("s2324"), Is().False());
    Assert::That(is_digit("3 4"), Is().False());
    Assert::That(is_digit("3-4"), Is().False());
    Assert::That(is_digit("3 4   "), Is().False());
    Assert::That(is_digit(""), Is().False());
    Assert::That(is_digit(" "), Is().False());
  }
};


int main(int argc, const char *argv[])
{

    return TestRunner::RunAllTests();
}