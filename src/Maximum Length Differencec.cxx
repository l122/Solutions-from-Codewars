// https://www.codewars.com/kata/5663f5305102699bad000056
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

class MaxDiffLength
{
public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2){
        if (a1.empty() || a2.empty())
            return -1;
            
        int ret = 0;
        for (const auto & a1 : a1){
            for (const auto & a2 : a2){
                int temp = a1.size() - a2.size();
                ret = std::max(ret, std::abs(temp));
            }
        }
        return ret;
    }
};


void testequal(int ans, int sol) {
    Assert::That(ans, Equals(sol));
}
void dotest(std::vector<std::string> &a1, std::vector<std::string> &a2, int expected)
{
    testequal(MaxDiffLength::mxdiflg(a1, a2), expected);
}
Describe(mxdiflg_Tests)
{
    It(Fixed__Tests)
    {
        std::vector<std::string> s1 = {"hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"};
        std::vector<std::string> s2 = {"cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"};
        dotest(s1, s2, 13);
        s1 = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
        s2 = {"bbbaaayddqbbrrrv"};
        dotest(s1, s2, 10);
    }
};



int main(int argc, const char *argv[])
{
    TestRunner::RunAllTests();
    return 0;
}