// https://www.codewars.com/kata/56c5847f27be2c3db20009c3/solutions
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <random>

using namespace std;

/// It's not my solution
string SubtractSum(int n)
{
    vector<string> fruit = { "kiwi", "pear", "kiwi", "banana", "melon", "banana", "melon", "pineapple", "apple" };

    if (n < 10) return fruit[n - 1];
    
    do 
    {
        auto sum = 0, val = n;
        while (val > 0)
        {
            sum += (val % 10);
            val /= 10;
        }
        n = n - sum;
    } while (n >= 10);
    
    return fruit[n - 1];
}
/////// end of solution

Describe(sample_test)
{
    It(should_work_for_sample_test)
    {
        Assert::That(SubtractSum(10), Equals("apple"));
    }
};


Describe(Test)
{
    It(Basic_Test)
    {
        Assert::That(SubtractSum(10), Equals("apple"));
    }
    
    It(Random_Tests)
    {
      std::default_random_engine gen;
      
      for(int i = 0; i < 100; i++)
      {
        int m = gen()%9990 + 11;
        Assert::That(SubtractSum(m), Equals("apple"));
      }
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}