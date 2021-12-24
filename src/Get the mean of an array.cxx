// https://www.codewars.com/kata/563e320cee5dddcf77000158

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>

int get_average(std::vector <int> marks)
{
  return std::accumulate(marks.begin(), marks.end(), 0) / marks.size();
}

Describe(array_average)
{
    It(basic_test)
    {
        Assert::That(get_average(std::vector <int>{2, 2, 2, 2}), Equals(2));
        Assert::That(get_average(std::vector <int>{1, 5, 87, 45, 8, 8}), Equals(25));
        Assert::That(get_average(std::vector <int>{2,5,13,20,16,16,10}), Equals(11));
        Assert::That(get_average(std::vector <int>{1,2,15,15,17,11,12,17,17,14,13,15,6,11,8,7}), Equals(11));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}