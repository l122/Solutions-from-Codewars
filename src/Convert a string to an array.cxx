// https://www.codewars.com/kata/57e76bc428d6fbc2d500036d
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <string>
#include <sstream>

// My solution (some case aren't working)
std::vector<std::string> string_to_array(const std::string& s) {
  std::istringstream ss(s);
  std::vector<std::string> out;
  std::string temp = "";
  while (ss >> temp)
  {
      out.push_back(temp);
  }
  if (out.size() == 0)
    out.push_back("");
  return out;
}

// Other solution (working)
// std::vector<std::string> string_to_array(const std::string& str) {
//     if(str.empty())
//       return std::vector<std::string>{""};
//     std::vector<std::string> ans;
//     int i = 0;
//     while(i <= str.size()){
//       std::string s;
//       while(str[i] != ' ' && i != str.size()){
//         s += str[i];
//         i++;
//       }      
//       ans.push_back(s);
//       i++;
//     }
//   return ans;
// }


Describe(Fixed_tests) {
  It(Basic_cases) {
    Assert::That(string_to_array("some value"), 
                 Equals(std::vector<std::string>{"some", "value"}));
    Assert::That(string_to_array("Robin Singh"), 
                 Equals(std::vector<std::string>{"Robin", "Singh"}));
    Assert::That(string_to_array("Codewars"), 
                 Equals(std::vector<std::string>{"Codewars"}));
    Assert::That(string_to_array("I love arrays"), 
                 Equals(std::vector<std::string>{"I", "love", "arrays"}));
    Assert::That(string_to_array("1 2 3"), 
                 Equals(std::vector<std::string>{"1", "2", "3"}));
  }
  It(Empty_string) {
    Assert::That(string_to_array(""), 
                 Equals(std::vector<std::string>{""}));
  }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}