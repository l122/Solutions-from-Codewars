// https://www.codewars.com/kata/592fd8f752ee71ac7e00008a

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

std::string covfefe(std::string s)
{
    int pos;
    pos = s.find("coverage");
    if (pos != -1)
    {
        do
        {
            s.replace(pos, 8, "covfefe");
            pos = s.find("coverage");
        } while (pos != -1);
    }
    else
    {
        s += " covfefe";
    }
    return s;
}

Describe(test_covfefe)
{
    It(basic_test)
    {
        Assert::That(covfefe("coverage"), Equals("covfefe"));
        Assert::That(covfefe("coverage coverage"), Equals("covfefe covfefe"));
        Assert::That(covfefe("nothing"), Equals("nothing covfefe"));
        Assert::That(covfefe("double space "), Equals("double space  covfefe"));
        Assert::That(covfefe("covfefe"), Equals("covfefe covfefe"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}