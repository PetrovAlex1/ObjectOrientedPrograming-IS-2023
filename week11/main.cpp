// #pragma once
#include "headers/Car.h"
#include "headers/Truck.h"
#include "headers/VehicleFactory.h"
#include <stdexcept>
#include <iostream>

// Vehicle *createVehicle(const std::string &key);

int main(int argc, char const *argv[])
{
  std::string input;

  std::cin >> input;

  Vehicle *vehicle = VehicleFactory::getFactory().createVehicle(input, std::cin);

  vehicle->startEngine();

  // Car car(250, 69, 4, 4);

  // std::string input;

  // while (true)
  // {
  //   std::cin >> input;

  //   Vehicle *vehicle = createVehicle(input);

  //   vehicle->startEngine();
  //   delete vehicle;
  // }
  return 0;
}

// Vehicle *createVehicle(const std::string &key)
// {
//   if (key == "car")
//   {
//     return new Car();
//   }
//   else if (key == "truck")
//   {
//     return new Truck();
//   }

//   throw std::invalid_argument("Wrong key");
// }
