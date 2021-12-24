// https://www.codewars.com/kata/54edbc7200b811e956000556/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>


int count_sheep(std::vector<bool> arr) 
{
  return std::count(arr.begin(), arr.end(), true);
}

using namespace std;           

Describe(count_sheep_method)
{
    It(array_one)
    {
        vector<bool> array1 = { true,  true,  true,  false,
                                  true,  true,  true,  true ,
                                  true,  false, true,  false,
                                  true,  false, false, true ,
                                  true,  true,  true,  true ,
                                  false, false, true,  true };
        Assert::That(count_sheep(array1), Equals(17));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}