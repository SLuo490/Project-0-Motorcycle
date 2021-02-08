#include <iostream>
#include "Motorcycle.hpp"

//default constructor
Motorcycle::Motorcycle()
{
  brand_ = bike_details::bike_brand(rand() % 4);
  curr_speed_ = 0;
  curr_acceleration_ = bike_details::NONE;
  curr_direction_ = 0;
  distance_traveled_ = 0;
}

//parameterized constructor
Motorcycle::Motorcycle(int kind_of_bike)
{
  if ((kind_of_bike < 0) || (kind_of_bike > 3))
  {
    throw std::runtime_error("Error: Enter a bike type number between 0 and 3");
  }
  else
  {
    brand_ = bike_details::bike_brand(kind_of_bike);
  }
  curr_speed_ = 0;
  curr_acceleration_ = bike_details::NONE;
  curr_direction_ = 0;
  distance_traveled_ = 0;
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

//get speed
float Motorcycle::getSpeed()
{
  return curr_speed_;
}

//get total distance travled
float Motorcycle::getDistanceTraveled()
{
  return distance_traveled_;
}

//get intensity
int Motorcycle::getIntensity()
{
  return curr_acceleration_;
}

//change direction
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

//update the speed
void Motorcycle::updateSpeed()
{
  //USE THE FOLLOWING FORMULA: [ (acceleration) / 8 ] + [ (brand) * 17.64 ]

  curr_speed_ = (curr_acceleration_ / 8) + (brand_ * 17.64);
}

/**
    if the current acceleration is not HIGH increase it by one level and call updateSpeed()
*/
void Motorcycle::accelerate()
{
  if (curr_acceleration_ == bike_details::NONE)
  {
    curr_acceleration_ = bike_details::LOW;
    updateSpeed();
  }
  else if (curr_acceleration_ == bike_details::LOW)
  {
    curr_acceleration_ = bike_details::MEDIUM;
    updateSpeed();
  }
  else if (curr_acceleration_ == bike_details::MEDIUM)
  {
    curr_acceleration_ = bike_details::HIGH;
    updateSpeed();
  }
}

/**
    if the current acceleration is not NONE decrease it by one level and call updateSpeed()
*/
void Motorcycle::brake()
{
  if (curr_acceleration_ == bike_details::LOW)
  {
    curr_acceleration_ = bike_details::NONE;
    updateSpeed();
  }
  else if (curr_acceleration_ == bike_details::MEDIUM)
  {
    curr_acceleration_ = bike_details::LOW;
    updateSpeed();
  }
  else if (curr_acceleration_ == bike_details::HIGH)
  {
    curr_acceleration_ = bike_details::MEDIUM;
    updateSpeed();
  }
}

//calculate the total distance traveled
float Motorcycle::ride(float duration)
{
  // multiply duration and speed to find distance traveled
  distance_traveled_ = duration * curr_speed_;

  return distance_traveled_;
}

int main()
{
  //default constructor
  Motorcycle test;

  //bike type
  std::cout << "Random Bike Type: " << test.getBikeType() << std::endl;

  //This catches the edge cases: less than 0 and greater than 3
  try
  {
    Motorcycle test2(0);
    std::cout << "Assigned Bike Type: " << test2.getBikeType() << std::endl;
  }
  catch (std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  //Test East
  test.turn(0);

  //Get current direction
  std::cout << "Current Direction: " << test.getDirection() << std::endl;

  return 0;
}
