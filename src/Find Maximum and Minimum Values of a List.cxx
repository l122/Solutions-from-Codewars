// https://www.codewars.com/kata/577a98a6ae28071780000989
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int min(vector<int> list){
    
    // std::cout << *std::min_element(list.begin(), list.end()) << std::endl;
    // std::cout << *std::ranges::min_element(list) << std::endl;
    return *std::min_element(list.begin(), list.end());
    // return *std::min_element(list.begin(), list.end());
}

int max(vector<int> list){
    
    return *std::max_element(list.begin(), list.end());
}

Describe(Test){
    It(Examples){
        using V = std::vector<int>;
        Assert::That(min(V{-52, 56, 30, 29, -54, 0, -110} ), Equals(-110));
        Assert::That(min(V{42, 54, 65, 87, 0} ), Equals(0));
        Assert::That(max(V{4,6,2,1,9,63,-134,566}), Equals(566));
        Assert::That(max(V{5}), Equals(5));
	  }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}