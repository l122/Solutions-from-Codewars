// https://www.codewars.com/kata/55c28f7304e3eaebef0000da
#include <vector>

std::vector<int> createVector(const int n)
{
	std::vector<int> res;

	for (int i = 1; i <= n; ++i)
	{
		res.push_back(i);
	}

	return res;
}

#include <igloo/igloo_alt.h>
using namespace igloo;
#include <random>

// TODO: Replace examples and use TDD development by writing your own tests

Describe(exampleTests)
{
    It(BasicTests1)
    {
        std::vector<int> res = {1};
        Assert::That(createVector(1), Equals(res));
    }
    
    It(BasicTests2)
    {
        std::vector<int> res = {1, 2};
        Assert::That(createVector(2), Equals(res));
    }
    
    It(BasicTests3)
    {
        std::vector<int> res = {1, 2, 3};
        Assert::That(createVector(3), Equals(res));
    }
    
    It(BasicTests4)
    {
        std::vector<int> res = {1, 2, 3, 4};
        Assert::That(createVector(4), Equals(res));
    }
    
    It(BasicTests5)
    {
        std::vector<int> res = {1, 2, 3, 4, 5};
        Assert::That(createVector(5), Equals(res));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}