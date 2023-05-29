#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
  int doors = 1;
  int seats = 1;

public:
  Car() = default;
  Car(int hp, int top_speed, int doors, int seats);
  // ~Car();

  virtual void startEngine() const override;
  virtual void stopEngine() const override;
};

class CarCreator : public VehicleCreator
{
public:
  CarCreator();
  Vehicle *createVehicle(std::istream &in) const override;
};