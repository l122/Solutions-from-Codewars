// From Codewars.com
// https://www.codewars.com/kata/5264d2b162488dc400000001/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

std::string spinWords2(const std::string &str)
{
    using namespace std;

    stringstream stream(str);
    string buff;
    string result;

        while (stream >> buff)
    {
        if (buff.size() >= 5)
            reverse(buff.begin(), buff.end());

        result += buff + " ";
    }

    result.pop_back();

    return result;
} // spinWords

std::string spinWords(const std::string &str)
{
    using namespace std;
    string result = "";

    int indx = 0;
    int i = 0;
    while (indx < str.length())
    {
        i = str.substr(indx).find(' ');
        if (i > -1)
        {
            if (i < 5)
            {
                result += str.substr(indx, i + 1);
            }
            else
            {
                string temp;
                for (int j = i - 1; j >= 0; j--)
                {
                    result += str.substr(indx + j, 1);
                }
                result += str.substr(indx + i, 1);
            }
            indx += i + 1;
        }
        else
        {
            if (str.substr(indx).length() < 5)
            {
                result += str.substr(indx);
            }
            else
            {
                string temp;
                for (int j = str.substr(indx).length() - 1; j >= 0; j--)
                {
                    result += str.substr(indx + j, 1);
                }
            }
            indx += str.substr(indx).length();
        }
    }

    return result;
} // spinWords

// TODO: Replace examples and use TDD development by writing your own tests

Describe(Sample_Tests)
{
    It(Single_Word)
    {
        Assert::That(spinWords("Welcome"), Equals("emocleW"));
        Assert::That(spinWords("to"), Equals("to"));
        Assert::That(spinWords("CodeWars"), Equals("sraWedoC"));
    }
    
    It(Mulitple_Words)
    {
      Assert::That(spinWords("Hey fellow warriors"), Equals("Hey wollef sroirraw"));
      Assert::That(spinWords("Burgers are my favorite fruit"), Equals("sregruB are my etirovaf tiurf"));
      Assert::That(spinWords("Pizza is the best vegetable"), Equals("azziP is the best elbategev"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}