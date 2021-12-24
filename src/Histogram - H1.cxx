// https://www.codewars.com/kata/57d532d2164a67cded0001c7

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <vector>

std::string histogram(std::vector<int> results)
{
    std::string ret;

    for (int i = 5; i >= 0; --i)
    {
        if (results[i] != 0)
        {
            ret = ret + std::to_string(i + 1) + "|" + std::string(results[i], '#') + " " + std::to_string(results[i]) + "\n";
        }
        else
        {
            ret = ret + std::to_string(i + 1) + "|" + "\n";
        }
    }

    return ret;
}

Describe(ExampleTests)
{
    It(BasicTest)
    {
        std::string expected = 
            "6|##### 5\n"
            "5|\n"
            "4|# 1\n"
            "3|########## 10\n"
            "2|### 3\n"
            "1|####### 7\n";
        
        std::string actual = histogram({ 7, 3, 10, 1, 0, 5 });
        
        Assert::That(actual, Is().EqualTo(expected));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}