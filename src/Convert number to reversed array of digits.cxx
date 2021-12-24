// https://www.codewars.com/kata/5583090cbe83f4fd8c000051
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>

// My first solution
// std::vector<int> digitize(unsigned long n) 
// {   
//     std::vector<int> out;
//     unsigned long temp = n;
//     do
//     {
//         out.push_back(static_cast<int>(temp % 10));
//         temp /= 10;
//     }while (temp);
//     return out;
// }

// My second solution
std::vector<int> digitize(unsigned long n) 
{   
    std::string temp = std::to_string(n);
    std::vector<int> out;
    std::for_each(temp.rbegin(), temp.rend(), [&out](auto a)mutable{out.push_back(std::stoi(&a));});
    return out;
}

Describe(digitize_method)
{
    It(basic_tests)
    {
        Assert::That(digitize(35231), Equals(std::vector<int>({ 1,3,2,5,3 })));
        Assert::That(digitize(0), Equals(std::vector<int>({ 0 })));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}