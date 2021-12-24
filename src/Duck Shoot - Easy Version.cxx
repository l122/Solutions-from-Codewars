// https://www.codewars.com/kata/57d27a0a26427672b900046f

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string duckShoot(int ammo, double aim, std::string ducks)
{
    size_t successfulShots = ammo * aim;
    int pos = 0;
    for (size_t i = 0; i < successfulShots; ++i)
    {
        pos = ducks.find('2', pos);
        if (pos != std::string::npos)
        {
            ducks[pos] = 'X';
        }
    }

    return ducks;
}

Describe(DuckShoot){
  It(BasicTests){
    Assert::That(duckShoot(4, 0.64, "|~~2~~~22~2~~22~2~~~~2~~~|"), Equals("|~~X~~~X2~2~~22~2~~~~2~~~|"));
    Assert::That(duckShoot(9, 0.22, "|~~~~~~~2~2~~~|"), Equals("|~~~~~~~X~2~~~|"));
    Assert::That(duckShoot(6, 0.41, "|~~~~~22~2~~~~~|"), Equals("|~~~~~XX~2~~~~~|"));
    Assert::That(duckShoot(8, 0.05, "|2~~~~|"), Equals("|2~~~~|"));
    Assert::That(duckShoot(8, 0.92, "|~~~~2~2~~~~~22~~2~~~~2~~~2|"), Equals("|~~~~X~X~~~~~XX~~X~~~~X~~~X|"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}