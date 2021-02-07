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

//Direction
std::string North = "North";
std::string East = "East";
std::string West = "West";
std::string South = "South";
std::string Northeast = "Northeast";
std::string Southwest = "Southwest";
std::string Southeast = "Southeast";
std::string Northwest = "Northwest";

std::string Motorcycle::getDirection()
{
  //print out the directions depending on curr_direction_
  if (curr_direction_ == 90)
  {
    return North;
  }
  else if (curr_direction_ == 0)
  {
    return East;
  }
  else if (curr_direction_ == 180)
  {
    return West;
  }
  else if (curr_direction_ == 270)
  {
    return South;
  }
  else if ((curr_direction_ > 0) && (curr_direction_ < 90))
  {
    return Northeast;
  }
  else if (curr_direction_ > 270)
  {
    return Southeast;
  }
  else if ((curr_direction_ > 180) && (curr_direction_ < 270))
  {
    return Southwest;
  }
  else
  {
    return Northwest;
  }
}

//bike_brands
std::string YAMAHA = "YAMAHA";
std::string DUCATI = "DUCATI";
std::string HARLEY_DAVIDSON = "HARLEY_DAVIDSON";
std::string KAWASAKI = "KAWASAKI";

std::string Motorcycle::getBikeType()
{
  if (brand_ == 0)
  {
    return YAMAHA;
  }
  else if (brand_ == 1)
  {
    return DUCATI;
  }
  else if (brand_ == 2)
  {
    return HARLEY_DAVIDSON;
  }
  else if (brand_ == 3)
  {
    return KAWASAKI;
  }
  else
  {
    return 0;
  }
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
}

void Motorcycle::updateSpeed()
{
  //USE THE FOLLOWING FORMULA: [ (acceleration) / 8 ] + [ (brand) * 17.64 ]

  curr_speed_ = (curr_acceleration_ / 8) + (brand_ * 17.64);
}

// void Motorcycle::set_Direction (int direction) {
//   curr_direction_ = direction;
// }

// void

int main()
{
  Motorcycle test;
  test.turn(0); //northwest
  //current direction
  std::cout << "Current Direction: " << test.getDirection() << std::endl;

  //bike type
  std::cout << "Current Bike Type: " << test.getBikeType() << std::endl;

  return 0;
}
