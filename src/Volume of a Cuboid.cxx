//https://www.codewars.com/kata/58261acb22be6e2ed800003a

#include <igloo/igloo_alt.h>
using namespace igloo;

double getVolumeOfCubiod(double length, double width, double height) {
  return length * width * height;
}

Describe(GetVolume)
{
    It(BasicTests)
    {
        Assert::That(getVolumeOfCubiod(1, 2, 2), Equals(4));
        Assert::That(getVolumeOfCubiod(6.3, 2, 5), Equals(63));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}