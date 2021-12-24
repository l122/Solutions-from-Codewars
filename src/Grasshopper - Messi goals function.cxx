// https://www.codewars.com/kata/55f73be6e12baaa5900000d4

#include <igloo/igloo_alt.h>
using namespace igloo;

int goals (int laLigaGoals, int copaDelReyGoals, int championsLeagueGoals) {
  return laLigaGoals + copaDelReyGoals + championsLeagueGoals;
}

Describe(Sample)
{
    It(Tests)
    {
        Assert::That(goals(0,0,0), Equals(0));
        Assert::That(goals(43, 10, 5), Equals(58));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}