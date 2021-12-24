// https://www.codewars.com/kata/586a1af1c66d18ad81000134

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <cctype>
#include <array>
#include <algorithm>
#include <map>

// 1ST VERSION ******************************************************************
// std::map<std::string, int> monthMap = {
//     {"JAN", 1}, {"FEB", 2}, {"MAR", 3}, {"APR", 4}, {"MAY", 5}, {"JUN", 6}, {"JUL", 7}, {"AUG", 8}, {"SEP", 9}, {"OCT", 10}, {"NOV", 11}, {"DEC", 12}};

// std::string driver(const std::array<std::string, 5> &data)
// {
//     std::string firstName = data[0],
//                 middleName = data[1],
//                 surname = data[2],
//                 birthdate = data[3],
//                 sex = data[4],
//                 sMonth = birthdate.substr(3, 3);

//     std::string out(surname.size(), ' ');
//     // 1-5 - Surname
//     std::transform(surname.begin(), surname.end(), out.begin(), toupper);
//     out = out.size() < 5 ? out + std::string(5 - out.size(), '9') : out.substr(0, 5);
//     // 6 - decade
//     out += birthdate.substr(birthdate.size() - 2, 1);
//     // 7-8 - month
//     std::transform(sMonth.begin(), sMonth.end(), sMonth.begin(), toupper);
//     int iMonth = monthMap[sMonth];
//     if (sex == "F")
//         iMonth += 50;
//     if (iMonth < 10)
//         out = out + "0" + std::to_string(iMonth);
//     else
//         out += std::to_string(iMonth);
//     // 9-10 - day
//     out += birthdate.substr(0, 2);
//     // 11 - digit from the year of birth
//     out += birthdate.substr(birthdate.size() - 1, 1);
//     // 12-13 the initials of first and middle names
//     out += std::toupper(firstName[0]);                                        // initial of name
//     out += (middleName.size() > 0) ? char(std::toupper(middleName[0])) : '9'; //initial of middle name
//     // 14 - Arbitrary digit
//     out += "9";
//     // 15-16 - the computer check digits
//     out += "AA";

//     return out; // Code here
// }
// END OF 1ST VERSION **********************************************************************************

// REVISED VERSION *************************************************************************************
std::map<std::string, std::string> months = {
    {"JAN", "01"}, {"FEB", "02"}, {"MAR", "03"}, {"APR", "04"}, {"MAY", "05"}, {"JUN", "06"}, {"JUL", "07"}, {"AUG", "08"}, {"SEP", "09"}, {"OCT", "10"}, {"NOV", "11"}, {"DEC", "12"}};

std::string driver(const std::array<std::string, 5> &data)
{
    std::string out, // returned data
        firstName = data[0],
        middleName = data[1],
        surname = data[2],
        birthdate = data[3],
        sex = data[4],
        month = birthdate.substr(3, 3);

    // 1-5 - Surname
    out = (surname.size() < 5) ? surname + std::string(5 - surname.size(), '9') : surname.substr(0, 5);
    // 6 - decade
    out += birthdate.substr(birthdate.size() - 2, 1);
    // 7-8 - month
    std::transform(month.begin(), month.end(), month.begin(), toupper);
    month = months[month];
    if (sex == "F")
        month[0] += 5;
    out += month;
    // 9-10 - day
    out += birthdate.substr(0, 2);
    // 11 - digit from the year of birth
    out += birthdate.substr(birthdate.size() - 1, 1);
    // 12-13 the initials of first and middle names
    out += firstName[0];                                  // initial of first name
    out += (middleName.size() > 0) ? middleName[0] : '9'; // initial of middle name
    // 14 - Arbitrary digit
    out += "9";
    // 15-16 - the computer check digits
    out += "AA";

    std::transform(out.begin(), out.end(), out.begin(), toupper);

    return out;
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