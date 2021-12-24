// https://www.codewars.com/kata/58dced7b702b805b200000be
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <cmath>
#include <iostream>

struct Point
{
    Point(int i, int j) : x(i), y(j) {}
    int x, y;
};

// My solution
double distance_between_two_points(const Point& a, const Point& b) {
    double nX = a.x - b.x;
    double nY = a.y - b.y;
    double dist = std::round(std::sqrt(nX*nX + nY*nY) * 1000000) / 1000000;
    return dist;
}

// // The best solution
// double distance_between_two_points(const Point& a, const Point& b) {
//     return std::hypot(a.x - b.x, a.y - b.y);
// }

Describe(test_cases)
{
    It(test_1)
    {
        Assert::That(distance_between_two_points(Point{3, 3}, Point{3, 3}), Equals(0));
    }

    It(test_2)
    {
        Assert::That(distance_between_two_points(Point{5, 1}, Point{1, 4}), EqualsWithDelta(5 , 0.000001));
    }
};

int main(int argc, const char *argv[])
{
  return TestRunner::RunAllTests();
}