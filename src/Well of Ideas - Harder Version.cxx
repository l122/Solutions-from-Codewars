//https://www.codewars.com/kata/57f22b0f1b5432ff09001cab/train/cpp


#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string well(const std::vector<std::vector<std::string>>& arr) {
  int goodIdeas = 0;
  for (const auto & ideas : arr){
    goodIdeas += std::count_if(ideas.begin(), ideas.end(), 
      [](auto idea){
        std::transform(idea.begin(), idea.end(), idea.begin(), ::tolower);
        return idea == "good";
      });
    // for (auto idea : ideas){
    //   std::transform(idea.begin(), idea.end(), idea.begin(), ::tolower);
    //   if (idea == "good") 
    //     ++goodIdeas;
    //   if (goodIdeas > 2)
    //     return "I smell a series!";
    // }
  }
  return !goodIdeas ? "Fail!" : goodIdeas <= 2 ? "Publish!" : "I smell a series!";
}

Describe(Fixed_tests) {
  It(Should_fail) {
    Assert::That(well(std::vector<std::vector<std::string>>{
      std::vector<std::string>{"bad", "bAd", "bad"},
      std::vector<std::string>{"bad", "bAd", "bad"},
      std::vector<std::string>{"bad", "bAd", "bad"},
    }), Equals("Fail!"));
  }
  It(Should_publish) {
    Assert::That(well(std::vector<std::vector<std::string>>{
      std::vector<std::string>{"gOOd", "bad", "BAD", "bad", "bad"},
      std::vector<std::string>{"bad", "bAd", "bad"},
      std::vector<std::string>{"GOOD", "bad", "bad", "bAd"},
    }), Equals("Publish!"));
  }
  It(Should_smell_a_series) {
    Assert::That(well(std::vector<std::vector<std::string>>{
      std::vector<std::string>{"gOOd", "bAd", "BAD", "bad", "bad", "GOOD"},
      std::vector<std::string>{"bad"},
      std::vector<std::string>{"gOOd", "BAD"},
    }), Equals("I smell a series!"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}