// https://www.codewars.com/kata/568d0dd208ee69389d000016

#include <igloo/igloo_alt.h>
using namespace igloo;

int rental_car_cost(int d){
  return d >= 7 ? d * 40 - 50 : d >= 3 ? d * 40 - 20 : d * 40;
}

Describe(Transportation_on_vacation)
{
    It(Fixed_tests)
    {
        Assert::That(rental_car_cost(1), Equals(40));
        Assert::That(rental_car_cost(2), Equals(80));
        Assert::That(rental_car_cost(3), Equals(100));
        Assert::That(rental_car_cost(4), Equals(140));
        Assert::That(rental_car_cost(5), Equals(180));
        Assert::That(rental_car_cost(6), Equals(220));
        Assert::That(rental_car_cost(7), Equals(230));
        Assert::That(rental_car_cost(8), Equals(270));
        Assert::That(rental_car_cost(9), Equals(310));
        Assert::That(rental_car_cost(10), Equals(350));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}