// https://www.codewars.com/kata/5bc73331797b005d18000255

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <cmath>

std::string draw_spider(int legSize, int bodySize, char mouth, char eye)
{
    std::string output[] = {"^^",
                            "/\\/\\",
                            "/╲╱\\",
                            "╱╲╱╲"};

    std::string middle = std::string(1, mouth);

    //Add eyes
    int t = std::pow(2, bodySize) / 2;
    middle = std::string(t, eye) + middle + std::string(t, eye);

    //Add body
    middle = std::string(bodySize, '(') + middle + std::string(bodySize, ')');

    //Insert into legs
    output[legSize - 1].insert(output[legSize - 1].size() / 2, middle);

    return output[legSize - 1];
}

using namespace std;

Describe(SampleTest)
{
    It(testBasic)
    {
        doTest(1, 1, 'W', 'o', "^(oWo)^");
        
        doTest(2, 2, 'w', 'O', "/\\((OOwOO))/\\");
        
        doTest(3, 3, 'w', '0', "/╲(((0000w0000)))╱\\");
    }
    void doTest(int legSize, int bodySize, char mouth, char eye, const string &expected)
    {
        string actual = draw_spider(legSize, bodySize, mouth, eye);
        cout << "Expected : " << expected << endl
             << "Actual   : " << actual   << endl
             << endl;
        Assert::That(actual, Equals(expected));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}