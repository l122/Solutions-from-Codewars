// https://www.codewars.com/kata/515e188a311df01cba000003
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string get_planet_name(int id)
{
  std::string planets[] = {"", "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
  return planets[id];
}

Describe(planet_id_conversion)
{
    It(some_planets)
    {
        Assert::That(get_planet_name(2), Equals("Venus"));
        Assert::That(get_planet_name(5), Equals("Jupiter"));
        Assert::That(get_planet_name(3), Equals("Earth"));
        Assert::That(get_planet_name(4), Equals("Mars"));
        Assert::That(get_planet_name(8), Equals("Neptune"));
        Assert::That(get_planet_name(1), Equals("Mercury"));
    }
};



int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}