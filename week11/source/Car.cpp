#include "../headers/Car.h"
#include <iostream>

Car::Car(int hp, int top_speed, int doors, int seats) : Vehicle(hp, top_speed)
{
  this->doors = doors;
  this->seats = seats;
}

void Car::startEngine() const
{
  std::cout << "Car starting engine" << std::endl;
}

void Car::stopEngine() const
{
  std::cout << "Car stopping engine" << std::endl;
}

CarCreator::CarCreator() : VehicleCreator("car") {}

Vehicle *CarCreator::createVehicle(std::istream &in) const
{
  int hp;
  int top_speed;
  int doors;
  int seats;

  in >> hp;
  in >> top_speed;
  in >> doors;
  in >> seats;

  return new Car(hp, top_speed, doors, seats);
}

static CarCreator __;
