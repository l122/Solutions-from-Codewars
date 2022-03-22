// https://www.codewars.com/kata/5660aa3d5e011dfd6e000063
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <algorithm>

class EightiesKids2
{
public:
    // 1
    // static std::string findSpaceship(const std::string &map)
    // {
    //   int i = map.find('X');
    //   if (i < 0)
    //     return std::string("Spaceship lost forever.");

    //   int c = 0, r = 0;
    //   //count raw
    //   int j = map.size();
    //   while(--j >= i){
    //     if (map[j] == '\n')
    //       ++r;
    //   }
    //   // count column
    //   while(--i >= 0 && map[i] != '\n'){
    //     ++c;
    //   }
      
    //   return std::string("[" + std::to_string(c) + ", " 
    //                          + std::to_string(r) + "]");
    // }

    // my best 
    static std::string findSpaceship(const std::string &map)
    {
      int i = map.find('X');
      if (i < 0)
        return std::string("Spaceship lost forever.");

      //count raw
      int r = std::count(map.begin() + i, map.end(), '\n');

      // count column
      int c = map.rfind('\n', i) < 0 ? i - 1 :  i - map.rfind('\n', i) - 1;
      
      return std::string("[" + std::to_string(c) + ", " 
                             + std::to_string(r) + "]");
    }
};

Describe(EightiesKids2Test)
{
    It(test1x1Map)
    {
        // Assert::That(EightiesKids2::findSpaceship("X"), Equals("[0, 0]"));
    }
  
    It(test2x2Map)
    {
        Assert::That(EightiesKids2::findSpaceship("..\nX."), Equals("[0, 0]"));
        Assert::That(EightiesKids2::findSpaceship("..\n.X"), Equals("[1, 0]"));
        Assert::That(EightiesKids2::findSpaceship("X.\n.."), Equals("[0, 1]"));
        Assert::That(EightiesKids2::findSpaceship(".X\n.."), Equals("[1, 1]"));
        Assert::That(EightiesKids2::findSpaceship("..\n.."), Equals("Spaceship lost forever."));
    }
  
    // Good luck!
    // Remember that space might not be square..
};

int main(int argc, const char *argv[])
{
    TestRunner::RunAllTests();
    return 0;
}