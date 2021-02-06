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
    std::cout << "Enter a new number between 0 - 4" << std::endl;
  }
  else
  {
    brand_ = bike_details::bike_brand(kind_of_bike);
  }
}

// std::string Motorcycle::getDirection()
// {
//   return curr_direction_;
// }

// std::string Motorcycle::getBikeType()
// {
//   return brand_;
// }

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

void Motorcycle::turn(float degrees)
{
  //update current_direction_
  if (degrees < 0)
  {
    curr_direction_ = degrees + 360;
  }
  else
  {
    curr_direction_ = degrees;
  }

  //print out the directions depending on curr_direction_
  if (curr_direction_ == 90)
  {
    std::cout << "North" << std::endl;
  }
  else if (curr_direction_ == 0)
  {
    std::cout << "East" << std::endl;
  }
  else if (curr_direction_ == 180)
  {
    std::cout << "West" << std::endl;
  }
  else if (curr_direction_ == 270)
  {
    std::cout << "South" << std::endl;
  }
  else if ((curr_direction_ > 0) && (curr_direction_ < 90))
  {
    std::cout << "Northeast" << std::endl;
  }
  else if (curr_direction_ > 270)
  {
    std::cout << "Southeast" << std::endl;
  }
  else if ((curr_direction_ > 180) && (curr_direction_ < 270))
  {
    std::cout << "Southwest" << std::endl;
  }
  else
  {
    std::cout << "Northwest" << std::endl;
  }
}

void Motorcycle::updateSpeed()
{
  //USE THE FOLLOWING FORMULA: [ (acceleration) / 8 ] + [ (brand) * 17.64 ]

  curr_speed_ = (curr_acceleration_ / 8) + (brand_ * 17.64);
}

int main()
{
  Motorcycle test;
  test.turn(91); //northwest

  return 0;
}
