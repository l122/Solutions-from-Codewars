// https://www.codewars.com/kata/5680781b6b7c2be860000036
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <string>

std::vector<int> vowelIndices(const std::string& word)
{
    std::string vowels = "aeiouyAEIOUY";
    std::vector<int> res;
    for (auto i = 0; i < word.size(); ++i){
        if (vowels.find(word[i]) != std::string::npos){
            res.push_back(i+1);
        }
    }
    return res;
}


Describe(vowelIndicesTest)
{
    It(SimpleTests1)
    {
        std::vector<int> res { 2, 4 };
        Assert::That(vowelIndices("super"), Equals(res));
    }

    It(SimpleTests2)
    {
        std::vector<int> res;
        Assert::That(vowelIndices("Mmmm"), Equals(res));
    }

    It(SimpleTests3)
    {
        std::vector<int> res { 1, 5 };
        Assert::That(vowelIndices("Apple"), Equals(res));
    }

    It(SimpleTests4)
    {
        std::vector<int> res { 1,2,4,6 };
        Assert::That(vowelIndices("YoMama"), Equals(res));
    }
};



int main(int argc, const char *argv[])
{
    TestRunner::RunAllTests();
    return 0;
}