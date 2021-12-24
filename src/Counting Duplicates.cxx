// From Codewars.com
// https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <algorithm>

size_t duplicateCount(const std::string &in); // helper for tests

size_t duplicateCount(const char *in)
{
    using namespace std;

    string view(in);
    transform(view.begin(), view.end(), view.begin(),
              [](unsigned char c) { return tolower(c); });
    set<char> chars(view.begin(), view.end());
    multiset<char> multichars(view.begin(), view.end());
    size_t r = 0;
    for (auto c : chars)
    {
        r += (multichars.count(c) > 1) ? 1 : 0;
    }
    return r;
}

Describe(sample_Tests)
{
    It(small_Tests)
    {
        Assert::That(duplicateCount(" "), Equals(0));
        Assert::That(duplicateCount(""), Equals(0));
        //Assert::That(duplicateCount("asdfghjkl;'\\"), Equals(0));
        //Assert::That(duplicateCount("asdfghjkl;'\\'"), Equals(1));
        Assert::That(duplicateCount("aabbcde"), Equals(2));
        Assert::That(duplicateCount("aabBcde"), Equals(2));
        Assert::That(duplicateCount("Indivisibility"), Equals(1));
        Assert::That(duplicateCount("Indivisibilities"), Equals(2));
        Assert::That(duplicateCount("ABBA"), Equals(2));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}