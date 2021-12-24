// https://www.codewars.com/kata/5a1e6323ffe75f71ae000026

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_turing_equation(string s)
{
    string first, second, sum;
    size_t c = 0;
    size_t i = 0;
    for (const auto &ch : s)
    {
        switch (ch)
        {
        case '+':
            first = s.substr(i, c);
            i = i + c + 1;
            c = 0;
            break;
        case '=':
            second = s.substr(i, c);
            sum = s.substr(i + c + 1, s.size() - 1);
            break;
        default:
            ++c;
        }
    }

    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());
    reverse(sum.begin(), sum.end());

    return (stoll(first) + stoll(second)) == stoll(sum);
}

// TODO: Replace examples and use TDD development by writing your own tests

Describe(Basic_Tests)
{
    It(It_should_work_for_basic_tests)
    {    
        vector<pair<string, bool>> basic_tests{
			    {"73+42=16",true },
			    {"5+8=13",false},
			    {"10+20=30",true},
			    {"0001000+000200=00030",true},
			    {"1234+5=1239",false},
			    {"1+0=0",false},
			    {"7000+8000=51",true},
			    {"0+0=0",true}
		};
        for(pair<string, bool> p: basic_tests)
          Assert::That(is_turing_equation(p.first), Equals(p.second));    
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}