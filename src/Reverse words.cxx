// https://www.codewars.com/kata/5259b20d6021e9e14c0010d4/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string reverse_words(std::string str)
{
    std::string result;
    std::stringstream ss(str);

    std::string buff = "";

    char c;
    while (ss.get(c))
    {
        if (c != ' ')
        {
            buff.push_back(c);
        }
        else
        {
            if (buff.size() != 0)
            {
                std::reverse(buff.begin(), buff.end());
                result += buff;
            }
            result.push_back(c);
            buff.clear();
        }
    }

    if (buff.size() != 0)
    {
        std::reverse(buff.begin(), buff.end());
        result += buff;
    }

    return result;
}

// Other's solution
std::string reverse_words2(std::string str)
{
    auto begin = str.begin();
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (*it == ' ')
        {
            auto end = it;
            std::reverse(begin, end);
            begin = it + 1;
        }
    }
    std::reverse(begin, str.end());
    return str;
}

Describe(Tests)
{
  It(Sample_Test_Cases)
  {
    Assert::That(reverse_words("The quick brown fox jumps over the lazy dog."), Equals("ehT kciuq nworb xof spmuj revo eht yzal .god"));
    Assert::That(reverse_words("apple"), Equals("elppa"));
    Assert::That(reverse_words("a b c d"), Equals("a b c d"));
    Assert::That(reverse_words("double  spaced  words"), Equals("elbuod  decaps  sdrow"));
    Assert::That(reverse_words(""), Equals(""));
    Assert::That(reverse_words("ab   ba   cd"), Equals("ba   ab   dc"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}
