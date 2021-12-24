// https://www.codewars.com/kata/568dcc3c7f12767a62000038/train/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

bool set_alarm(const bool& employed,const bool& vacation){
  return employed && !vacation;
}

Describe(Set_Alarm)
{
    It(Test_Case)
    {
        Assert::That(set_alarm(true,true), Equals(false));
        Assert::That(set_alarm(false,true), Equals(false));
        Assert::That(set_alarm(false,false), Equals(false));
        Assert::That(set_alarm(true,false), Equals(true));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}