/**
 Name: Shi Tao Luo
 Date: Deb 8, 2021
 Program: Project 0
 */

#include <iostream>
#include "Motorcycle.hpp"

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

  test.turn(0);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(45);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;
  test.turn(-90);
  std::cout << "Current Direction: " << test.getDirection() << std::endl;

  // test.ride(0);
  // std::cout << "Total Distance Traveled: " << test.getDistanceTraveled() << std::endl;
  // test.ride(9001);
  // std::cout << "Total Distance Traveled: " << test.getDistanceTraveled() << std::endl;
  // test.ride(1);
  // std::cout << "Total Distance Traveled: " << test.getDistanceTraveled() << std::endl;

  // std::cout << "Speed: " << test.getSpeed() << std::endl;

  return 0;
}