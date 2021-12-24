// https://www.codewars.com/kata/576b93db1129fcf2200001e6
#include <vector>

#include <igloo/igloo_alt.h>
using namespace igloo;


int sum(std::vector<int> numbers)
{
    if (numbers.size() <= 1)
        return 0;
    
    int sum = 0;
    int smallest = numbers[0];
    int largest = numbers[0];

    for (const auto & n : numbers){
        if (smallest > n){
            smallest = n;
        }
        if (largest < n){
            largest = n;
        }
        sum += n;
    }
    sum -= smallest + largest;
    return sum;
}

Describe(ExampleTests)
{
    It(Test1)
    {
        Assert::That(sum({ 6, 2, 1, 8, 10 }), Equals(16));
        Assert::That(sum({ 1, 1, 11, 2, 3 }), Equals(6));
        Assert::That(sum({ 6}), Equals(0));
        Assert::That(sum({}), Equals(0));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}