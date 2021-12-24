// https://www.codewars.com/kata/57f781872e3d8ca2a000007e/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <algorithm>
std::vector<int> maps(std::vector<int> values) {
    std::for_each(values.begin(), values.end(), [](int &a) {a*=2;});
  return values;
}

#include <random> 

int random_int();
std::vector<int> make_random_vector(size_t size);

Describe(the_maps_function)
{    
    // It(should_return_an_empty_vector_on_an_empty_input)
    // {
    //     const std::vector<int> empty;
    //     Assert::That(maps(empty), Equals(empty));
    // }
    // It(should_return_a_vector_of_the_same_length)
    // {      
    //     for(size_t i = 1; i < 145; i += 13){
    //       const auto input = make_random_vector(i);
    //       Assert::That(maps(input), HasLength(i));        
    //     }
    // }
    It(should_return_a_vector_where_the_first_value_is_doubled)
    {
        for(size_t i = 1; i < 145; i += 13){
          const auto input = make_random_vector(i);
          Assert::That(maps(input)[0], Equals(input[0] * 2));
        }
    }
};

int random_int() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int> d(-2000,2000);
  
  return d(gen);
}

std::vector<int> make_random_vector(size_t size) {
  std::vector<int> vec(size);
  std::generate(vec.begin(), vec.end(), random_int);
  return vec;
}

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}