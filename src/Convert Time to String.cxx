// https://www.codewars.com/kata/5502ddd734137e90af000f62

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <sstream>

std::string convertTime(int timeDiff)
{
    std::string result;
    int day = 0,
        hour = 0,
        min = 0,
        sec = 0;

    day = timeDiff / 86400;
    result = std::to_string(day) + " ";
    hour = (timeDiff % 86400) / 3600;
    result += std::to_string(hour);
    result += " ";
    min = ((timeDiff % 86400) % 3600) / 60;
    result += std::to_string(min);
    result += " ";
    sec = ((timeDiff % 86400) % 3600) % 60;
    result += std::to_string(sec);

    return result;
}

//Better way
std::string convertTime2(int timeDiff)
{
    std::ostringstream os;
    os << timeDiff / 86400 << " "
       << (timeDiff % 86400) / 3600 << " "
       << ((timeDiff % 86400) % 3600) / 60 << " "
       << ((timeDiff % 86400) % 3600) % 60;

    return os.str();
}

Describe(TimeUtilsTest )
{
    It(shouldConvertCorrectly)
    {
        Assert::That(convertTime(90061), Equals("1 1 1 1"));
        Assert::That(convertTime(-90061), Equals("-1 -1 -1 -1"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}