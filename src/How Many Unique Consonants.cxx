// https://www.codewars.com/kata/5a19226646d843de9000007d

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

unsigned int countConsonants(const std::string &str)
{
    std::set<char> charSet;
    std::string vowels = "aeiou";

    for (const auto c : str)
    {
        if (std::isalpha(c) && vowels.find(std::tolower(c)) == std::string::npos)
        {
            charSet.insert(std::tolower(c));
        }
    }

    return charSet.size();
}

Describe(CountConsonants){
  It(BasicTests){
    Assert::That(countConsonants("sillystring"), Equals(7));
    Assert::That(countConsonants("aeiou"), Equals(0));
    Assert::That(countConsonants("abcdefghijklmnopqrstuvwxyz"), Equals(21));
    Assert::That(countConsonants("Count my unique consonants!!"), Equals(7));
    Assert::That(countConsonants(""), Equals(0));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}