// https://www.codewars.com/kata/57a429e253ba3381850000fb

#include <igloo/igloo_alt.h>
using namespace igloo;

std::string bmi(double w, double h) 
{
  double bmi = w / h / h;
  if (bmi <= 18.5) return "Underweight";
  if (bmi <= 25.0) return "Normal";
  if (bmi <= 30.0) return "Overweight";
  return "Obese";
//   throw std::logic_error("Method or operation is not implemented");
}

Describe(simple_tests) 
{
  It(should_pass_all_simple_tests) 
  {
    Assert::That(bmi(81.585, 2.1), Equals("Underweight"));
    Assert::That(bmi(90.25, 1.9), Equals("Normal"));
    Assert::That(bmi(86.7, 1.7), Equals("Overweight"));
    Assert::That(bmi(200, 1.6), Equals("Obese"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}