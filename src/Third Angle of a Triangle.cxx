// https://www.codewars.com/kata/5a023c426975981341000014

#include <igloo/igloo_alt.h>
using namespace igloo;

class Triangle {
public:
  static int otherAngle(int a, int b){return 180 - a - b;}
};

Describe(sampleTests) {
	It(shouldBe) {
		Assert::That(Triangle::otherAngle(30, 60), Equals(90));
		Assert::That(Triangle::otherAngle(60, 60), Equals(60));
		Assert::That(Triangle::otherAngle(43, 78), Equals(59));
		Assert::That(Triangle::otherAngle(10, 20), Equals(150));
	}
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}