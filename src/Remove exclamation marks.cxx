// https://www.codewars.com/kata/57a0885cbb9944e24c00008e
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

// // My frist solution
// #include <regex>
// std::string removeExclamationMarks(std::string str){
//   return std::regex_replace(str, std::regex("!"), "");
// }

// Somebody else's solution
#include <algorithm>
std::string removeExclamationMarks(std::string str){

    str.erase(std::remove(str.begin(), str.end(), '!'), str.end());
    return str;

//   auto remaining = std::remove(str.begin(), str.end(), '!');
//     str.erase(remaining, str.end());
  
//   return str;
}

Describe(RemoveExclamationMarks){
  It(BasicTests){
    // Assert::That(removeExclamationMarks("Hello World!"), Equals("Hello World"));
    // Assert::That(removeExclamationMarks("Hello World!!!"), Equals("Hello World"));
    // Assert::That(removeExclamationMarks("Hi! Hello!"), Equals("Hi Hello"));
    Assert::That(removeExclamationMarks("Hi!!! Hello!"), Equals("Hi Hello"));
    Assert::That(removeExclamationMarks("Hi! He!l!lo!"), Equals("Hi Hello"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}