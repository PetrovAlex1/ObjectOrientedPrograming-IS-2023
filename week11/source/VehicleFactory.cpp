#include "../headers/VehicleFactory.h"

const VehicleCreator *VehicleFactory::getCreator(const std::string &key) const
{
  for (size_t i = 0; i < creators.size(); i++)
  {
    if (creators[i]->getKey() == key)
    {
      return creators[i];
    }
  }

  return nullptr;
}

VehicleFactory &VehicleFactory::getFactory()
{
  static VehicleFactory factory;
  return factory;
}

void VehicleFactory::registerVehicleCreator(const VehicleCreator *creator)
{
  creators.push_back(creator);
}

Vehicle *VehicleFactory::createVehicle(const std::string &key, std::istream &in)
{
  const VehicleCreator *creator = this->getCreator(key);
  return creator->createVehicle(in);
}