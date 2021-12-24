// https://www.codewars.com/kata/55d24f55d7dd296eb9000030/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;


// // My first solution
// int summation(int num){
//  return num == 0 ? 0 : num + (summation(num-1));
// }

// The best solution from codewars
int summation(int num){
 return num*(num+1)/2;
}

Describe(Test)
{
    It(Fixed__Tests)
    {
        Assert::That(summation(1), Equals(1));
        Assert::That(summation(8), Equals(36));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}