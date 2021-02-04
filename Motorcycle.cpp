#include <iostream>
#include "Motorcycle.hpp"

using namespace std;

Motorcycle::Motorcycle()
{
  curr_speed_ = 0;
  curr_direction_ = 0;
  distance_traveled_ = 0;
}

Motorcycle::Motorcycle(int kind_of_bike)
{
}

int main()
{
  Motorcycle test(4);

  return 0;
}