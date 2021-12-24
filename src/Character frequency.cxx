// https://www.codewars.com/kata/53e895e28f9e66a56900011a

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <cstddef> // std::size_t
#include <string>
#include <utility> // std::pair
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::pair<char, std::size_t>> letter_frequency(const std::string &input)
{
    std::map<char, std::size_t> counter;
    for (char symbol : input)
    {
        if (std::isalpha(symbol))
        {
            ++counter[std::tolower(symbol)];
        }
    }

    std::vector<std::pair<char, std::size_t>> output(counter.begin(), counter.end());

    std::sort(output.begin(), output.end(), [](std::pair<char, std::size_t> a, std::pair<char, std::size_t> b)
              { return a.second == b.second ? a.first < b.first : a.second > b.second; });

    return output;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, std::vector<T> const &values)
{
    for (auto const &value : values)
    {
        output << "{" << value.first << ", " << value.second << "} ";
    }
    return output;
}

#include <cstddef> // std::size_t
#include <utility> // std::pair
#include <vector>

Describe(SampleTests)
{
    It(SampleTest)
    {
        typedef std::vector<std::pair<char, std::size_t>> list_t;
        Assert::That(letter_frequency("aaAabb dddDD hhcc"), Equals(list_t{{'d',5}, {'a',4}, {'b',2}, {'c',2}, {'h',2}}));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}