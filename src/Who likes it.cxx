// https://www.codewars.com/kata/5266876b8f4bf2da9b000362
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <vector>

std::string likes(const std::vector<std::string> &names)
{
    std::vector<std::string> outputs = {
        "no one likes this",
        "XXX likes this",
        "XXX and XXX like this",
        "XXX, XXX and XXX like this",
        "XXX, XXX and NNN others like this"};

    size_t option = 0;
    size_t NNN = 0;

    if (names.size() >= 4)
    {
        option = 4;
        NNN = names.size() - 2;
    }
    else
    {
        option = names.size();
    }

    int limit = names.size() > 3 ? 2 : names.size();
    for (int i = 0; i < limit; ++i)
    {
        outputs[option].replace(outputs[option].find("XXX"), 3, names[i]);
    }

    if (option == 4)
    {
        outputs[option].replace(outputs[option].find("NNN"), 3, std::to_string(NNN));
    }

    return outputs[option];
}

//A simple and better solution
std::string likes2(const std::vector<std::string> &names)
{
    switch (names.size())
    {
    case 0:
        return "no one likes this";
    case 1:
        return names[0] + " likes this";
    case 2:
        return names[0] + " and " + names[1] + " like this";
    case 3:
        return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    default:
        return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}

Describe(sample_tests)
{
    It(should_return_correct_text)
    {
        Assert::That(likes({}), Equals("no one likes this"));
        Assert::That(likes({"Peter"}), Equals("Peter likes this"));
        Assert::That(likes({"Jacob", "Alex"}), Equals("Jacob and Alex like this"));
        Assert::That(likes({"Max", "John", "Mark"}), Equals("Max, John and Mark like this"));
        Assert::That(likes({"Alex", "Jacob", "Mark", "Max"}), Equals("Alex, Jacob and 2 others like this"));
    }
};
int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}