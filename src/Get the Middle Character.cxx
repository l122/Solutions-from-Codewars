// https://www.codewars.com/kata/56747fd5cb988479af000028
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string get_middle(std::string input)
{
    return (input.size() % 2) ? input.substr(input.size() / 2, 1) : input.substr((input.size() / 2) - 1, 2);
}
Describe(get_middle_algorithm)
{
    It(should_handle_basic_tests)
    {
        Assert::That(get_middle("test"), Equals("es"));
        Assert::That(get_middle("testing"), Equals("t"));;
    }
};
int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}