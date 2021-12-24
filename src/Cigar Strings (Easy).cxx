// https://www.codewars.com/kata/5b64d2cd83d64828ce000039/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>

std::string is_valid(const std::string &cigar, const std::string &nuc_seq)
{
    int sum = 0;
    std::string result;
    sum += std::stoi(cigar);
    result = "True";
    if (cigar.size() > 2)
    {
        sum += std::stoi(cigar.substr(2));
        result = "False";
    }
    return (sum == nuc_seq.size()) ? result : "Invalid cigar";
}

Describe(Tests)
{
    const std::string basic_nucs = "ACTGC";
    const std::string matched_cigar = "5M";
    const std::string unmatched_cigar = "3M2S";
    const std::string invalid_cigar = "4M2S";
    const std::string m_result = is_valid(matched_cigar, basic_nucs);
    const std::string u_result = is_valid(unmatched_cigar, basic_nucs);
    const std::string i_result = is_valid(invalid_cigar, basic_nucs);

    It(Basic_Tests)
    {
        Assert::That(m_result, Equals("True"));
        Assert::That(u_result, Equals("False"));
        Assert::That(i_result, Equals("Invalid cigar"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}