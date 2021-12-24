// https://www.codewars.com/kata/59cfc000aeb2844d16000075

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <utility>
#include <cctype>

std::pair<std::string, std::string> capitalize(const std::string &s)
{
    std::string first, second;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i % 2)
        {
            first.push_back(s[i]);
            second.push_back(std::toupper(s[i]));
        }
        else
        {
            second.push_back(s[i]);
            first.push_back(std::toupper(s[i]));
        }
    }
    return std::make_pair(first, second);
}
#include <string>
#include <utility>

using namespace std;

Describe(Sample_Test)
{
    It(Basic_tests)
    {
        doTest("abcdef", {"AbCdEf", "aBcDeF"});
        doTest("codewars", {"CoDeWaRs", "cOdEwArS"});
        doTest("abracadabra", {"AbRaCaDaBrA", "aBrAcAdAbRa"});
        doTest("codewarriors", {"CoDeWaRrIoRs", "cOdEwArRiOrS"});
    }
    inline string pair2str(const pair<string,string> &p)
    {
        return "{\"" + p.first + "\", \"" + p.second + "\"}";
    }
    void doTest(const string &s, const pair<string,string> &expected)
    {
        pair<string,string> actual = capitalize(s);
        Assert::That(pair2str(actual), Equals(pair2str(expected)));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}