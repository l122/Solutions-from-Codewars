// https://www.codewars.com/kata/57f24e6a18e9fad8eb000296

#include <igloo/igloo_alt.h>
using namespace igloo;

std::string how_much_i_love_you(int nb_petals) {
  std::string answer [] = {"not at all", "I love you", "a little", "a lot", "passionately", "madly"};
  return answer[nb_petals % 6];
}

Describe(decode)
{
    It(basic_tests)
    {
        Assert::That(how_much_i_love_you(7), Equals("I love you"));
        Assert::That(how_much_i_love_you(3), Equals("a lot"));
        Assert::That(how_much_i_love_you(6), Equals("not at all"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}