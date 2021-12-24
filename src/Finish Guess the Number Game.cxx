// https://www.codewars.com/kata/568018a64f35f0c613000054


#include <stdexcept>

class Guesser
{
public:
    Guesser(int number, int lives)
      : number(number), lives(lives)
    { }
    bool guess(int n)
    {
        if (lives <= 0){
            throw std::exception();
        }
        if (n == number){
            return true;
        }else{      
            --lives;
            return false;
        }
    }
private:
    int number, lives;
};

// class Guesser
// {
// public:
//     Guesser(int number, int lives)
//       : number(number), lives(lives)
//     { }
//     bool guess(int n)
//     {
//         if(lives<=0)
//         {
//           throw std::exception();
//         }
//         if(n==number)
//         {
//           return true;
//         }
//         else
//         {
//           lives--;
//           return false;
//         }
//     }
// private:
//     int number, lives;
// };

#include <igloo/igloo_alt.h>
using namespace igloo;
#include <random>

Describe(test_Guesser)
{
    It(should_return_true_for_correct_guesses)
    {
        Guesser guesser(10, 2);
        Assert::That(guesser.guess(10), Equals(true));
    };
    It(should_allow_multiple_correct_guesses)
    {
        Guesser guesser(10, 2);
        for (int i = 0; i < 10; ++i)
            Assert::That(guesser.guess(10), Equals(true));
    };
    It(should_return_false_for_incorrect_guesses)
    {
        Guesser guesser(10, 2);
        Assert::That(guesser.guess(1), Equals(false));
    };
    It(should_throw_if_lives_ran_out)
    {
        Guesser guesser(10, 2);
        guesser.guess(1);
        guesser.guess(2);
        AssertThrows(std::exception, guesser.guess(10));
    };
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}