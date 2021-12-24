// https://www.codewars.com/kata/5b2be37991c7460d17000009

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string communicationModule(std::string packet)
{
    std::string result;
    std::string instr = packet.substr(4, 4);
    std::string sData1;
    int data1 = std::stoi(packet.substr(8, 4));
    int data2 = std::stoi(packet.substr(12, 4));
    if (instr == "0F12") // Addition
        data1 += data2;
    else if (instr == "B7A2") // Sugstruction
        data1 -= data2;
    else if (instr == "C3D9") // Multiplication
        data1 *= data2;

    if (data1 < 0)
        sData1 = "0000";
    else if (data1 > 9999)
        sData1 = "9999";
    else
    {
        std::string temp = std::to_string(data1);
        sData1 = "0000" + temp;
        sData1.erase(0, temp.size());
    }

    result = packet.substr(0, 4) + "FFFF" + sData1 + "0000" + packet.substr(16, 4);
    return result;
}

Describe(communication_tests)
{
  It(sample_test_cases)
  {
    // Addition
    Assert::That(communicationModule("H1H10F1200120008F4F4"), Equals("H1H1FFFF00200000F4F4"));
    
    // Subtraction
    Assert::That(communicationModule("X7X7B7A201400058L0L0"), Equals("X7X7FFFF00820000L0L0"));
    
    // Multiplication
    Assert::That(communicationModule("R5R5C3D900120008K4K4"), Equals("R5R5FFFF00960000K4K4"));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}