// https://www.codewars.com/kata/5a87449ab1710171300000fd/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

bool tidyNumber(int number)
{
    std::string unsortedNumber(std::to_string(number));

    std::string sortedNumber(std::to_string(number));
    std::sort(sortedNumber.begin(), sortedNumber.end());

    return !unsortedNumber.compare(sortedNumber);

    return std::is_sorted(unsortedNumber.begin(), unsortedNumber.end()); //better solution
}

#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

Describe(Tidy_Number_Tests)
{
    It(Check_Small_Values)
    {
        Assert::That(tidyNumber(12), Equals(true));
          Assert::That(tidyNumber(32), Equals(false));
            Assert::That(tidyNumber(39), Equals(true));
    }
    It(Check_Larger_Values)
    {
        Assert::That(tidyNumber(1024), Equals(false));
          Assert::That(tidyNumber(12576), Equals(false));
            Assert::That(tidyNumber(13579), Equals(true));
    }
    
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}