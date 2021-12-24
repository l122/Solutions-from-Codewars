// https://www.codewars.com/kata/57a72cb872292dc43100000c

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <vector>

class Route
{
public:
    std::string in;

    std::string out;

    Route(std::string in, std::string out)
    {
        this->in = in;
        this->out = out;
    }

    ~Route(){};
};

std::string itinerary(std::vector<Route> travel)
{
    std::string result = "";
    std::string temp = "";

    int i = 1;
    for (auto const &rout : travel)
    {
        std::cout << i << ") ";
        std::cout << "in: " << rout.in << std::endl;
        std::cout << "   out: " << rout.out << std::endl;
        ++i;
        if (rout.in != temp)
        {
            result += rout.in;
            result += "-";
        }
        result += rout.out;
        result += "-";
        temp = rout.out;
    }

    result.pop_back();
    return result;
}

Describe(ExampleTests)
{
    It(SimpleTest)
    {
        std::vector<Route> travel =
        {
            Route("TRN", "FCO")
        };
        
        std::string expected = "TRN-FCO";
        std::string actual = itinerary(travel);
        
        Assert::That(actual, Is().EqualTo(expected));
    }
    
    It(MultipleTest)
    {
        std::vector<Route> travel =
        {
            Route("TRN", "FCO"),
            Route("CIA", "JFK")
        };
        
        std::string expected = "TRN-FCO-CIA-JFK";
        std::string actual = itinerary(travel);
        
        Assert::That(actual, Is().EqualTo(expected));
    }
    
    It(SameAirportsAreSkippedTest)
    {
        std::vector<Route> travel =
        {
            Route("TRN", "FCO"),
            Route("FCO", "JFK")
        };
        
        std::string expected = "TRN-FCO-JFK";
        std::string actual = itinerary(travel);
        
        Assert::That(actual, Is().EqualTo(expected));
    }
    
    It(RoundTripAreConservedTest)
    {
        std::vector<Route> travel =
        {
            Route("TRN", "FCO"),
            Route("CIA", "TRN")
        };
        
        std::string expected = "TRN-FCO-CIA-TRN";
        std::string actual = itinerary(travel);
        
        Assert::That(actual, Is().EqualTo(expected));
    }

    It(RoundTripAreConservedWithSharedAirportsTest)
    {
        std::vector<Route> travel =
        {
            Route("TRN", "FCO"),
            Route("FCO", "TRN")
        };
        
        std::string expected = "TRN-FCO-TRN";
        std::string actual = itinerary(travel);
        
        Assert::That(actual, Is().EqualTo(expected));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}