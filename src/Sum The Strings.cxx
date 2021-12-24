// https://www.codewars.com/kata/5966e33c4e686b508700002d

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string sum_str(const std::string& a, const std::string& b) {
    int sum = 0;
    sum += a.empty() ? 0 : std::stoi(a);
    sum += b.empty() ? 0 : std::stoi(b);

    return std::to_string(sum);
}


// Describe(SampleTests)
// {
//     It(should_pass_sample_tests)
//     {
//         Assert::That(sum_str("4", "5"), Equals("9"), ExtraMessage(R"(Invalid result for a = "4", b = "5")"));
//         Assert::That(sum_str("34", "5"), Equals("39"), ExtraMessage(R"(Invalid result for a = "34", b = "5")"));
//         Assert::That(sum_str("42", ""), Equals("42"), ExtraMessage(R"(Invalid result for a = "42", b = "")"));
//         Assert::That(sum_str("", "42"), Equals("42"), ExtraMessage(R"(Invalid result for a = "", b = "42")"));
//     }
// };

Describe(SampleTests)
{
    It(should_pass_sample_tests)
    {
        // Assert::That(sum_str("4", "5"), Equals("9"));
        // Assert::That(sum_str("34", "5"), Equals("39"));
        Assert::That(sum_str("42", ""), Equals("42"));
        Assert::That(sum_str("", "42"), Equals("42"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}