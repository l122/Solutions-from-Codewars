// https://www.codewars.com/kata/5667525f0f157f7a0a000004

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class EightiesKids5
{
public:
    static string bucketOf(const string &said)
    {
        map<string, string> wordsMap = {{"water", "water"},
                                        {"wet", "water"},
                                        {"wash", "water"},
                                        {"slime", "slime"},
                                        {"i don't know", "slime"}};

        string words[] = {"water", "wet", "wash", "slime", "i don't know"};

        string result = "";
        string input = said;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        for (size_t i = 0; i < 5; ++i)
        {
            if (input.find(words[i]) != string::npos)
            {
                result = (!result.empty() && result != wordsMap[words[i]])
                             ? "sludge"
                             : wordsMap[words[i]];
            }
        }
        if (result.empty())
            result = "air";
        return result;
    }
};

Describe(EightiesKids5Test)
{
    It(test1)
    {
        doTest("water", "water");
    }

    It(test2)
    {
        doTest("slime", "slime");
    }

    It(test3)
    {
        doTest("sludge", "Will I get wet? I don't know.");
    }

    It(test4)
    {
        doTest("air", "This should be safe.");
    }
    
    void doTest(const string &expected, const string &said)
    {
        string actual = EightiesKids5::bucketOf(said);
        Assert::That(actual, Equals(expected));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}