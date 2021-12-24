// https://www.codewars.com/kata/54147087d5c2ebe4f1000805
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <functional>
#include <string>

void _if(bool value, std::function<void(void)> func1, std::function<void(void)> func2)
{
    if (value) func1();
    else func2();
}

bool ran_expected;
void Expected() { 
    ran_expected = true; 
    }
void Unexpected() { 
    ran_expected = false; 
    }

Describe(if_method)
{
    void SetUp()
    {
       ran_expected = false;
    }
    It(should_work_for_true)
    {
      _if(true, Expected, Unexpected);
      Assert::That(ran_expected, Equals(true));
    }
    It(should_work_for_false)
    {
      _if(false, Unexpected, Expected);
      Assert::That(ran_expected, Equals(true));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}