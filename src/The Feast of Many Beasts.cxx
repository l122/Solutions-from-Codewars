// https://www.codewars.com/kata/5aa736a455f906981800360d/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>

bool feast(std::string beast, std::string dish){
  std::cout << beast.front() << " = " << dish.front() 
          << " && " << beast.back() << " = " << dish.back() << std::endl;
  return beast.front() == dish.front() && beast.back() == dish.back();
}

Describe(Feast){
  It(BasicTests){
    Assert::That(feast("great blue heron", "garlic naan"), Equals(true));
    Assert::That(feast("chickadee", "chocolate cake"), Equals(true));
    Assert::That(feast("brown bear", "bear claw"), Equals(false));
    Assert::That(feast("marmot", "mulberry tart"), Equals(true));
    Assert::That(feast("porcupine", "pie"), Equals(true));
    Assert::That(feast("electric eel", "lasagna"), Equals(false));
    Assert::That(feast("slow loris", "salsas"), Equals(true));
    Assert::That(feast("ox", "orange lox"), Equals(true));
    Assert::That(feast("blue-footed booby", "blueberry"), Equals(true));
    Assert::That(feast("blue-footed booby", "binary human"), Equals(false));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}