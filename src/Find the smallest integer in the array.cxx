// https://www.codewars.com/kata/55a2d7ebe362935a210000b2
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>


int findSmallest(vector <int> list)
{
    return *std::min_element(list.begin(), list.end());
}

Describe(Smallest_Number)
{
    It(Check_Positive_Values)
    {
        Assert::That(findSmallest({3,5,2}), Equals(2));
          Assert::That(findSmallest({7,4,6,8}), Equals(4));  
            Assert::That(findSmallest({17,21,15,36,96}), Equals(15));
              Assert::That(findSmallest({3,9,13,10,5,3,9,5}), Equals(3));
    }
    It(Check_Negative_Values)
    {
      Assert::That(findSmallest({-12,-52,-27}), Equals(-52));  
        Assert::That(findSmallest({-3,-27,-4,-2,-27,-2}), Equals(-27));
            Assert::That(findSmallest({-16,-37,-8,-46,-29}), Equals(-46));
              Assert::That(findSmallest({-14,-102,-96,-36,-46,-15,-44}), Equals(-102));
    }
    It(Check_Mixture_Values)
    {
      Assert::That(findSmallest({12,0,-27}), Equals(-27));  
        Assert::That(findSmallest({-13,-50,57,13,67,-13,57,108,67}), Equals(-50));
          Assert::That(findSmallest({-23,12,0,-47,-3,24}), Equals(-47));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}