#pragma once
#include <string>

class Vehicle
{
protected:
  int hp = 0;
  int top_speed = 0;

public:
  Vehicle() = default;
  Vehicle(int hp, int top_speed);
  virtual ~Vehicle() = default;

  virtual void startEngine() const = 0;
  virtual void stopEngine() const = 0;
};

class VehicleCreator
{
private:
  std::string key; // "car"

public:
  explicit VehicleCreator(const std::string &key);
  virtual ~VehicleCreator() = default;
  VehicleCreator(const VehicleCreator &) = delete;
  VehicleCreator &operator=(const VehicleCreator &) = delete;

  const std::string &getKey() const;
  virtual Vehicle *createVehicle(std::istream &in) const = 0;
};
