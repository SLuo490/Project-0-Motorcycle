#include <iostream>
#include "Motorcycle.hpp"

using namespace std;

Motorcycle::Motorcycle()
{
  curr_speed_ = 0;
  curr_acceleration_ = bike_details::NONE;
  curr_direction_ = 0;
  distance_traveled_ = 0;
  brand_ = bike_details::bike_brand(rand() % 4);
}

Motorcycle::Motorcycle(int kind_of_bike)
{
  if ((kind_of_bike < 0) && (kind_of_bike > 0))
  {
    cout << "Enter a new number from 0 - 4" << endl;
  }
  else
  {
    brand_ = bike_details::bike_brand(kind_of_bike);
  }
}

int main()
{
  Motorcycle test;

  return 0;
}