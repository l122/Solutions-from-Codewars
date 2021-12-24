// https://www.codewars.com/kata/53697be005f803751e0015aa/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <map>

static std::map<char, char> incodeVowels = {{'a', '1'},
                                            {'e', '2'},
                                            {'i', '3'},
                                            {'o', '4'},
                                            {'u', '5'}};

static std::map<char, char> decodeVowels = {{'1', 'a'},
                                            {'2', 'e'},
                                            {'3', 'i'},
                                            {'4', 'o'},
                                            {'5', 'u'}};

std::string encode(const std::string &str)
{
    std::string output = str;
    for (char &letter : output)
    {
        auto search = incodeVowels.find(letter);
        if (search != incodeVowels.end())
        {
            letter = incodeVowels[letter];
        }
    }
    return output;
}

std::string decode(const std::string &str)
{
    std::string output = str;
    for (char &letter : output)
    {
        auto search = decodeVowels.find(letter);
        if (search != decodeVowels.end())
        {
            letter = decodeVowels[letter];
        }
    }
    return output;
}

Describe(Sample_Tests) {
  It(Tests) {
    Assert::That(encode("hello"), Equals("h2ll4"));
    Assert::That(encode("How are you today?"), Equals("H4w 1r2 y45 t4d1y?"));
    Assert::That(encode("This is an encoding test."), Equals("Th3s 3s 1n 2nc4d3ng t2st."));
    
    Assert::That(decode("h2ll4"), Equals("hello"));
    Assert::That(decode("H4w 1r2 y45 t4d1y?"), Equals("How are you today?"));
    Assert::That(decode("Th3s 3s 1n 2nc4d3ng t2st."), Equals("This is an encoding test."));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}