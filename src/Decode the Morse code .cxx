// https://www.codewars.com/kata/54b724efac3d5402db00065e/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <map>

std::string decodeMorse(std::string morseCode)
{
    std::map<std::string, std::string> codesMap = {
        {".-", "A"},
        {"-...", "B"},
        {"-.-.", "C"},
        {"-..", "D"},
        {".", "E"},
        {"..-.", "F"},
        {"--.", "G"},
        {"....", "H"},
        {"..", "I"},
        {".---", "J"},
        {"-.-", "K"},
        {".-..", "L"},
        {"--", "M"},
        {"-.", "N"},
        {"---", "O"},
        {".--.", "P"},
        {"--.-", "Q"},
        {".-.", "R"},
        {"...", "S"},
        {"-", "T"},
        {"..-", "U"},
        {"...-", "V"},
        {".--", "W"},
        {"-..-", "X"},
        {"-.--", "Y"},
        {"--..", "Z"},
        {".----", "1"},
        {"..---", "2"},
        {"...--", "3"},
        {"....-", "4"},
        {".....", "5"},
        {"-....", "6"},
        {"--...", "7"},
        {"---..", "8"},
        {"----.", "9"},
        {"-----", "0"},
        {" ", " "},
        {".-.-.-", "."},
        {"-..-", ","},
        {"..-..", "?"},
        {".-.", "'"},
        {"-.-.-", "!"},
        {"...---...", "SOS"}};
    std::string decoded;

    size_t prev = 0,
           next = prev;
    do
    {
        next = morseCode.substr(prev, morseCode.length() - prev).find(" ");
        if (next != std::string::npos)
        {
            if (next == 0)
                next++;
            decoded += codesMap[morseCode.substr(prev, next)];
            prev += next + 1;
        }
        else
        {
            decoded += codesMap[morseCode.substr(prev, morseCode.length())];
        }
    } while (next != std::string::npos);

    return decoded;
}

Describe(Example_from_description)
{
    It(should_do_something)
    {
        Assert::That(decodeMorse(".... . -.--   .--- ..- -.. ."), Equals("HEY JUDE"));
    }
};
Describe(Your_own_tests)
{
  // Add more tests here
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}