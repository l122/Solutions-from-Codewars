// https://www.codewars.com/kata/5700c9acc1555755be00027e

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Rotations
{
public:
    static bool containAllRots(const std::string &strng, std::vector<std::string> &arr)
    {
        if (strng == "")
            return true;

        // get all version of input string
        std::vector<std::string> words;
        std::string temp = strng;
        words.push_back(temp);

        int times = temp.size() - 1;
        for (int i = 0; i < times; ++i)
        {
            temp = temp.substr(1) + temp.substr(0, 1);
            words.push_back(temp);
        }

        // search each string version in the array
        for (const auto &word : words)
        {
            auto found = std::find(arr.begin(), arr.end(), word);
            if (found == arr.end())
            {
                return false;
            }
        }
        return true;
    }
};

#include <string>
#include <vector>

void testequal(bool ans, bool sol)
{
    Assert::That(ans, Equals(sol));
}
Describe(containAllRots_Tests)
{
    It(Fixed_Tests)
    {
        std::string s1 = "bsjq";
        std::vector<std::string> v1 = {"bsjq", "qbsj", "sjqb", "twZNsslC", "jqbs"};
        bool b = Rotations::containAllRots(s1, v1);
        testequal(b, true);
        s1 = "";
        v1 = {};
        b = Rotations::containAllRots(s1, v1);
        testequal(b, true);
        s1 = "";
        v1 = {"bsjq", "qbsj"};
        b = Rotations::containAllRots(s1, v1);
        testequal(b, true);
        s1 = "XjYABhR";
        v1 = {"TzYxlgfnhf", "yqVAuoLjMLy", "BhRXjYA", "YABhRXj", "hRXjYAB", "jYABhRX", "XjYABhR", "ABhRXjY"};
        b = Rotations::containAllRots(s1, v1);
        testequal(b, false);
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}