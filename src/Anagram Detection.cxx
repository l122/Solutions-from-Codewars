// https://www.codewars.com/kata/529eef7a9194e0cbc1000255

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

bool isAnagram(std::string test, std::string original)
{
    //change all to lowercase
    std::transform(test.begin(), test.end(), test.begin(), tolower);
    std::transform(original.begin(), original.end(), original.begin(), tolower);

    //sort
    std::sort(test.begin(), test.end());
    std::sort(original.begin(), original.end());

    //return comparison
    return test.compare(original) == 0;
}

Describe(IsAnagram){
  It(BasicTests){
    Assert::That(isAnagram("foefet", "toffee"), Equals(true));
    Assert::That(isAnagram("Buckethead", "DeathCubeK"), Equals(true));
    Assert::That(isAnagram("Twoo", "WooT"), Equals(true));
    Assert::That(isAnagram("dumble", "bumble"), Equals(false));
    Assert::That(isAnagram("around", "round"), Equals(false));
    Assert::That(isAnagram("ound", "round"), Equals(false));
    Assert::That(isAnagram("apple", "pale"), Equals(false));
    Assert::That(isAnagram("apple", "appeal"), Equals(false));
    Assert::That(isAnagram("apple", "appeal"), Equals(false));
    Assert::That(isAnagram("", ""), Equals(true));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}