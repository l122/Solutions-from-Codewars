// https://www.codewars.com/kata/57f037927b45ef77b3000260

#include <igloo/igloo_alt.h>
using namespace igloo;

class Person
{
    public:
        Person(int x, int y, int z)
            : m_x(x), m_y(y), m_z(z)
        {
        }
        
        void location(int &x, int &y, int &z)
        {
            x = m_x;
            y = m_y;
            z = m_z;
        }
        
    private:
        int m_x;
        int m_y;
        int m_z;
};

Describe(person_test)
{
    It(should_return_location)
    {
        Person* person = new Person(1, 2, 3);
        int x = 0, y = 0, z = 0;
        person->location(x, y, z);
        Assert::That(x, Equals(1));
        Assert::That(y, Equals(2));
        Assert::That(z, Equals(3));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}