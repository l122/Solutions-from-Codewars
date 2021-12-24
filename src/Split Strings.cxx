// https://www.codewars.com/kata/515de9ae9dcfc28eb6000001

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> result;
    bool flag = false;
    size_t i;
    for (i = 0; i < s.size(); ++i)
    {
        if ((i + 1) % 2 == 0)
        {
            result.push_back(s.substr(i - 1, 2));
            flag = false;
        }
        else
        {
            flag = true;
        }
    }

    if (flag)
        result.push_back(std::string(s.substr(i - 1, 1) + "_"));

    return result;
}

//Version 2
std::vector<std::string> solution2(const std::string &s)
{
    std::vector<std::string> result;

    for (size_t i = 1; i < s.size(); i += 2)
    {
        result.push_back(s.substr(i - 1, 2));
    }

    if (s.size() % 2 != 0)
    {
        result.push_back(std::string(s.substr(s.size() - 1, 1) + "_"));
    }

    return result;
}

//Version 3
std::vector<std::string> solution3(const std::string &s)
{
    std::vector<std::string> result;
    for (size_t i = 0; i < s.size(); i += 2)
    {
        result.push_back(s.substr(i, 2));
    }

    if (s.size() % 2 != 0)
    {
        result[result.size() - 1] += "_";
    }

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, std::vector<T> const &values)
{
    for (auto const &value : values)
    {
        output << value << ", ";
    }
    return output;
}

// TODO: Replace examples and use TDD development by writing your own tests

void do_test(const std::string input, std::vector<std::string> expected){
    Assert::That(solution(input), Equals(expected));
}

Describe(sample_test)
{
    It(even_length)
    {
       do_test("abcdef", {"ab", "cd", "ef"});
       do_test("HelloWorld", {"He", "ll", "oW", "or", "ld"});
    }
    It(odd_length)
    {
       do_test("abcde", {"ab", "cd", "e_"});
       do_test("LovePizza", {"Lo", "ve", "Pi", "zz", "a_"});
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}