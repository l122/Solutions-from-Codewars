// https://www.codewars.com/kata/55f9b48403f6b87a7c0000bd

#include <igloo/igloo_alt.h>
using namespace igloo;

int paperwork(int n, int m){
    return n > 0 && m > 0 ? n * m : 0;
}

Describe(Sample_tests)
{
    It(Should_work_for_positive)
    {
        Assert::That(paperwork(5,5), Equals(25));
    }
  
    It(Should_work_for_negative_m)
    {
        Assert::That(paperwork(5,-5), Equals(0));
    }
    
    It(Should_work_for_negative_n)
    {
        Assert::That(paperwork(-5,5), Equals(0));
    }
    
    It(Should_work_for_negative_m_and_n)
    {
        Assert::That(paperwork(-5,-5), Equals(0));
    }
    
    It(Should_work_for_zero)
    {
        Assert::That(paperwork(5,0), Equals(0));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}