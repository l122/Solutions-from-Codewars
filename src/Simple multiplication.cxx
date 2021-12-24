// https://www.codewars.com/kata/583710ccaa6717322c000105

#include <igloo/igloo_alt.h>
using namespace igloo;

// My solution
int simpleMultiplication(int a){
    return a & 1 ? a * 9 : a * 8;
}

// // A clever solution from codewars
// int simpleMultiplication(int a)
// {
//     return a * ( 8 + ( a & 1 ) );
// }

// Isn't working
// int __attribute__((naked)) simpleMultiplication(int) {
//     asm(
//       "leal 0(,%rdi,8), %eax;"
//       "leal (%rax,%rdi), %edx;"
//       "andl $1, %edi;" 
//       "cmovne %edx, %eax;"
//       "ret");
// }

Describe(simpleMultiplicationTest)
{
    It(multiply)
    {
        Assert::That(simpleMultiplication(2), Equals(16));
        Assert::That(simpleMultiplication(1), Equals(9));
        Assert::That(simpleMultiplication(8), Equals(64));
        Assert::That(simpleMultiplication(4), Equals(32));
        Assert::That(simpleMultiplication(5), Equals(45));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}