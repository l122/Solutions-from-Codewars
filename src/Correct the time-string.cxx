// https://www.codewars.com/kata/57873ab5e55533a2890000c7/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <regex>

// Initial idea

// std::string correct(std::string timeString)
// { 
//   unsigned int hour = 0, 
//                 min = 0, 
//                 sec = 0;
//   if (timeString.size() != 8) return "";
  
//   for (const auto & symbol : timeString){
//     if ((int)symbol < 48 || (int)symbol > 58)
//       return "";
//   }
  
//   sec = std::stoi(timeString.substr(6, 2));
//   min = std::stoi(timeString.substr(3, 2)) + sec / 60;
//   hour = std::stoi(timeString.substr(0, 2)) + min / 60;
  
//   timeString = "00:00:00";

//   timeString.replace(timeString.end() - std::to_string(sec % 60).size(), timeString.end(), std::to_string(sec % 60));
//   timeString.replace(timeString.end() - 3 - std::to_string(min % 60).size(), timeString.end() - 3, std::to_string(min % 60));
//   timeString.replace(timeString.end() - 6 - std::to_string(hour % 24).size(), timeString.end() - 6, std::to_string(hour % 24));

//   return timeString;
// }

//best way

std::string correct(std::string timeString)
{ 
  unsigned int hour = 0, 
                min = 0, 
                sec = 0;
  if (timeString.size() != 8) return "";
  
  std::regex mask (R"((\d\d):(\d\d):(\d\d))");
  std::smatch match;

  if (std::regex_match(timeString, match, mask)){ // if match do code
    sec = std::stoi(match[3]);
    min = std::stoi(match[2]) + sec / 60;
    hour = std::stoi(match[1]) + min / 60;

    sec %= 60;
    min %= 60;
    hour %= 24; 

    char result[9];

    sprintf(result, "%02d:%02d:%02d", hour, min, sec);
    
    return std::string(result);
  }
  else return ""; // else return emply string
}

Describe(ExampleTests)
{
    It(EmptyTest)
    {
        Assert::That(correct(""), Equals(""));
    }
    
    It(InvalidFormatTests)
    {
        Assert::That(correct("001122"), Equals(""));
        Assert::That(correct("00;11;22"), Equals(""));
        Assert::That(correct("0a:1c:22"), Equals(""));
    }
    
    It(CorrectionTests)
    {
        Assert::That(correct("09:10:01"), Equals("09:10:01"));
        Assert::That(correct("11:70:10"), Equals("12:10:10"));
        Assert::That(correct("19:99:99"), Equals("20:40:39"));
        Assert::That(correct("24:01:01"), Equals("00:01:01"));
        Assert::That(correct("52:01:01"), Equals("04:01:01"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}