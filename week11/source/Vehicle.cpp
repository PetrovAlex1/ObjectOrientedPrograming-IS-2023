#include "../headers/Vehicle.h"
#include "../headers/VehicleFactory.h"

Vehicle::Vehicle(int hp, int top_speed)
{
  this->hp = hp;
  this->top_speed = top_speed;
}

VehicleCreator::VehicleCreator(const std::string &key)
{
  this->key = key;
  VehicleFactory::getFactory().registerVehicleCreator(this);
}

const std::string &VehicleCreator::getKey() const
{
  return key;
}
