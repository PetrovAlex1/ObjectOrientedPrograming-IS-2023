#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
  int max_load = 0;

public:
  Truck() = default;
  Truck(int hp, int top_speed, int max_load);

  virtual void startEngine() const override;
  virtual void stopEngine() const override;
};

class TruckCreator : public VehicleCreator
{
public:
  TruckCreator();
  Vehicle *createVehicle(std::istream &in) const override;
};