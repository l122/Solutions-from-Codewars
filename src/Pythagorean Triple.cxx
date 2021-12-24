// https://www.codewars.com/kata/5951d30ce99cf2467e000013
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>

#include <set>

bool PythagoreanTriple(const int a, const int b, const int c)
{
    std::set<int> t;
    t.insert(a);
    t.insert(b);
    t.insert(c);

    std::set<int>::iterator it = t.begin();
    
    int A = *(it++);
    int B = *(it++);
    int C = *(it);

    return C*C == (A*A + B*B);
}

Describe(PythagorianTriple)
{
    It(BasicTests)
    {
        Assert::That(PythagoreanTriple(3,4,5) , Equals(true));
        Assert::That(PythagoreanTriple(5,3,4) , Equals(true));
        Assert::That(PythagoreanTriple(3,5,9) , Equals(false));
        Assert::That(PythagoreanTriple(5,2,4) , Equals(false));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}