// https://www.codewars.com/kata/5b37a50642b27ebf2e000010

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <regex>

// Version 1: using string.find
int sum_of_a_beach(std::string input)
{
    int ret = 0,
        pos = 0;
    std::array<std::string, 4> words = {"sand", "water", "fish", "sun"};

    //transform input to lower
    std::transform(input.begin(), input.end(), input.begin(), tolower);

    //for each word in array count it in the input
    for (const auto &w : words)
    {
        do
        {
            pos = input.find(w, pos);
            if (pos != std::string::npos)
                ++ret;
            ++pos;
        } while (pos);
    }
    return ret;
}

//Verstion 2: using regex
int sum_of_a_beach2(std::string input)
{
    int ret = 0;
    std::array<std::string, 4> words = {"sand", "water", "fish", "sun"};
    std::regex ex;
    std::smatch sm;
    //transform input to lower
    std::transform(input.begin(), input.end(), input.begin(), tolower);
    //search each word in the input using regular expression
    for (const auto &w : words)
    {
        ex = w;
        auto words_begin =
            std::sregex_iterator(input.begin(), input.end(), ex);
        auto words_end = std::sregex_iterator();

        ret += std::distance(words_begin, words_end);
    }
    return ret;
}

Describe(sample_tests)
{
    It(should_pass_sample_tests)
    {
        Assert::That(1, Equals(sum_of_a_beach("SanD")));
        Assert::That(1, Equals(sum_of_a_beach("sunshine")));
        Assert::That(4, Equals(sum_of_a_beach("sunsunsunsun")));
        Assert::That(1, Equals(sum_of_a_beach("123FISH321")));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}