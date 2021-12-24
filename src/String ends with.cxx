// https://www.codewars.com/kata/51f2d1cafc9c0f745c00037d/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>
#include <random>

bool solution(std::string const &str, std::string const &ending) {
//other solutions
// return str.size() >= ending.size() && str.compare(str.size() - ending.size(), std::string::npos, ending) == 0;
return (std::string(str.end() - ending.size(), str.end()) == ending);


// my solution
  std::string::size_type n = str.rfind(ending);
  return n != std::string::npos ? (str.size() - n) == ending.size() : false;
}

std::string make_word(int min, int max)
  {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
  
    std::string possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int length = ceil((dis(gen) * max) + min);
    std::string word = "";
    
    for(int i = 0; i < length; i++)
      word += possible[floor(dis(gen) * possible.size())];
      
    return word;
  }

Describe(Tests)
{
  It(Sample_Test_Cases)
  {
    Assert::That(solution("abcde", "cde"), Equals(true));
    Assert::That(solution("abcde", "abc"), Equals(false));
    Assert::That(solution("abc", ""), Equals(true));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}