/*
 Name: Shi Tao Luo
 Date: Feb 8, 2021
 Program: Project 0
 */
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
  //edge case: kind_of_bike is less than 0 and greater than 3
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

std::string Motorcycle::getDirection()
{
  //print out the directions depending on curr_direction_
  if (curr_direction_ == 90)
  {
    return "North";
  }
  else if (curr_direction_ == 0)
  {
    return "East";
  }
  else if (curr_direction_ == 180)
  {
    return "West";
  }
  else if (curr_direction_ == 270)
  {
    return "South";
  }
  else if ((curr_direction_ > 0) && (curr_direction_ < 90))
  {
    return "Northeast";
  }
  else if ((curr_direction_ > 270) && (curr_direction_ < 360))
  {
    return "Southeast";
  }
  else if ((curr_direction_ > 180) && (curr_direction_ < 270))
  {
    return "Southwest";
  }
  else if ((curr_direction_ > 90) && (curr_direction_ < 180))
  {
    return "Northwest";
  }
  //Return error: out of bound
  else
  {
    return "Error: Out of Bound";
  }
}

//bike_brands
std::string Motorcycle::getBikeType()
{
  if (brand_ == bike_details::bike_brand(0))
  {
    return "YAMAHA";
  }
  else if (brand_ == bike_details::bike_brand(1))
  {
    return "DUCATI";
  }
  else if (brand_ == bike_details::bike_brand(2))
  {
    return "HARLEY_DAVIDSON";
  }
  else if (brand_ == bike_details::bike_brand(3))
  {
    return "KAWASAKI";
  }
  else
  {
    return "Error: No Bike Type";
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
  //Increment acceleration
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
  //Decrement acceleration
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

//distance traveled during duration
int distance = 0;
//calculate the total distance traveled
float Motorcycle::ride(float duration)
{
  //edge case: negative duration
  if (duration < 0)
  {
    duration = 0;
  }
  //calculate distance travel during duration
  distance = (duration * curr_speed_);
  distance_traveled_ += distance;

  return distance;
}

//error?
//change direction
void Motorcycle::turn(float degrees)
{
  //edgecase: degrees greater than 360 degrees, subtract until less than 360
  while (degrees >= 360)
  {
    degrees -= 360;
  }

  //edgecase: degrees less than -360, add until less than -360
  while (degrees <= -360)
  {
    degrees -= -360;
  }

  // negative degrees subtract
  if (degrees < 0)
  {
    curr_direction_ += degrees;
    while (curr_direction_ < 0)
    {
      curr_direction_ -= -360;
    }
  }
  else
  {
    curr_direction_ += degrees;

    while (curr_direction_ > 360)
    {
      curr_direction_ -= 360;
    }
  }
}
