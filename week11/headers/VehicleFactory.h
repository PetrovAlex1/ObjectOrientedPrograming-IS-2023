#pragma once
#include <vector>
#include "Vehicle.h"

class VehicleFactory
{
private:
  std::vector<const VehicleCreator *> creators;

private:
  const VehicleCreator *getCreator(const std::string &key) const;

private:
  VehicleFactory() = default;
  ~VehicleFactory() = default;

public:
  VehicleFactory(const VehicleFactory &) = delete;
  VehicleFactory &operator=(const VehicleFactory &) = delete;

public:
  static VehicleFactory &getFactory();
  void registerVehicleCreator(const VehicleCreator *creator);
  Vehicle *createVehicle(const std::string &key, std::istream &in);
};
