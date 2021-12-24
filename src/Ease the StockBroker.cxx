// https://www.codewars.com/kata/54de3257f565801d96001200

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <sstream>

class OrdersSummary
{
public:
    static std::string balanceStatements(const std::string &lst)
    {

        std::string badlyFormedOrders = "";

        std::string orderName = "";
        std::string quantity = "";
        std::string price = "";
        std::string status = "";
        double boughtAmount = 0;
        double soldAmount = 0;
        int quantityOfBadOrders = 0;
        std::string output = "Buy: 0 Sell: 0";

        std::stringstream ss(lst);
        while (ss >> orderName)
        {
            ss >> quantity;
            ss >> price;
            ss >> status;
            status = status.substr(0, 1);
            if (price.find('.') == std::string::npos)
            {
                badlyFormedOrders = badlyFormedOrders + orderName + " " + quantity + " " + price + " " + status + " ;";
                ++quantityOfBadOrders;
            }
            else
            {
                if (status == "B")
                {
                    boughtAmount += std::stoi(quantity) * std::stod(price);
                }
                else
                {
                    soldAmount += std::stoi(quantity) * std::stod(price);
                }
            }
            output = "Buy: " + std::to_string((int)(boughtAmount + 0.5)) + " Sell: " + std::to_string((int)(soldAmount + 0.5));
        }

        if (badlyFormedOrders != "")
            output = output + "; Badly formed " + std::to_string(quantityOfBadOrders) + ": " + badlyFormedOrders;

        return output;
    }
};

#include <string>

void testequal(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}
static void dotest(const std::string &lst, std::string &expected)
{
    testequal(OrdersSummary::balanceStatements(lst), expected);
}
Describe(balanceStatements_Tests)
{
    It(Fixed_Tests)
    {
      std::string l = "GOOG 300 542.0 B, AAPL 50 145.0 B, CSCO 250.0 29 B, GOOG 200 580.0 S";
      std::string sol = "Buy: 169850 Sell: 116000; Badly formed 1: CSCO 250.0 29 B ;";
      dotest(l, sol);
      
      l = "GOOG 90 160.45 B, JPMC 67 12.8 S, MYSPACE 24.0 210 B, CITI 50 450 B, CSCO 100 55.5 S";
      sol = "Buy: 14440 Sell: 6408; Badly formed 2: MYSPACE 24.0 210 B ;CITI 50 450 B ;";
      dotest(l, sol);
      
      l = "ZNGA 1300 2.66 B, CLH15.NYM 50 56.32 B, OWW 1000 11.623 B, OGG 20 580.1 B";
      sol = "Buy: 29499 Sell: 0";
      dotest(l, sol);
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}