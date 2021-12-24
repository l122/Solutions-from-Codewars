// https://www.codewars.com/kata/5797d1a9c38ec2de1f00017b

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <cmath>
std::string watchPyramidFromTheSide(std::string characters)
{
    if (characters.empty())
        return characters;

    std::string out = "";
    size_t s = characters.size();
    char ch;
    for (size_t i = 1; i <= s; ++i)
    {
        ch = characters[s - i];
        out += std::string(s - i, ' ');
        out += std::string(i, ch) + std::string(i - 1, ch);
        out += std::string(s - i, ' ');
        out.push_back('\n');
    }
    out.pop_back();
    return out;
}

std::string watchPyramidFromAbove(std::string characters)
{
    if (characters.empty())
        return characters;

    size_t s = characters.size();
    char ch;
    std::vector<std::string> lines;
    for (size_t i = 0; i < s; ++i)
    {
        std::string temp = "";
        size_t j = 0;
        for (; j <= i; ++j)
        {
            ch = characters[j];
            temp.push_back(ch);
        }
        size_t x = s - j;
        temp += std::string(x, ch);

        lines.push_back(temp);
        temp.pop_back();
        std::reverse(temp.begin(), temp.end());
        lines[i] += temp;
        lines[i].push_back('\n');
    }
    std::string out = "";

    for (const auto &l : lines){
        out += l;
    }
    for (auto i = lines.size()-1; i-- > 0; ){
        out+= lines[i];
    }

    out.pop_back();
    return out;
}

int countVisibleCharactersOfThePyramid(std::string characters)
{   
    if (characters.empty())
        return -1;
    int out = pow((characters.size() + characters.size()-1), 2); 

    return out;
}

int countAllCharactersOfThePyramid(std::string characters)
{
    if (characters.empty())
        return -1;

    int out = 0;
    for (int i = 1; i <= characters.size(); ++i){
        out += countVisibleCharactersOfThePyramid(characters.substr(0, i));
    }

    return out;
}

Describe(ExampleTests)
{
    It(_0_Test1)
    {
        std::string testCharacters = "*#";
        
        // Test FromSide
        std::string expectedWatchFromSide = " # \n***";
        std::string actualWatchFromSide = watchPyramidFromTheSide(testCharacters);
        
        Assert::That("\n" + actualWatchFromSide, Is().EqualTo("\n" + expectedWatchFromSide));
        
        // Test FromAbove
        std::string expectedWatchFromAbove = "***\n*#*\n***";
        std::string actualWatchFromAbove = watchPyramidFromAbove(testCharacters);
        
        Assert::That("\n" + actualWatchFromAbove, Is().EqualTo("\n" + expectedWatchFromAbove));

        // Test CountVisibleCharacters
        Assert::That(countVisibleCharactersOfThePyramid(testCharacters), Is().EqualTo(9));
        
        // Test CountAllCharacters
        Assert::That(countAllCharactersOfThePyramid(testCharacters), Is().EqualTo(10));
    }
    
    It(_1_Test2)
    {
        std::string testCharacters = "abc";
        
        // Test FromSide
        std::string expectedWatchFromSide = "  c  \n bbb \naaaaa";
        std::string actualWatchFromSide = watchPyramidFromTheSide(testCharacters);
        
        Assert::That("\n" + actualWatchFromSide, Is().EqualTo("\n" + expectedWatchFromSide));
        
        //Test FromAbove
        std::string expectedWatchFromAbove = "aaaaa\nabbba\nabcba\nabbba\naaaaa";
        std::string actualWatchFromAbove = watchPyramidFromAbove(testCharacters);
        
        Assert::That("\n" + actualWatchFromAbove, Is().EqualTo("\n" + expectedWatchFromAbove));
        
        // Test CountVisibleCharacters
        Assert::That(countVisibleCharactersOfThePyramid(testCharacters), Is().EqualTo(25));
        
        // Test CountAllCharacters
        Assert::That(countAllCharactersOfThePyramid(testCharacters), Is().EqualTo(35));
    } 
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}