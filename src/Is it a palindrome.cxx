// https://www.codewars.com/kata/57a1fd2ce298a731b20006a4

#include <igloo/igloo_alt.h>
using namespace igloo;
#include <string>
#include <algorithm>

bool isPalindrom (const std::string& str)
{
    std::string s1(str);
    std::transform(s1.begin(), s1.end(), s1.begin(), tolower);
    std::string s2(s1);
    std::reverse(s2.begin(), s2.end());
    return s1 == s2; 
}


Describe(The_isPalindrom_function)
{
    It(should_work_for_some_examples)
    {
        Assert::That(isPalindrom("a"), Equals(true));
        Assert::That(isPalindrom("aba"), Equals(true));
        Assert::That(isPalindrom("Abba"), Equals(true));
        Assert::That(isPalindrom("hello"), Equals(false));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}