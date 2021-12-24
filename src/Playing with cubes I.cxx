// https://www.codewars.com/kata/55c0a79e20be94c91400014b
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

class Cube
{
    public:
        int GetSide(){return c;}
        void SetSide(int s) {c = s;}
    private:
        int c=0;
};

Describe(Should_create_cube)
{

  It(Must_be_0)
  {
    Cube c;
    Assert::That(c.GetSide(), Equals(0));
    c.SetSide(10);
    Assert::That(c.GetSide(), Equals(10));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}