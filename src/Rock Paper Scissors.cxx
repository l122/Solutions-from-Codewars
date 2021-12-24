// https://www.codewars.com/kata/5672a98bdbdd995fad00000f
#include <iostream>

#include <string>

std::string rps(const std::string& p1, const std::string& p2)
{
    if (p1 == p2)
        return "Draw!";

    if ((p1 == "scissors" && p2 == "paper") ||
        (p1 == "paper" && p2 == "rock") ||
        (p1 == "rock" && p2 == "scissors"))
        return "Player 1 won!";
    
    return "Player 2 won!";  
}

#include <igloo/igloo_alt.h>
using namespace igloo;

Describe(test_rpg)
{
    It(should_pass_some_example_tests)
    {
        Assert::That(rps("rock", "scissors"), Equals("Player 1 won!"));
        Assert::That(rps("rock", "paper"), Equals("Player 2 won!"));
        Assert::That(rps("rock", "rock"), Equals("Draw!"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}