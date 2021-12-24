// https://www.codewars.com/kata/5865918c6b569962950002a1

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <algorithm>

unsigned int strCount(std::string word, char letter){
    return std::count(word.begin(), word.end(), letter);
}

Describe(StrCount){
  It(BasicTests){
    Assert::That(strCount("Hello", 'o'), Equals(1));
    Assert::That(strCount("Hello", 'l'), Equals(2));
    Assert::That(strCount("Hello", 'q'), Equals(0));
    Assert::That(strCount("Pippi", 'p'), Equals(2));
    Assert::That(strCount("", 'l'), Equals(0));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}