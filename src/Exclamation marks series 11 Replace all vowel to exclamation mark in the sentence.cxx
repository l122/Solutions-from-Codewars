// https://www.codewars.com/kata/57fb09ef2b5314a8a90001ed
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

//// Solution 1
// std::string replace(const std::string &s)
// {
//     std::string mask("aeiouAEIOU");
//     std::string out(s);
//     for (auto & l:out){
//         if (mask.find(l) != std::string::npos){
//             l = '!';
//         }
//     }

//     return out;
// }




//// Solution 2
// #include <algorithm>
// std::string replace(const std::string &s)
// {
//     std::string out(s);
//     // std::string mask("aeiouAEIOU");
//     // auto isVowel = [&mask](auto l){
//     //     return mask.find(l) != std::string::npos;
//     // };
//     // std::replace_if(out.begin(), out.end(), isVowel, '!');

//     std::replace_if(out.begin(), out.end(), [](auto l){
//         return std::string("aeiouAEIOU").find(l) != std::string::npos;}, 
//         '!');

//     return out;
// }

////The best solution
#include <regex>

std::string replace(const std::string &s)
{
    return std::regex_replace(s, std::regex("[aeiouAEIOU]"), "!");
}

Describe(Sample_Test)
{
    It(Basic_Tests)
    {
        Assert::That(replace("Hi!"),      Equals("H!!"));
        Assert::That(replace("!Hi! Hi!"), Equals("!H!! H!!"));
        Assert::That(replace("aeiou"),    Equals("!!!!!"));
        Assert::That(replace("ABCDE"),    Equals("!BCD!"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}