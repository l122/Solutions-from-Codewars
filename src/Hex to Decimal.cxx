// https://www.codewars.com/kata/57a4d500e298a7952100035d

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <sstream>

int hexToDec(std::string hexString)
{
    return std::stoi(hexString, nullptr, 16);
    // std::stringstream ss;
    // ss << std::hex << hexString;
    // int ret = 0;
    // ss >> ret;
    // return ret;
}

Describe(ExampleTests)
{
    It(BasicTests)
    {
        int expected = 1;
        int actual = hexToDec("1");
        Assert::That(actual, Is().EqualTo(expected));
        
        expected = 10;
        actual = hexToDec("a");
        Assert::That(actual, Is().EqualTo(expected));
        
        expected = 16;
        actual = hexToDec("10");
        Assert::That(actual, Is().EqualTo(expected));
        
        expected = 255;
        actual = hexToDec("FF");
        Assert::That(actual, Is().EqualTo(expected));
        
        expected = -12;
        actual = hexToDec("-C");
        Assert::That(actual, Is().EqualTo(expected));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}