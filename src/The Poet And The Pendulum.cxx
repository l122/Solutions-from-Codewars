// https://www.codewars.com/kata/5bd776533a7e2720c40000e5

#include <vector>
#include <algorithm>

using namespace std;

// My first solution
// vector <int> Pendulum (vector <int> values)
// {
//   int n = values.size();
//   if (n < 3)
//     return values;

//   vector<int> ret(n);
//   std::sort(values.begin(), values.end());
//   int mid = (n-1) / 2;
//   ret[mid] = values[0];
//   int l = mid - 1;
//   int r = mid + 1;
//   for (int i = 1; i < n; i+=2){
//     if (r < n){
//       ret[r] = values[i];
//       ++r;
//     }
//     if (l >= 0){
//       ret[l] = values[i+1];
//       --l;
//     }
//   }
//   return ret; 
// }

// Best solution
#include <deque>
vector <int> Pendulum (vector <int> values)
{
  sort(values.begin(), values.end());

  deque<int> ret;
  for (int i = 0; i < values.size(); ++i){
    (i % 2) ? ret.push_back(values[i]) : ret.push_front(values[i]);
  }
  return vector<int>(ret.begin(), ret.end()); 
}

#include <igloo/igloo_alt.h>
using namespace igloo;


using vec = vector <int> ;

Describe(The_Poet_And_The_Pendulum)
{
    It(Check_Short_length_Positives)
    {
        Assert::That(Pendulum(vec{4,10,9}), Equals(vec{10,4,9}));
          Assert::That(Pendulum(vec{8,7,10,3}), Equals(vec{8,3,7,10}));
            Assert::That(Pendulum(vec{6,6,8,5,10}), Equals(vec{10,6,5,6,8}));
              Assert::That(Pendulum(vec{9,4,6,4,10,5}), Equals(vec{9,5,4,4,6,10}));
                Assert::That(Pendulum(vec{4,6,8,7,5}), Equals(vec{8,6,4,5,7}));
                  Assert::That(Pendulum(vec{10,5,6,10}), Equals(vec{10,5,6,10}));
                    Assert::That(Pendulum(vec{11,12,12}), Equals(vec{12,11,12}));
    }
    It(Check_Medium_length_Positives)
    {
        Assert::That(Pendulum(vec{27,27,19,21,22,28,24}), Equals(vec{28,27,22,19,21,24,27}));
          Assert::That(Pendulum(vec{20,19,25,16,19,30,18,24}), Equals(vec{25,20,19,16,18,19,24,30}));
            Assert::That(Pendulum(vec{22,26,21,27,24,21,15,26,25}), Equals(vec{27,26,24,21,15,21,22,25,26}));
              Assert::That(Pendulum(vec{19,30,16,19,28,26,28,17,21,17}), Equals(vec{28,26,19,17,16,17,19,21,28,30}));
                Assert::That(Pendulum(vec{27,28,26,28,24,22,18,16,15,24}), Equals(vec{28,26,24,18,15,16,22,24,27,28}));
                  Assert::That(Pendulum(vec{17,26,15,26,26,20,16,18,15}), Equals(vec{26,26,18,16,15,15,17,20,26}));
                    Assert::That(Pendulum(vec{22,21,19,27,18,15,24,24}), Equals(vec{24,22,19,15,18,21,24,27}));
    }
    It(Check_lengthy_Positives)
    {
        Assert::That(Pendulum(vec{33,38,38,36,43,48,32,40,47,50,33}), Equals(vec{50,47,40,38,33,32,33,36,38,43,48}));
          Assert::That(Pendulum(vec{49,40,41,41,39,43,40,46,30,47,46,40}), Equals(vec{47,46,41,40,40,30,39,40,41,43,46,49}));
            Assert::That(Pendulum(vec{48,41,38,35,50,46,38,42,37,49,44,32,37}), Equals(vec{50,48,44,41,38,37,32,35,37,38,42,46,49}));
              Assert::That(Pendulum(vec{49,30,39,30,40,44,43,48,47,50,42,48,33}), Equals(vec{50,48,47,43,40,33,30,30,39,42,44,48,49}));
                Assert::That(Pendulum(vec{48,43,35,47,39,38,38,46,49,32,42}), Equals(vec{49,47,43,39,38,32,35,38,42,46,48}));
    }
    It(Check_Short_length_Negatives)
    {
        Assert::That(Pendulum(vec{-9,-2,-10,-6}), Equals(vec{-6,-10,-9,-2}));
          Assert::That(Pendulum(vec{-3,-6,-7}), Equals(vec{-3,-7,-6}));
            Assert::That(Pendulum(vec{-7,-8,-2,-3,-4}), Equals(vec{-2,-4,-8,-7,-3}));
              Assert::That(Pendulum(vec{-8,-8,-9,-10,-10,-3}), Equals(vec{-8,-9,-10,-10,-8,-3}));
                Assert::That(Pendulum(vec{-7,-10,-1,-10,-8}), Equals(vec{-1,-8,-10,-10,-7}));
                  Assert::That(Pendulum(vec{-6,-2,-5}), Equals(vec{-2,-6,-5}));
    }
    It(Check_Medium_length_Negatives)
    {
        Assert::That(Pendulum(vec{-2,-11,-6,-11,-4,-3,-5}), Equals(vec{-2,-4,-6,-11,-11,-5,-3}));
          Assert::That(Pendulum(vec{-19,-9,-5,-6,-15,-16,-5,-12}), Equals(vec{-5,-9,-15,-19,-16,-12,-6,-5}));
            Assert::That(Pendulum(vec{-18,-2,-11,-10,-6,-7,-7,-12,-16}), Equals(vec{-2,-7,-10,-12,-18,-16,-11,-7,-6}));
              Assert::That(Pendulum(vec{-10,-10,-12,-13,-5,-10,-4,-17,-5,-12}), Equals(vec{-5,-10,-10,-12,-17,-13,-12,-10,-5,-4}));
    }
    It(Check_lengthy_Negatives)
    {
        Assert::That(Pendulum(vec{-33,-21,-6,-29,-24,-5,-50,-42,-43,-17,-17}), Equals(vec{-5,-17,-21,-29,-42,-50,-43,-33,-24,-17,-6}));
          Assert::That(Pendulum(vec{-4,-50,-32,-23,-47,-44,-43,-24,-29,-44,-20,-35}), Equals(vec{-20,-24,-32,-43,-44,-50,-47,-44,-35,-29,-23,-4}));
            Assert::That(Pendulum(vec{-36,-38,-44,-47,-41,-27,-10,-30,-22,-11,-23,-50,-23}), Equals(vec{-10,-22,-23,-30,-38,-44,-50,-47,-41,-36,-27,-23,-11}));
    }
    It(Check_Mixture_Of_Positives_And_Negatives)
    {
        Assert::That(Pendulum(vec{-15,8,11}), Equals(vec{11,-15,8}));
          Assert::That(Pendulum(vec{8,-1,-1,-10}), Equals(vec{-1,-10,-1,8}));
            Assert::That(Pendulum(vec{-8,15,8,-3,-11}), Equals(vec{15,-3,-11,-8,8}));
              Assert::That(Pendulum(vec{15,17,3,-20,-1,3}), Equals(vec{15,3,-20,-1,3,17}));
                Assert::That(Pendulum(vec{-8,-13,-19,-8,7,15,-10}), Equals(vec{15,-8,-10,-19,-13,-8,7}));
                  Assert::That(Pendulum(vec{11,-16,-18,13,-11,-12,3,18}), Equals(vec{13,3,-12,-18,-16,-11,11,18}));
                    Assert::That(Pendulum(vec{7,-5,-20,15,2,10,18,4,-10}), Equals(vec{18,10,4,-5,-20,-10,2,7,15}));
                      Assert::That(Pendulum(vec{-6,1,2,12,19,12,19,-10,13,1}), Equals(vec{19,12,2,1,-10,-6,1,12,13,19}));
    }
};

int main(int argc, const char *argv[])
{
  TestRunner::RunAllTests();
    return 0;
}