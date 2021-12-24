// https://www.codewars.com/kata/5a145ab08ba9148dd6000094/train/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string doubles(std::string s)
{
    bool flag;
    do
    {
        flag = false;
        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                flag = true;
            }
        }
    } while (flag);
    return s;
}

//Best practice version
std::string doubles2(const std::string &s)
{
    std::string result;

    for (auto c : s)
    {
        if (result.size() > 0 && result.back() == c)
        {
            result.pop_back();
        }
        else
        {
            result.push_back(c);
        }
    }

    return result;
}
Describe(String_doubles)
{
    It(Example_tests)
    {
        Assert::That(doubles("abbbzz"), Equals("ab"));
        Assert::That(doubles("zzzzykkkd"),Equals("ykd"));
        Assert::That(doubles("abbcccdddda"),Equals("aca"));
        Assert::That(doubles("vvvvvoiiiiin"),Equals("voin"));  
        Assert::That(doubles("rrrmooomqqqqj"), Equals("rmomj"));
        Assert::That(doubles("xxbnnnnnyaaaaam"),Equals("bnyam"));
   
    }
}; 

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}