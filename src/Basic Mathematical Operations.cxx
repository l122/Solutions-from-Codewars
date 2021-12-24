// https://www.codewars.com/kata/57356c55867b9b7a60000bd7
#include <igloo/igloo_alt.h>
using namespace igloo;

int basicOp(char op, int val1, int val2) {
  
  switch(op)
  {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return val2 == 0 ? 0 : val1 / val2;
  }
  return 0;
}

Describe(basic_op_samples)
{
  It(basic_tests) {
    Assert::That(basicOp('+',5,4), Equals(9));
    Assert::That(basicOp('-',11,8), Equals(3));
    Assert::That(basicOp('*',3,4), Equals(12));
    Assert::That(basicOp('/',16,4), Equals(4));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}