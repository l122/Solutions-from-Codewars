// https://www.codewars.com/kata/59c5f4e9d751df43cf000035/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

int solve(std::string s)
{
    int longestVowel = 0;
    int temp = 0;
    //vowels : aeiou
    std::string aeiou = "aeiou";
    for (const auto s : s)
    {
        if (aeiou.find(s) != std::string::npos)
        {
            ++temp;
        }
        else
        {
            if (temp > longestVowel)
            {
                longestVowel = temp;
            }
            temp = 0;
        }
    }
    if (temp > longestVowel)
    {
        longestVowel = temp;
    }

    return longestVowel;
}
Describe(Simple_Square_numbers)
{
    It(Example_tests)
    {
        Assert::That(solve("ultrarevolutionariees"), Equals(3));
        Assert::That(solve("codewarriors"),Equals(2));
        Assert::That(solve("suoidea"),Equals(3));
        Assert::That(solve("strengthlessnesses"),Equals(1)); 
        Assert::That(solve("mnopqriouaeiopqrstuvwxyuaeiouaeiou"),Equals(11));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}