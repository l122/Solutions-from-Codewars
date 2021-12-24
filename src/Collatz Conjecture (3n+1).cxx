// https://www.codewars.com/kata/577a6e90d48e51c55e000217
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>

#include <string>

unsigned int hotpo(unsigned int n){
    if(n == 0) return 0; 

    unsigned int count = 0;

    while (n != 1){
        if (n & 1) {
            n = 3 * n + 1;
        }else{
            n /= 2;
        }
        ++count;
    }

    return count;
}


Describe(Test){
    It(Examples){
	      Assert::That(hotpo(1), Equals(0));
        Assert::That(hotpo(5), Equals(5));
        Assert::That(hotpo(6), Equals(8));
        Assert::That(hotpo(23), Equals(15));
	  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}