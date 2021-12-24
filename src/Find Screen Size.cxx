// https://www.codewars.com/kata/5bbd279c8f8bbd5ee500000f/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <sstream>
#include <string>

std::string find_screen_height(int width, const std::string &ratio)
{
    std::istringstream ss(ratio);
    int w = 0,
        h = 0,
        height = 0;
    char c;
    ss >> w >> c >> h;
    height = width * h / w;

    return std::to_string(width) + "x" + std::to_string(height);

    // int n = stoi(ratio), d = stoi(ratio.substr(ratio.find(':') + 1));
    // return std::to_string(width) + "x" + std::to_string(width * d / n);
}

#include <string>

std::string find_screen_height(int width, const std::string &ratio);

void do_test(int width, const std::string &ratio, const std::string &expected)
{
    Assert::That(find_screen_height(width, ratio), Equals(expected));
}

Describe(sample_test)
{
    It(example_tests)
    {
        do_test(1024,  "4:3", "1024x768");
        do_test(1280, "16:9", "1280x720");
        do_test(3840, "32:9", "3840x1080");
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}