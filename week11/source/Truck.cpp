#include "../headers/Truck.h"
#include <iostream>

Truck::Truck(int hp, int top_speed, int max_load) : Vehicle(hp, top_speed)
{
  this->max_load = max_load;
}

void Truck::startEngine() const
{
  std::cout << "Truck starting engine" << std::endl;
}

void Truck::stopEngine() const
{
  std::cout << "Truck stopping engine" << std::endl;
}

TruckCreator::TruckCreator() : VehicleCreator("truck") {}

Vehicle *TruckCreator::createVehicle(std::istream &in) const
{
  int hp;
  int top_speed;
  int max_load;

  in >> hp;
  in >> top_speed;
  in >> max_load;

  return new Truck(hp, top_speed, max_load);
}

static TruckCreator __;