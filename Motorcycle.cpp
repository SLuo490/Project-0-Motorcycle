#include <iostream>
#include "Motorcycle.hpp"

//default constructor
Motorcycle::Motorcycle()
{
  curr_speed_ = 0;
  curr_acceleration_ = bike_details::NONE;
  curr_direction_ = 0;
  distance_traveled_ = 0;
  brand_ = bike_details::bike_brand(rand() % 4);
}

//parameterized constructor
Motorcycle::Motorcycle(int kind_of_bike)
{
  if ((kind_of_bike < 0) && (kind_of_bike > 4))
  {
    std::cout << "Enter a new number from 0 - 4" << std::endl;
  }
  else
  {
    brand_ = bike_details::bike_brand(kind_of_bike);
  }
}

std::string Motorcycle::getDirection()
{
  return curr_direction_; //?
}

std::string Motorcycle::getBikeType()
{
  return brand_;
}

float Motorcycle::getSpeed()
{
  return curr_speed_;
}

float Motorcycle::getDistanceTraveled()
{
  return distance_traveled_;
}

int Motorcycle::getIntensity()
{
  return curr_acceleration_;
}

int main()
{
  Motorcycle test;

  return 0;
}