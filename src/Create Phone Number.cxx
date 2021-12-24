// https://www.codewars.com/kata/525f50e3b73515a6db000b83

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string createPhoneNumber(const int arr[10])
{
    std::string result = "(XXX) XXX-XXXX";

    size_t i = 0;
    for (auto &symbol : result)
    {
        if (symbol == 'X')
        {
            symbol = std::to_string(arr[i])[0];
            ++i;
        }
    }

    return result;
}

//Version 2
std::string createPhoneNumber2(const int arr[10])
{
    std::string result = "(XXX) XXX-XXXX";

    size_t i = 0;
    for (auto &symbol : result)
    {
        if (symbol == 'X')
        {
            symbol = '0' + arr[i];
            ++i;
        }
    }

    return result;
}

using arr = int [10];

#include <utility>

Describe(CreatePhoneNumber) {
    It(BasicTests) {    
        Assert::That(createPhoneNumber(std::move(arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0})), Equals("(123) 456-7890"));
        Assert::That(createPhoneNumber(std::move(arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0})), Equals("(123) 456-7890"));
        Assert::That(createPhoneNumber(std::move(arr{1, 1, 1, 1, 1, 1, 1, 1, 1, 1})), Equals("(111) 111-1111"));
        Assert::That(createPhoneNumber(std::move(arr{1, 2, 3, 4, 5, 6, 8, 8, 0, 0})), Equals("(123) 456-8800"));
        Assert::That(createPhoneNumber(std::move(arr{0, 2, 3, 0, 5, 6, 0, 8, 9, 0})), Equals("(023) 056-0890"));
        Assert::That(createPhoneNumber(std::move(arr{0, 0, 0, 0, 0, 0, 0, 0, 0, 0})), Equals("(000) 000-0000"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}