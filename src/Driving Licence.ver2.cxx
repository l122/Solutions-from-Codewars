// https://www.codewars.com/kata/586a1af1c66d18ad81000134

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <iostream>
#include <algorithm>
#include <array>
#include <sstream>
#include <map>
std::map<std::string, std::string> months{
    {"jan", "01"},
    {"feb", "02"},
    {"mar", "03"},
    {"apr", "04"},
    {"may", "05"},
    {"jun", "06"},
    {"jul", "07"},
    {"aug", "08"},
    {"sep", "09"},
    {"oct", "10"},
    {"nov", "11"},
    {"dec", "12"}};
std::string driver(const std::array<std::string, 5> &data)
{
    std::string result = "99999######999AA";
    std::stringstream data_sstream(data[3]);

    std::string str_day;
    std::string str_month;
    std::string str_year;

    std::getline(data_sstream, str_day, '-');
    std::getline(data_sstream, str_month, '-');
    std::getline(data_sstream, str_year, '-');

    std::transform(str_month.begin(), str_month.end(), str_month.begin(), ::tolower);
    str_month = months[str_month.substr(0, 3)];

    if (data[4] == "F")
    {
        str_month[0] = str_month[0] + 5;
    }
    result.replace(0, data[2].size(), data[2]);
    auto temp1 = data[3][data[3].size() - 2];
    auto temp2 = data[3][data[3].size() - 2] - '0';
    result.replace(5, 1, std::to_string(data[3][data[3].size() - 2] - '0'));
    result.replace(6, 2, str_month);
    result.replace(8, 2, str_day);
    result.replace(10, 1, std::to_string(str_year[str_year.size() - 1] - '0'));
    result.replace(11, 1, data[0].substr(0, 1));

    if (data[1] != "")
        result.replace(12, 1, data[1].substr(0, 1));

    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result; // Code here
}

#include <array>

using namespace std;

Describe(sample_tests)
{
    It(basic_tests)
    {
        Assert::That(driver({"John",    "James",  "Smith", "01-Jan-2000",       "M"}),
                     Equals("SMITH001010JJ9AA"));
        Assert::That(driver({"Johanna", "",       "Gibbs", "13-Dec-1981",       "F"}),
                     Equals("GIBBS862131J99AA"));
        Assert::That(driver({"Andrew",  "Robert", "Lee",   "02-September-1981", "M"}),
                     Equals("LEE99809021AR9AA"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}