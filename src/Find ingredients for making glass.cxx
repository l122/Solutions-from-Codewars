// https://www.codewars.com/kata/5aea1b7fd2ee276c4b000011

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::string createIngredients(double sand = 60, double seaweed = 180, double chalk = 5)
{

    //Check for negative inputs
    if (sand < 0 || seaweed < 0 || chalk < 0)
    {
        return "";
    }

    //Define an index for incrementing all values
    double index = 1;
    if (sand > 0)
    {
        // index = sand / 60;
        seaweed = sand * 3;
        chalk = sand / 12;
    }
    else if (seaweed > 0)
    {
        // index = seaweed / 180;
        sand = seaweed / 3;
        chalk = seaweed / 36;
    }
    else if (chalk > 0)
    {
        // index = chalk / 5;
        sand = chalk * 12;
        seaweed = chalk * 36;
        // sand *= index;
        // seaweed *= index;
    }

    std::string result;
    std::stringstream ss;

    ss << "["
       << std::fixed << std::setprecision(2) << sand << ";"
       << std::fixed << std::setprecision(2) << seaweed << ";"
       << std::fixed << std::setprecision(2) << chalk << "]";

    return ss.str();
}
Describe(sample_tests)
{ 
 It(tests) {
	 Assert::That(createIngredients(), Equals("[60.00;180.00;5.00]"));
 	 Assert::That(createIngredients(60), Equals("[60.00;180.00;5.00]"));
	 Assert::That(createIngredients(0,180), Equals("[60.00;180.00;5.00]"));
	 Assert::That(createIngredients(100) , Equals("[100.00;300.00;8.33]"));
   }
};
int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}